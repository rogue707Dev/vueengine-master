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

extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_1_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_2_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_3_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_4_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_5_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_6_SPRITES;
extern BgmapSpriteROMDef* const VUE_MASTER_IMAGE_7_SPRITES;

const SpriteDefinition* VUE_MASTER_SPRITES[__NUMBER_OF_VIEWER_IMAGES] =
{
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_1_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_2_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_3_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_4_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_5_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_6_SPRITES,
	(SpriteDefinition* const) &VUE_MASTER_IMAGE_7_SPRITES,
};


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void VueMasterState::constructor()
{
	Base::constructor();

	// init members
	this->currentImage = 0;
	this->showNumber = false;
	this->imageEntity = NULL;
}

void VueMasterState::destructor()
{
	// destroy base
	Base::destructor();
}

void VueMasterState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// disable user input
    Game::disableKeypad(Game::getInstance());

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageDefinition*)&VUE_MASTER_ST, NULL, true);

	// init members
	this->currentImage = 0;
	this->showNumber = false;

	// get image entity from stage
	this->imageEntity = Entity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"ImageEntity",
		false
	));

	// print image number
	Printing::setPalette(Printing::getInstance(), 1);
	VueMasterState::printImageNumber(this);

	// start fade in effect
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		(void (*)(Object, Object))VueMasterState::onFadeInComplete, // callback function
		Object::safeCast(this) // callback scope
	);
}

void VueMasterState::exit(void* owner)
{
	// call base
	Base::exit(this, owner);
}

void VueMasterState::printImageNumber()
{
	if (this->showNumber)
	{
		Printing::text(Printing::getInstance(), "./.", 45, 0, "NumberFont");
		Printing::int(Printing::getInstance(), this->currentImage + 1, 45, 0, "NumberFont");
		Printing::int(Printing::getInstance(), __NUMBER_OF_VIEWER_IMAGES, 47, 0, "NumberFont");
	}
	else
	{
		Printing::text(Printing::getInstance(), "...", 45, 0, "NumberFont");
	}
}

void VueMasterState::switchImage()
{
	// hide screen
	Camera::startEffect(Camera::getInstance(), kHide);

	// replace sprites
	Entity::releaseSprites(this->imageEntity);
	Entity::addSprites(this->imageEntity, (const SpriteDefinition**)VUE_MASTER_SPRITES[this->currentImage]);

	// print image number
	VueMasterState::printImageNumber(this);

	// delayed fade in to hide graphical corruption that occurs during rewriting of chars and maps in memory
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		75, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		NULL, // callback function
		NULL // callback scope
	);
}

void VueMasterState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey)
	{
		if(K_LL & userInput.pressedKey || K_RL & userInput.pressedKey)
		{
			this->currentImage = (this->currentImage > 0)
				? this->currentImage - 1
				: (__NUMBER_OF_VIEWER_IMAGES - 1);
			VueMasterState::switchImage(this);
			return;
		}
		else if(K_LR & userInput.pressedKey || K_RR & userInput.pressedKey)
		{
			this->currentImage = (this->currentImage < (__NUMBER_OF_VIEWER_IMAGES - 1))
				? this->currentImage + 1
				: 0;
			VueMasterState::switchImage(this);
			return;
		}
		else if(K_B & userInput.pressedKey)
		{
			// start fade out effect
			Brightness brightness = (Brightness){0, 0, 0};
			Camera::startEffect(Camera::getInstance(),
				kFadeTo, // effect type
				0, // initial delay (in ms)
				&brightness, // target brightness
				0, // delay between fading steps (in ms)
				(void (*)(Object, Object))VueMasterState::onFadeOutComplete, // callback function
				Object::safeCast(this) // callback scope
			);
			return;
		}
		else if(K_SEL & userInput.pressedKey)
		{
			this->showNumber = !this->showNumber;
			VueMasterState::printImageNumber(this);
		}
	}
}

// handle event
void VueMasterState::onFadeInComplete(Object eventFirer __attribute__ ((unused)))
{
	ASSERT(this, "VueMasterState::onFadeInComplete: null this");

	// enable user input
	Game::enableKeypad(Game::getInstance());
}

// handle event
void VueMasterState::onFadeOutComplete(Object eventFirer __attribute__ ((unused)))
{
	ASSERT(this, "VueMasterState::onFadeOutComplete: null this");

	Game::changeState(Game::getInstance(), GameState::safeCast(TitleScreenState::getInstance()));
}
