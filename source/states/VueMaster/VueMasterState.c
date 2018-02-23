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
#include <Printing.h>
#include <I18n.h>
#include <VueMasterState.h>
#include <KeypadManager.h>
#include <MessageDispatcher.h>
#include <TitleScreenState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMDef VUE_MASTER_ST;

extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_1_IM_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_2_IM_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_3_IM_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_4_IM_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_5_IM_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_6_IM_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_7_IM_SPRITES;

const SpriteDefinition* VUE_MASTER_SPRITES[__NUMBER_OF_VIEWER_IMAGES] =
{
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_1_IM_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_2_IM_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_3_IM_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_4_IM_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_5_IM_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_6_IM_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_7_IM_SPRITES,
};


//---------------------------------------------------------------------------------------------------------
// 												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

static void VueMasterState_destructor(VueMasterState this);
static void VueMasterState_constructor(VueMasterState this);
static void VueMasterState_enter(VueMasterState this, void* owner);
static void VueMasterState_exit(VueMasterState this, void* owner);
static void VueMasterState_printImageNumber(VueMasterState this);
static void VueMasterState_onFadeInComplete(VueMasterState this, Object eventFirer);
static void VueMasterState_onFadeOutComplete(VueMasterState this, Object eventFirer);


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

__CLASS_DEFINITION(VueMasterState, GameState);
__SINGLETON_DYNAMIC(VueMasterState);


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

static void __attribute__ ((noinline)) VueMasterState_constructor(VueMasterState this)
{
	__CONSTRUCT_BASE(GameState);

	// init members
	this->currentImage = 0;
	this->showNumber = false;
	this->imageEntity = NULL;
}

static void VueMasterState_destructor(VueMasterState this)
{
	// destroy base
	__SINGLETON_DESTROY;
}

static void VueMasterState_enter(VueMasterState this, void* owner __attribute__ ((unused)))
{
	// call base
	GameState_enter(__SAFE_CAST(GameState, this), owner);

	// disable user input
    Game_disableKeypad(Game_getInstance());

	// load stage
	GameState_loadStage(__SAFE_CAST(GameState, this), (StageDefinition*)&VUE_MASTER_ST, NULL, true);

	// init members
	this->currentImage = 0;
	this->showNumber = false;

	// get image entity from stage
	this->imageEntity = __SAFE_CAST(Entity, Container_getChildByName(
		__SAFE_CAST(Container, Game_getStage(Game_getInstance())),
		"ImageEntity",
		false
	));

	// print image number
	Printing_setPalette(Printing_getInstance(), 1);
	VueMasterState_printImageNumber(this);

	// start fade in effect
	Camera_startEffect(Camera_getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		(void (*)(Object, Object))VueMasterState_onFadeInComplete, // callback function
		__SAFE_CAST(Object, this) // callback scope
	);
}

static void VueMasterState_exit(VueMasterState this, void* owner)
{
	// call base
	GameState_exit(__SAFE_CAST(GameState, this), owner);
}

static void VueMasterState_printImageNumber(VueMasterState this)
{
	if (this->showNumber)
	{
		Printing_text(Printing_getInstance(), "./.", 45, 0, "NumberFont");
		Printing_int(Printing_getInstance(), this->currentImage + 1, 45, 0, "NumberFont");
		Printing_int(Printing_getInstance(), __NUMBER_OF_VIEWER_IMAGES, 47, 0, "NumberFont");
	}
	else
	{
		Printing_text(Printing_getInstance(), "...", 45, 0, "NumberFont");
	}
}

static void VueMasterState_switchImage(VueMasterState this)
{
	// hide screen
	Camera_startEffect(Camera_getInstance(), kHide);

	// replace sprites
	Entity_releaseSprites(this->imageEntity);
	Entity_addSprites(this->imageEntity, (const SpriteDefinition**)VUE_MASTER_SPRITES[this->currentImage]);

	// print image number
	VueMasterState_printImageNumber(this);

	// delayed fade in to hide graphical corruption that occurs during rewriting of chars and maps in memory
	Camera_startEffect(Camera_getInstance(),
		kFadeTo, // effect type
		75, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		NULL, // callback function
		NULL // callback scope
	);
}

void VueMasterState_processUserInput(VueMasterState this, UserInput userInput)
{
	if(userInput.pressedKey)
	{
		if(K_LL & userInput.pressedKey || K_RL & userInput.pressedKey)
		{
			this->currentImage = (this->currentImage > 0)
				? this->currentImage - 1
				: (__NUMBER_OF_VIEWER_IMAGES - 1);
			VueMasterState_switchImage(this);
			return;
		}
		else if(K_LR & userInput.pressedKey || K_RR & userInput.pressedKey)
		{
			this->currentImage = (this->currentImage < (__NUMBER_OF_VIEWER_IMAGES - 1))
				? this->currentImage + 1
				: 0;
			VueMasterState_switchImage(this);
			return;
		}
		else if(K_B & userInput.pressedKey)
		{
			// start fade out effect
			Brightness brightness = (Brightness){0, 0, 0};
			Camera_startEffect(Camera_getInstance(),
				kFadeTo, // effect type
				0, // initial delay (in ms)
				&brightness, // target brightness
				0, // delay between fading steps (in ms)
				(void (*)(Object, Object))VueMasterState_onFadeOutComplete, // callback function
				__SAFE_CAST(Object, this) // callback scope
			);
			return;
		}
		else if(K_SEL & userInput.pressedKey)
		{
			this->showNumber = !this->showNumber;
			VueMasterState_printImageNumber(this);
		}
	}
}

// handle event
static void VueMasterState_onFadeInComplete(VueMasterState this __attribute__ ((unused)), Object eventFirer __attribute__ ((unused)))
{
	ASSERT(this, "VueMasterState::onFadeInComplete: null this");

	// enable user input
	Game_enableKeypad(Game_getInstance());

}

// handle event
static void VueMasterState_onFadeOutComplete(VueMasterState this __attribute__ ((unused)), Object eventFirer __attribute__ ((unused)))
{
	ASSERT(this, "VueMasterState::onFadeOutComplete: null this");

	Game_changeState(Game_getInstance(), __SAFE_CAST(GameState, TitleScreenState_getInstance()));
}
