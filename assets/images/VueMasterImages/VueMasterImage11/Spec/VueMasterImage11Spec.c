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

#include <VueMasterState.h>
#if(__NUMBER_OF_VIEWER_IMAGES >= 11)


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE VueMasterImage11LTiles[];
extern BYTE VueMasterImage11LMap[];
extern BYTE VueMasterImage11RTiles[];
extern BYTE VueMasterImage11RMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec VUE_MASTER_IMAGE_11_DEFAULT_ANIM =
{
	// number of frames of this animation function
	8,

	// frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7
	},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Default",
};

// an animation spec
AnimationDescriptionROMSpec VUE_MASTER_IMAGE_11_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&VUE_MASTER_IMAGE_11_DEFAULT_ANIM,

		NULL,
	}
};

CharSetROMSpec VUE_MASTER_IMAGE_11_L_CH =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	272,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	VueMasterImage11LTiles,
};

TextureROMSpec VUE_MASTER_IMAGE_11_L_TX =
{
	// charset spec
	(CharSetSpec*)&VUE_MASTER_IMAGE_11_L_CH,

	// bgmap spec
	VueMasterImage11LMap,

	// cols (max 64)
	48,

	// rows (max 64)
	28,

	// padding for affine transformations
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	true,
};

BgmapSpriteROMSpec VUE_MASTER_IMAGE_11_L_SPRITE =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&VUE_MASTER_IMAGE_11_L_TX,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_LON,
};

CharSetROMSpec VUE_MASTER_IMAGE_11_R_CH =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	260,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE_OPTIMIZED,

	// char spec
	VueMasterImage11RTiles,
};

TextureROMSpec VUE_MASTER_IMAGE_11_R_TX =
{
	// charset spec
	(CharSetSpec*)&VUE_MASTER_IMAGE_11_R_CH,

	// bgmap spec
	VueMasterImage11RMap,

	// cols (max 64)
	48,

	// rows (max 64)
	28,

	// padding for affine transformations
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	true,
};

BgmapSpriteROMSpec VUE_MASTER_IMAGE_11_R_SPRITE =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&VUE_MASTER_IMAGE_11_R_TX,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_RON,
};

BgmapSpriteROMSpec* const VUE_MASTER_IMAGE_11_SPRITES[] =
{
	&VUE_MASTER_IMAGE_11_L_SPRITE,
	&VUE_MASTER_IMAGE_11_R_SPRITE,
	NULL
};

VueMasterImageROMSpec VUE_MASTER_IMAGE_11_EN =
{
	// animated entity spec
	{
		{
			// class allocator
			__TYPE(AnimatedEntity),

			// behaviors 
			NULL,

			// sprites
			(SpriteSpec**)VUE_MASTER_IMAGE_11_SPRITES,

			// collision shapes
			(ShapeSpec*)NULL,

			// size
			// if 0, width and height will be inferred from the first sprite's texture's size
			{0, 0, 0},

			// gameworld's character's type
			0,

			// physical specification
			(PhysicalSpecification*)NULL,
		},

		// pointer to the animation spec for the item
		(AnimationDescription*)&VUE_MASTER_IMAGE_11_ANIM,

		// initial animation
		"Default"
	},

	// colors config
	{
		// background color
		__COLOR_BLACK,

		// brightness
		// these values times the repeat values specified in the column table (max. 16) make the final
		// brightness values on the respective regions of the screen. maximum brightness is 128.
		{
			// dark red
			__BRIGHTNESS_DARK_RED,
			// medium red
			__BRIGHTNESS_MEDIUM_RED,
			// bright red
			__BRIGHTNESS_BRIGHT_RED,
		},

		// brightness repeat
		(BrightnessRepeatSpec*)NULL,
	},
};


#endif
