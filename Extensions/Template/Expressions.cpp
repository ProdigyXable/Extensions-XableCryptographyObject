
#include "Common.h"


TCHAR * Extension::EncryptCaesarCipher(TCHAR * string, int shift)
{
	unsigned int length = _tcslen(string);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);
    
	if(length <= 0)
	{
		return string;
	}

	for(int index = 0; index < length; index++)
	{
		New[index] += shift;
	}

	return New;    
}

TCHAR * Extension::DecryptCaesarCipher(TCHAR * string, int shift)
{
	unsigned int length = _tcslen(string);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0)
	{
		return string;
	}


	for(int index = 0; index < length; index++)
	{
		New[index] -= shift;
	}

	return New;
}

TCHAR * Extension::EncryptAffineShift(TCHAR * string,  int offset, int multiplier)
{
	unsigned int length = _tcslen(string);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0 || multiplier == 0)
	{
		return string;
	}

	for(int index = 0; index < length; index++)
	{
		New[index] += (multiplier*(index+offset));
	}

	return New;
}

TCHAR * Extension::DecryptAffineShift(TCHAR * string, int offset, int multiplier)
{
	unsigned int length = _tcslen(string);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0 || multiplier == 0)
	{
		return string;
	}

	for(int index = 0; index < length; index++)
	{
		New[index] -= (multiplier*(index+offset));
	}

	return New;
}

TCHAR * Extension::EncryptVigenerCipher(TCHAR * string, TCHAR * key)
{
	unsigned int string_length = _tcslen(string);
	unsigned int key_length = _tcslen(key);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(key_length <= 0 || string_length <= 0)
	{
		return string;
	}

	else
	{

		for(int index = 0; index < string_length; index++)
		{
			New[index] +=  abs(toupper(key[index % key_length])-64);
		}

		return New;
	}
}

TCHAR * Extension::DecryptVigenerCipher(TCHAR * string, TCHAR * key)
{

	unsigned int string_length = _tcslen(string);
	unsigned int key_length = _tcslen(key);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(key_length <= 0 || string_length <= 0)
	{
		return string;
	}
	else
	{

		for(int index = 0; index < string_length; index++)
		{
			New[index] -=  abs(toupper(key[index % key_length])-64);
		}

	return New;
	}
}

TCHAR * Extension::EncryptSubstitutionCipher(TCHAR * string, TCHAR * lowercase_map, TCHAR * uppercase_map, TCHAR * number_map)
 {
	if(_tcslen(lowercase_map) == 26 && _tcslen(uppercase_map) == 26 && _tcslen(number_map) == 10)
	{
		 unsigned int string_length = _tcslen(string);


	  TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	 for(int index = 0; index < string_length; index++)
	 {
		 if(islower(string[index]))
		 {
			 New[index] = lowercase_map[(string[index]-97)];
		 }

		 else if(isupper(string[index]))
		 {
			 New[index] = uppercase_map[(string[index]-65)];
		 }

		 else if(isdigit(string[index]))
		 {
			 New[index] = number_map[(string[index]-48)];
		 }
	 }

	
	 return New;
	 
	}

	else
	{
		return NULL;
	}
 }

TCHAR * Extension::DecryptSubstitutionCipher(TCHAR * string,TCHAR * lowercase_map, TCHAR * uppercase_map, TCHAR * number_map)
 {
	if(_tcslen(lowercase_map) == 26 && _tcslen(uppercase_map) == 26 && _tcslen(number_map)== 10)
	{
		 unsigned int string_length = _tcslen(string);


		TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
		_tcscpy(New, string);

		 for(int index = 0; index < string_length; index++)
		 {
			 if(islower(string[index]))
			 {
				 New[index] = lowercase_map[(string[index]-97)];
			 }

			 else if(isupper(string[index]))
			 {
				 New[index] = uppercase_map[(string[index]-65)];
			 }

			 else if(isdigit(string[index]))
			 {
				 New[index] = number_map[(string[index]-48)];
			 }
		 }

	
	 return New;
	 
	}
 }

