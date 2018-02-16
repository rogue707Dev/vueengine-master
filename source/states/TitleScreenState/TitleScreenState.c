/* VUEngine - Virtual Utopia Engine <http://vuengine.planetvb.com/>
 * A universal game engine for the Nintendo Virtual Boy
 *
 * Copyright (C) 2007, 2018 by Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <chris@vr32.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <string.h>

#include <Game.h>
#include <Camera.h>
#include <Actor.h>
#include <MessageDispatcher.h>
#include <AnimatedEntity.h>
#include <I18n.h>
#include <Languages.h>
#include <TitleScreenState.h>
#include <VueMasterState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef TITLE_SCREEN_ST;


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void TitleScreenState_destructor(TitleScreenState this);
static void TitleScreenState_constructor(TitleScreenState this);
static void TitleScreenState_enter(TitleScreenState this, void* owner);
static void TitleScreenState_onFadeInComplete(TitleScreenState this, Object eventFirer);
static void TitleScreenState_onFadeOutComplete(TitleScreenState this, Object eventFirer);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(TitleScreenState, GameState);
__SINGLETON_DYNAMIC(TitleScreenState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

static void __attribute__ ((noinline)) TitleScreenState_constructor(TitleScreenState this)
{
	__CONSTRUCT_BASE(GameState);

	// init state
	this->animationPlaying = true;
	this->viewtualBoyEntity = NULL;
	this->viewtualBoyArrowsEntity = NULL;
}

static void TitleScreenState_destructor(TitleScreenState this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

static void TitleScreenState_enter(TitleScreenState this, void* owner __attribute__ ((unused)))
{
	// call base
	__CALL_BASE_METHOD(GameState, enter, this, owner);

	// disable user input
	Game_disableKeypad(Game_getInstance());

	// register input events to be caught
	KeypadManager_registerInput(KeypadManager_getInstance(), __KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);

	// load stage
	GameState_loadStage(__SAFE_CAST(GameState, this), (StageDefinition*)&TITLE_SCREEN_ST, NULL, true);

	// get entities
	this->viewtualBoyEntity = __SAFE_CAST(AnimatedEntity, Container_getChildByName(
		__SAFE_CAST(Container, Game_getStage(Game_getInstance())),
		"VB",
		false
	));
	this->viewtualBoyArrowsEntity = __SAFE_CAST(AnimatedEntity, Container_getChildByName(
		__SAFE_CAST(Container, Game_getStage(Game_getInstance())),
		"Arrows",
		false
	));

	// init state
	this->animationPlaying = true;

	// print reel title and credits
	const char* strReelTitle = I18n_getText(I18n_getInstance(), STR_REEL_TITLE);
	const char* strReelCredits = I18n_getText(I18n_getInstance(), STR_REEL_CREDITS);
	FontSize strReelTitleSize = Printing_getTextSize(Printing_getInstance(), strReelTitle, NULL);
	FontSize strReelCreditsSize = Printing_getTextSize(Printing_getInstance(), strReelCredits, NULL);
	Printing_setPalette(Printing_getInstance(), 3);
	Printing_text(Printing_getInstance(), strReelTitle, 2, 12, NULL);
	Printing_setPalette(Printing_getInstance(), 2);
	Printing_text(Printing_getInstance(), strReelCredits, 2, 13 + strReelTitleSize.y, NULL);

	// move "press start" according to height of reel title and credits
	Container pressStartEntity = Container_getChildByName(
		__SAFE_CAST(Container, Game_getStage(Game_getInstance())),
		"PrssStrt",
		false
	);
	Vector3D localPosition = {
		__PIXELS_TO_METERS(100),
		__PIXELS_TO_METERS(124 + ((strReelTitleSize.y  + strReelCreditsSize.y) << 3)),
		__PIXELS_TO_METERS(0),
	};
	Container_setLocalPosition(pressStartEntity, &localPosition);

	// start clocks to start animations
	GameState_startClocks(__SAFE_CAST(GameState, this));

	// start fade in effect
	Camera_startEffect(Camera_getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		(void (*)(Object, Object))TitleScreenState_onFadeInComplete, // callback function
		__SAFE_CAST(Object, this) // callback scope
	);
}

void TitleScreenState_resume(TitleScreenState this, void* owner)
{
	__CALL_BASE_METHOD(GameState, resume, this, owner);

	// init state
	this->animationPlaying = true;
	this->viewtualBoyEntity = NULL;
	this->viewtualBoyArrowsEntity = NULL;
}

void TitleScreenState_processUserInput(TitleScreenState this, UserInput userInput)
{
	if((userInput.pressedKey & ~K_PWR) || (userInput.holdKey & ~K_PWR))
	{
		if((userInput.pressedKey & K_A) || (userInput.pressedKey & K_STA))
		{
			// disable user input
			Game_disableKeypad(Game_getInstance());

			// start fade out effect
			Brightness brightness = (Brightness){0, 0, 0};
			Camera_startEffect(Camera_getInstance(),
				kFadeTo, // effect type
				0, // initial delay (in ms)
				&brightness, // target brightness
				0, // delay between fading steps (in ms)
				(void (*)(Object, Object))TitleScreenState_onFadeOutComplete, // callback function
				__SAFE_CAST(Object, this) // callback scope
			);
		}
		else if(
			(userInput.pressedKey & K_LL) || ((userInput.holdKey & K_LL) && (userInput.holdKeyDuration > 12)) ||
			(userInput.pressedKey & K_RR) || ((userInput.holdKey & K_RR) && (userInput.holdKeyDuration > 12))
		)
		{
			// pause animation
			if(this->animationPlaying)
			{
				AnimatedEntity_pauseAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyEntity), true);
				AnimatedEntity_playAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyArrowsEntity), "Visible");
				this->animationPlaying = !this->animationPlaying;
			}

			// show next frame
			AnimatedEntity_nextFrame(this->viewtualBoyEntity);
		}
		else if(
			(userInput.pressedKey & K_LR) || ((userInput.holdKey & K_LR) && (userInput.holdKeyDuration > 12)) ||
			(userInput.pressedKey & K_RL) || ((userInput.holdKey & K_RL) && (userInput.holdKeyDuration > 12))
		)
		{
			// pause animation
			if(this->animationPlaying)
			{
				AnimatedEntity_pauseAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyEntity), true);
				AnimatedEntity_playAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyArrowsEntity), "Visible");
				this->animationPlaying = !this->animationPlaying;
			}

			// show previous frame
			AnimatedEntity_previousFrame(this->viewtualBoyEntity);
		}
		else if(userInput.pressedKey & K_SEL)
		{
			// pause/resume animation
			AnimatedEntity_pauseAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyEntity), this->animationPlaying);
			this->animationPlaying = !this->animationPlaying;
			if(this->animationPlaying)
			{
				AnimatedEntity_playAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyArrowsEntity), "Hidden");
			}
			else
			{
				AnimatedEntity_playAnimation(__SAFE_CAST(AnimatedEntity, this->viewtualBoyArrowsEntity), "Visible");
			}
		}
	}
}

static void TitleScreenState_onFadeInComplete(TitleScreenState this __attribute__ ((unused)), Object eventFirer __attribute__ ((unused)))
{
	ASSERT(this, "TitleScreenState::onFadeInComplete: null this");

	// enable user input
	Game_enableKeypad(Game_getInstance());

}

static void TitleScreenState_onFadeOutComplete(TitleScreenState this __attribute__ ((unused)), Object eventFirer __attribute__ ((unused)))
{
	ASSERT(this, "TitleScreenState::onFadeOutComplete: null this");

	Game_changeState(Game_getInstance(), __SAFE_CAST(GameState, VueMasterState_getInstance()));
}
