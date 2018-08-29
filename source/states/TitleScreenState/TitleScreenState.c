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
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void TitleScreenState::constructor()
{
	Base::constructor();

	// init state
	this->animationPlaying = true;
	this->viewtualBoyEntity = NULL;
	this->viewtualBoyArrowsEntity = NULL;
}

void TitleScreenState::destructor()
{
	// destroy base
	Base::destructor();
}

void TitleScreenState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// disable user input
	Game::disableKeypad(Game::getInstance());

	// register input events to be caught
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageDefinition*)&TITLE_SCREEN_ST, NULL, true);

	// get entities
	this->viewtualBoyEntity = AnimatedEntity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"VB",
		false
	));
	this->viewtualBoyArrowsEntity = AnimatedEntity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"Arrows",
		false
	));

	// init state
	this->animationPlaying = true;

	// print reel title and credits
	const char* strReelTitle = I18n::getText(I18n::getInstance(), STR_REEL_TITLE);
	const char* strReelCredits = I18n::getText(I18n::getInstance(), STR_REEL_CREDITS);
	FontSize strReelTitleSize = Printing::getTextSize(Printing::getInstance(), strReelTitle, NULL);
	FontSize strReelCreditsSize = Printing::getTextSize(Printing::getInstance(), strReelCredits, NULL);
	Printing::setPalette(Printing::getInstance(), 3);
	Printing::text(Printing::getInstance(), strReelTitle, 2, 12, NULL);
	Printing::setPalette(Printing::getInstance(), 2);
	Printing::text(Printing::getInstance(), strReelCredits, 2, 13 + strReelTitleSize.y, NULL);

	// move "press start" according to height of reel title and credits
	Container pressStartEntity = Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"PrssStrt",
		false
	);
	Vector3D localPosition = {
		__PIXELS_TO_METERS(100),
		__PIXELS_TO_METERS(124 + ((strReelTitleSize.y  + strReelCreditsSize.y) << 3)),
		__PIXELS_TO_METERS(0),
	};
	Container::setLocalPosition(pressStartEntity, &localPosition);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// start fade in effect
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		200, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		(void (*)(Object, Object))TitleScreenState::onFadeInComplete, // callback function
		Object::safeCast(this) // callback scope
	);
}

void TitleScreenState::resume(void* owner)
{
	Base::resume(this, owner);

	// init state
	this->animationPlaying = true;
	this->viewtualBoyEntity = NULL;
	this->viewtualBoyArrowsEntity = NULL;
}

void TitleScreenState::processUserInput(UserInput userInput)
{
	if((userInput.pressedKey & K_A) || (userInput.pressedKey & K_STA))
	{
		// disable user input
		Game::disableKeypad(Game::getInstance());

		// start fade out effect
		Brightness brightness = (Brightness){0, 0, 0};
		Camera::startEffect(Camera::getInstance(),
			kFadeTo, // effect type
			0, // initial delay (in ms)
			&brightness, // target brightness
			0, // delay between fading steps (in ms)
			(void (*)(Object, Object))TitleScreenState::onFadeOutComplete, // callback function
			Object::safeCast(this) // callback scope
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
			AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->viewtualBoyEntity), true);
			AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->viewtualBoyArrowsEntity), "Visible");
			this->animationPlaying = !this->animationPlaying;
		}

		// show next frame
		AnimatedEntity::nextFrame(this->viewtualBoyEntity);
	}
	else if(
		(userInput.pressedKey & K_LR) || ((userInput.holdKey & K_LR) && (userInput.holdKeyDuration > 12)) ||
		(userInput.pressedKey & K_RL) || ((userInput.holdKey & K_RL) && (userInput.holdKeyDuration > 12))
	)
	{
		// pause animation
		if(this->animationPlaying)
		{
			AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->viewtualBoyEntity), true);
			AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->viewtualBoyArrowsEntity), "Visible");
			this->animationPlaying = !this->animationPlaying;
		}

		// show previous frame
		AnimatedEntity::previousFrame(this->viewtualBoyEntity);
	}
	else if(userInput.pressedKey & K_SEL)
	{
		// pause/resume animation
		AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->viewtualBoyEntity), this->animationPlaying);
		this->animationPlaying = !this->animationPlaying;
		if(this->animationPlaying)
		{
			AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->viewtualBoyArrowsEntity), "Hidden");
		}
		else
		{
			AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->viewtualBoyArrowsEntity), "Visible");
		}
	}
}

void TitleScreenState::onFadeInComplete(Object eventFirer __attribute__ ((unused)))
{
	// enable user input
	Game::enableKeypad(Game::getInstance());

}

void TitleScreenState::onFadeOutComplete(Object eventFirer __attribute__ ((unused)))
{
	Game::changeState(Game::getInstance(), GameState::safeCast(VueMasterState::getInstance()));
}
