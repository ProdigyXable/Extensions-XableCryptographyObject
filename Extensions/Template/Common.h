#pragma once

// #define TGFEXT       // TGF2, MMF2, MMF2 Dev
   #define MMFEXT       // MMF2, MMF2 Dev
// #define PROEXT       // MMF2 Dev only

#include    "Edif.h"
#include	"Resource.h"

// edPtr : Used at edittime and saved in the MFA/CCN/EXE files

// -- Custom Shortcuts --
#define UpperCaseArray	Extension::UppercaseArray
#define LowerCaseArray	Extension::LowercaseArray
#define NumberArray		Extension::DigitArray

// -- Immediate Event Shorcuts --
#define WrongKeyLength 0

#define A_index_value 65
#define a_index_value 97
#define zero_index_value 48

#define UpperCaseArrayLength	26
#define LowerCaseArrayLength	26
#define NumberArrayLength		10

struct EDITDATA
{
	// Header - required
	extHeader		eHeader;

	TCHAR UppercaseArray[27];
	TCHAR LowercaseArray[27];
	TCHAR DigitArray[11];

	// Object's data
//	short			swidth;
//	short			sheight;

};

#include "Extension.h"
