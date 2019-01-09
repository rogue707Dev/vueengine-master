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
#include <VIPManager.h>
#include <I18n.h>
#include <VueMasterState.h>
#include <KeypadManager.h>
#include <MessageDispatcher.h>
#include <TitleScreenState.h>
#include <VueMasterImageSpec.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec VUE_MASTER_ST;


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
	this->animationPlaying = false;
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
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&VUE_MASTER_ST, NULL, true);

	// init members
	this->currentImage = 0;
	this->showNumber = false;

	// get image entity from stage
	this->imageEntity = AnimatedEntity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"ImageEntity",
		false
	));

	// print image number
	Printing::setPalette(Printing::getInstance(), 3);
	VueMasterState::printImageNumber(this);

	// set initial image's color config
	VueMasterImageROMSpec* vueMasterImageSpec = VUE_MASTER_ENTITIES[this->currentImage];
	ColorConfig colorConfig = vueMasterImageSpec->colorConfig;
	VueMasterState::setColorConfig(this, colorConfig);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// start fade in effect
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		&colorConfig.brightness, // target brightness
		0, // delay between fading steps (in ms)
		(EventListener)VueMasterState::onFadeInComplete, // callback function
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
#if(__NUMBER_OF_VIEWER_IMAGES < 10)
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
#else
	if (this->showNumber)
	{
		Printing::text(Printing::getInstance(), "00/..", 43, 0, "NumberFont");
		Printing::int(Printing::getInstance(), this->currentImage + 1, (this->currentImage>8 ? 43 : 44), 0, "NumberFont");
		Printing::int(Printing::getInstance(), __NUMBER_OF_VIEWER_IMAGES, 46, 0, "NumberFont");
	}
	else
	{
		Printing::text(Printing::getInstance(), ".....", 43, 0, "NumberFont");
	}
#endif
}

void VueMasterState::switchImage()
{
	// Prevent more user inputs before the image has been switched
	Game::disableKeypad(Game::getInstance());	

	// hide screen
	Camera::startEffect(Camera::getInstance(), kHide);

	if (__NUMBER_OF_VIEWER_IMAGES <= this->currentImage)
	{
		this->currentImage = __NUMBER_OF_VIEWER_IMAGES;
	}

	if(0 > this->currentImage)
	{
		this->currentImage = 0;
	}

	// replace sprites
	Entity::releaseSprites(Entity::safeCast(this->imageEntity), true);
	VueMasterImageROMSpec* vueMasterImageSpec = VUE_MASTER_ENTITIES[this->currentImage];
	AnimatedEntityROMSpec* animatedEntitySpec = (AnimatedEntitySpec*)&(vueMasterImageSpec->animatedEntitySpec);
	Entity::addSprites(Entity::safeCast(this->imageEntity), animatedEntitySpec->entitySpec.spriteSpecs);

	// replace animation spec and play animation
	AnimatedEntity::setAnimationDescription(this->imageEntity, animatedEntitySpec->animationDescription);
	AnimatedEntity::playAnimation(this->imageEntity, animatedEntitySpec->initialAnimation);
	this->animationPlaying = true;

	// set color config
	ColorConfig colorConfig = vueMasterImageSpec->colorConfig;
	VueMasterState::setColorConfig(this, colorConfig);

	// print image number
	VueMasterState::printImageNumber(this);

	// delayed fade in to hide graphical corruption that occurs during rewriting of chars and maps in memory
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		100, // initial delay (in ms)
		&colorConfig.brightness, // target brightness
		0, // delay between fading steps (in ms)
		(EventListener)VueMasterState::onSwitchImageFadeIn, // callback function
		Object::safeCast(this) // callback scope
	);
}

void VueMasterState::onSwitchImageFadeIn(Object eventFirer __attribute((unused)))
{
	Game::enableKeypad(Game::getInstance());	
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
			// Prevent more user inputs 
			Game::disableKeypad(Game::getInstance());	

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
		else if(
			(userInput.pressedKey & K_LU) || ((userInput.holdKey & K_LU) && (userInput.holdKeyDuration > 12)) ||
			(userInput.pressedKey & K_RU) || ((userInput.holdKey & K_RU) && (userInput.holdKeyDuration > 12))
		)
		{
			// pause animation
			if(this->animationPlaying)
			{
				AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->imageEntity), true);
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Visible");
				this->animationPlaying = !this->animationPlaying;
			}

			// show next frame
			AnimatedEntity::nextFrame(AnimatedEntity::safeCast(this->imageEntity));
		}
		else if(
			(userInput.pressedKey & K_LD) || ((userInput.holdKey & K_LD) && (userInput.holdKeyDuration > 12)) ||
			(userInput.pressedKey & K_RD) || ((userInput.holdKey & K_RD) && (userInput.holdKeyDuration > 12))
		)
		{
			// pause animation
			if(this->animationPlaying)
			{
				AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->imageEntity), true);
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Visible");
				this->animationPlaying = !this->animationPlaying;
			}

			// show previous frame
			AnimatedEntity::previousFrame(AnimatedEntity::safeCast(this->imageEntity));
		}
		else if(userInput.pressedKey & K_STA)
		{
			// pause/resume animation
			AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->imageEntity), this->animationPlaying);
			this->animationPlaying = !this->animationPlaying;
			if(this->animationPlaying)
			{
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Hidden");
			}
			else
			{
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Visible");
			}
		}
	}
}

void VueMasterState::setColorConfig(ColorConfig colorConfig)
{
	// background color
	VIPManager::setBackgroundColor(VIPManager::getInstance(), colorConfig.backgroundColor);

	// brightness repeat
	BrightnessRepeatSpec* brightnessRepeat = colorConfig.brightnessRepeat;
	if(brightnessRepeat)
	{
		VIPManager::setupBrightnessRepeat(VIPManager::getInstance(), colorConfig.brightnessRepeat);
	}
}

// handle event
void VueMasterState::onFadeInComplete(Object eventFirer __attribute__ ((unused)))
{
	// enable user input
	Game::enableKeypad(Game::getInstance());
}

// handle event
void VueMasterState::onFadeOutComplete(Object eventFirer __attribute__ ((unused)))
{
	Game::changeState(Game::getInstance(), GameState::safeCast(TitleScreenState::getInstance()));
}
