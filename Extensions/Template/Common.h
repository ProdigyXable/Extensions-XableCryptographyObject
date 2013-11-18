#pragma once

// #define TGFEXT       // TGF2, MMF2, MMF2 Dev
   #define MMFEXT       // MMF2, MMF2 Dev
// #define PROEXT       // MMF2 Dev only

#include    "Edif.h"
#include	"Resource.h"

// edPtr : Used at edittime and saved in the MFA/CCN/EXE files

struct EDITDATA
{
	// Header - required
	extHeader		eHeader;

	char UppercaseArray[27];
	char LowercaseArray[27];
	char DigitArray[11];

	// Object's data
//	short			swidth;
//	short			sheight;

};

#include "Extension.h"
