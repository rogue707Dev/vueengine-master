///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Printing.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE GuiFontTiles[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

CharSetROMSpec NUMBER_FONT_CH =
{
	// number of chars
	15,

	// allocation type
	__NOT_ANIMATED,

	// char spec
	GuiFontTiles,
};

FontROMSpec NUMBER_FONT =
{
	// font charset spec pointer
	(CharSetSpec*)&NUMBER_FONT_CH,

	// character number at which the font starts, allows you to skip the control characters for example
	46,

	// number of characters in this font
	15,

	// size of a single character (in chars) ({width, height})
	{1, 1},

	// font's name
	"Number",
};