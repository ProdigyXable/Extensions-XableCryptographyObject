
#include "Common.h"

void Extension::EditUppercaseArray(TCHAR * NewKey)
{
	if(_tcslen(NewKey) == 26)
	{
		strcpy(Extension::UppercaseArray, (char *)NewKey);
	}

	else
	{
		// Valid testing
		Runtime.GenerateEvent(0);
	}
}
void Extension::EditLowercaseArray(TCHAR * NewKey)
{
	if(_tcslen(NewKey) == 26)
	{
		strcpy(Extension::LowercaseArray, (char *)NewKey);
	}

	else
	{
		// Valid testing
		Runtime.GenerateEvent(0);
	}
}
void Extension::EditDigitArray(TCHAR * NewKey)
{
	if(_tcslen(NewKey) == 10)
	{
		strcpy(Extension::DigitArray, (char *)NewKey);
	}

	else
	{
		// Valid testing
		Runtime.GenerateEvent(0);
	}
}