TCHAR * Extension::EncryptSafeCaesarCipher(TCHAR * string, int shift)
{
	unsigned int length = _tcslen(string);
	
	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0)
	{
		return string;
	}

	for(int index = 0; index < length; index++)
	{
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-65)+shift) % 26) + 65;
		}

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-97)+shift) % 26) +97;
		}

		else if(isdigit(string[index]))
		{
			New[index] = (((string[index]-48)+shift) % 10) + 48;
		}
	}

	return New;    
}

TCHAR * Extension::DecryptSafeCaesarCipher(TCHAR * string, int shift)
{

	unsigned int length = _tcslen(string);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0)
	{
		return string;
	}


	for(int index = 0; index < length; index++)
	{
		
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-65)+(26-(shift % 26))) % 26) + 65;
		}

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-97)+(26-(shift % 26))) % 26) +97;
		}

		else if(isdigit(string[index]))
		{
			New[index] = (((string[index]-48)+(10-(shift % 10))) % 10) + 48;
		}
	}

	return New;
}

TCHAR * Extension::EncryptSafeAffineShift(TCHAR * string, int offset, int multiplier)
{
	unsigned int length = _tcslen(string);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0 || multiplier == 0)
	{
		return string;
	}

	for(int index = 0; index < length; index++)
	{
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-65)+((multiplier*(index+offset))) % 26) % 26) + 65;
		}	

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-97)+((multiplier*(index+offset))) % 26) % 26) + 97;
		}

		else if(isdigit(string[index]))
		{
						
			New[index] = (((string[index]-48)+((multiplier*(index+offset))) % 10) % 10) + 48;
		}

	}

	return New;
}

TCHAR * Extension::DecryptSafeAffineShift(TCHAR * string, int offset, int multiplier)
{
	unsigned int length = _tcslen(string);

	TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	char * foo = (char *) Runtime.Allocate(length);

	if(length <= 0 || multiplier == 0)
	{
		return string;
	}

	for(int index = 0; index < length; index++)
	{
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-65)+(26-(multiplier*(index+offset))) % 26) % 26) + 65;
		}	

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-97)+(26-(multiplier*(index+offset))) % 26) % 26) + 97;
		}

		else if(isdigit(string[index]))
		{
						
			New[index] = (((string[index]-48)+(10-(multiplier*(index+offset))) % 10) % 10) + 48;
		}
	}

	return New;
}

/*TCHAR * Extension::EncryptSafeVigenerCipher(TCHAR * string, TCHAR * key)
{
	unsigned int string_length = _tcslen(string);
	unsigned int key_length = _tcslen(key);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(key_length <= 0 || string_length <= 0)
	{
		return string;
	}
	else
	{

		for(int index = 0; index < string_length; index++)
		{
			if(isupper(string[index]))
			{
				New[index] =  ((string[index]-64)+(toupper(key[index % key_length])- 64) % 26) + 64;
			}

			else if(islower(string[index]))
			{
				New[index] =  ((string[index]-97)+(tolower(key[index % key_length])- 97) % 26) + 97;
			}

			else if(isdigit(string[index]))
			{
				New[index] =  ((string[index]-48)+(toupper(key[index % key_length])- 48) % 10) + 48;
			}

		}

		return New;
	}
}

TCHAR * Extension::DecryptSafeVigenerCipher(TCHAR * string, TCHAR * key)
{
	unsigned int string_length = _tcslen(string);
	unsigned int key_length = _tcslen(key);

	 TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(key_length <= 0 || string_length <= 0)
	{
		return string;
	}
	else
	{

		for(int index = 0; index < string_length; index++)
		{
			if(isupper(string[index]))
			{
				New[index] =  ((string[index]-64)+(26-(toupper(key[index % key_length])- 64)) % 26) + 64;
			}

			else if(islower(string[index]))
			{
				New[index] =  ((string[index]-97)+(26-(tolower(key[index % key_length])- 97)) % 26) + 97;
			}

			else if(isdigit(string[index]))
			{
				New[index] =  ((string[index]-48)+(10-(toupper(key[index % key_length])- 48)) % 10) + 48;
			}

		}

	return New;
	}
}
*/