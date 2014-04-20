
#include "Common.h"

void Extension::EditUppercaseArray(TCHAR * NewKey)
{
	if(_tcslen(NewKey) == 26)
	{
		_tcscpy(UpperCaseArray, NewKey);
	}

	else
	{
		// Valid testing
		Runtime.GenerateEvent(WrongKeyLength);
	}
}
void Extension::EditLowercaseArray(TCHAR * NewKey)
{
	if(_tcslen(NewKey) == 26)
	{
		_tcscpy(LowerCaseArray, NewKey);
	}

	else
	{
		// Validation test
		Runtime.GenerateEvent(WrongKeyLength);
	}
}
void Extension::EditDigitArray(TCHAR * NewKey)
{
	if(_tcslen(NewKey) == 10)
	{
		_tcscpy(NumberArray, NewKey);
	}

	else
	{
		// Validation test
		Runtime.GenerateEvent(WrongKeyLength);
	}
}