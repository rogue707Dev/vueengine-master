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

#ifndef VUE_MASTER_IMAGE_DEFINITION_H_
#define VUE_MASTER_IMAGE_DEFINITION_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <BgmapSprite.h>
#include <VueMasterState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

#if(__NUMBER_OF_VIEWER_IMAGES >= 1)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_1_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 2)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_2_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 3)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_3_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 4)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_4_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 5)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_5_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 6)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_6_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 7)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_7_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 8)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_8_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 9)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_9_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 10)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_10_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 11)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_11_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 12)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_12_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 13)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_13_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 14)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_14_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 15)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_15_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 16)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_16_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 17)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_17_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 18)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_18_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 19)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_19_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 20)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_20_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 21)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_21_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 22)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_22_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 23)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_23_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 24)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_24_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 25)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_25_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 26)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_26_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 27)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_27_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 28)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_28_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 29)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_29_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 30)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_30_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 31)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_31_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 32)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_32_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 33)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_33_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 34)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_34_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 35)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_35_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 36)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_36_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 37)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_37_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 38)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_38_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 39)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_39_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 40)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_40_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 41)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_41_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 42)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_42_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 43)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_43_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 44)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_44_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 45)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_45_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 46)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_46_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 47)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_47_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 48)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_48_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 49)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_49_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 50)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_50_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 51)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_51_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 52)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_52_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 53)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_53_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 54)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_54_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 55)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_55_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 56)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_56_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 57)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_57_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 58)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_58_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 59)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_59_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 60)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_60_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 61)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_61_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 62)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_62_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 63)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_63_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 64)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_64_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 65)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_65_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 66)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_66_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 67)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_67_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 68)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_68_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 69)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_69_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 70)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_70_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 71)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_71_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 72)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_72_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 73)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_73_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 74)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_74_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 75)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_75_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 76)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_76_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 77)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_77_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 78)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_78_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 79)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_79_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 80)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_80_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 81)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_81_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 82)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_82_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 83)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_83_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 84)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_84_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 85)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_85_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 86)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_86_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 87)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_87_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 88)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_88_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 89)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_89_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 90)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_90_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 91)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_91_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 92)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_92_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 93)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_93_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 94)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_94_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 95)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_95_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 96)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_96_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 97)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_97_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 98)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_98_EN;
#endif
#if(__NUMBER_OF_VIEWER_IMAGES >= 99)
extern VueMasterImageROMSpec VUE_MASTER_IMAGE_99_EN;
#endif

const VueMasterImageROMSpec* VUE_MASTER_ENTITIES[__NUMBER_OF_VIEWER_IMAGES] =
{
	#if(__NUMBER_OF_VIEWER_IMAGES >= 1)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_1_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 2)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_2_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 3)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_3_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 4)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_4_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 5)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_5_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 6)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_6_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 7)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_7_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 8)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_8_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 9)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_9_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 10)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_10_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 11)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_11_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 12)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_12_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 13)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_13_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 14)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_14_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 15)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_15_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 16)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_16_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 17)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_17_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 18)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_18_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 19)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_19_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 20)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_20_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 21)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_21_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 22)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_22_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 23)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_23_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 24)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_24_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 25)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_25_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 26)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_26_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 27)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_27_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 28)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_28_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 29)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_29_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 30)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_30_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 31)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_31_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 32)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_32_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 33)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_33_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 34)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_34_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 35)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_35_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 36)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_36_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 37)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_37_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 38)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_38_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 39)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_39_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 40)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_40_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 41)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_41_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 42)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_42_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 43)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_43_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 44)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_44_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 45)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_45_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 46)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_46_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 47)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_47_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 48)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_48_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 49)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_49_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 50)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_50_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 51)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_51_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 52)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_52_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 53)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_53_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 54)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_54_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 55)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_55_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 56)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_56_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 57)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_57_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 58)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_58_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 59)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_59_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 60)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_60_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 61)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_61_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 62)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_62_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 63)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_63_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 64)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_64_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 65)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_65_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 66)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_66_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 67)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_67_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 68)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_68_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 69)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_69_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 70)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_70_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 71)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_71_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 72)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_72_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 73)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_73_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 74)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_74_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 75)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_75_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 76)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_76_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 77)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_77_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 78)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_78_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 79)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_79_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 80)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_80_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 81)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_81_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 82)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_82_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 83)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_83_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 84)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_84_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 85)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_85_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 86)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_86_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 87)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_87_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 88)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_88_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 89)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_89_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 90)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_90_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 91)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_91_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 92)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_92_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 93)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_93_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 94)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_94_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 95)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_95_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 96)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_96_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 97)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_97_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 98)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_98_EN,
	#endif
	#if(__NUMBER_OF_VIEWER_IMAGES >= 99)
	(VueMasterImageROMSpec*)&VUE_MASTER_IMAGE_99_EN,
	#endif

};


#endif
