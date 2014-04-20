
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

	for(unsigned int index = 0; index < length; index++)
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


	for(unsigned int index = 0; index < length; index++)
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

	for(unsigned int index = 0; index < length; index++)
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

	for(unsigned int index = 0; index < length; index++)
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

		for(unsigned int index = 0; index < string_length; index++)
		{
			New[index] +=  abs(toupper(key[index % key_length])-A_index_value);
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

		for(unsigned int index = 0; index < string_length; index++)
		{
			New[index] -=  abs(toupper(key[index % key_length])-A_index_value);
		}

	return New;
	}
}

TCHAR * Extension::EncryptSubstitutionCipher(TCHAR * string, TCHAR * lowercase_map, TCHAR * uppercase_map, TCHAR * number_map)
 {
	if(_tcslen(lowercase_map) == LowerCaseArrayLength && _tcslen(uppercase_map) == UpperCaseArrayLength && _tcslen(number_map) == NumberArrayLength)
	{
		 unsigned int string_length = _tcslen(string);


	  TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	 for(unsigned int index = 0; index < string_length; index++)
	 {
		 if(islower(string[index]))
		 {
			 New[index] = lowercase_map[(string[index]-a_index_value)];
		 }

		 else if(isupper(string[index]))
		 {
			 New[index] = uppercase_map[(string[index]-A_index_value)];
		 }

		 else if(isdigit(string[index]))
		 {
			 New[index] = number_map[(string[index]-zero_index_value)];
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
	if(_tcslen(lowercase_map) == LowerCaseArrayLength && _tcslen(uppercase_map) == UpperCaseArrayLength && _tcslen(number_map)== NumberArrayLength)
	{
		 unsigned int string_length = _tcslen(string);


		TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
		_tcscpy(New, string);

		 for(unsigned int index = 0; index < string_length; index++)
		 {
			 if(islower(string[index]))
			 {
				 New[index] = lowercase_map[(string[index]-a_index_value)];
			 }

			 else if(isupper(string[index]))
			 {
				 New[index] = uppercase_map[(string[index]-A_index_value)];
			 }

			 else if(isdigit(string[index]))
			 {
				 New[index] = number_map[(string[index]-zero_index_value)];
			 }
		 }

	
	 return New;
	 
	}

	else
	{
		return 0;
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

	for(unsigned int index = 0; index < length; index++)
	{
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-A_index_value)+shift) % UpperCaseArrayLength) + A_index_value;
		}

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-a_index_value)+shift) % LowerCaseArrayLength) +a_index_value;
		}

		else if(isdigit(string[index]))
		{
			New[index] = (((string[index]-zero_index_value)+shift) % NumberArrayLength) + zero_index_value;
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


	for(unsigned int index = 0; index < length; index++)
	{
		
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-A_index_value)+(UpperCaseArrayLength-(shift % UpperCaseArrayLength))) % UpperCaseArrayLength) + A_index_value;
		}

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-a_index_value)+(LowerCaseArrayLength-(shift % LowerCaseArrayLength))) % LowerCaseArrayLength) +a_index_value;
		}

		else if(isdigit(string[index]))
		{
			New[index] = (((string[index]-zero_index_value)+(NumberArrayLength-(shift % NumberArrayLength))) % NumberArrayLength) + zero_index_value;
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

	for(unsigned int index = 0; index < length; index++)
	{
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-A_index_value)+((multiplier*(index+offset))) % UpperCaseArrayLength) % UpperCaseArrayLength) + A_index_value;
		}	

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-a_index_value)+((multiplier*(index+offset))) % LowerCaseArrayLength) % LowerCaseArrayLength) + a_index_value;
		}

		else if(isdigit(string[index]))
		{
						
			New[index] = (((string[index]-zero_index_value)+((multiplier*(index+offset))) % NumberArrayLength) % NumberArrayLength) + zero_index_value;
		}

	}

	return New;
}

TCHAR * Extension::DecryptSafeAffineShift(TCHAR * string, int offset, int multiplier)
{
	unsigned int length = _tcslen(string);

	TCHAR * New = (TCHAR *) Runtime.Allocate(_tcslen(string) + 1);
    _tcscpy(New, string);

	if(length <= 0 || multiplier == 0)
	{
		return string;
	}

	for(unsigned int index = 0; index < length; index++)
	{
		if(isupper(string[index]))
		{
			New[index] = (((string[index]-A_index_value)+(UpperCaseArrayLength-(multiplier*(index+offset))) % UpperCaseArrayLength) % UpperCaseArrayLength) + A_index_value;
		}	

		else if(islower(string[index]))
		{
			New[index] = (((string[index]-a_index_value)+(LowerCaseArrayLength-(multiplier*(index+offset))) % LowerCaseArrayLength) % LowerCaseArrayLength) + a_index_value;
		}

		else if(isdigit(string[index]))
		{
						
			New[index] = (((string[index]-zero_index_value)+(NumberArrayLength-(multiplier*(index+offset))) % NumberArrayLength) % NumberArrayLength) + zero_index_value;
		}
	}

	return New;
}

TCHAR * Extension::EncryptSafeVigenerCipher(TCHAR * string, TCHAR * key)
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

		for(unsigned int index = 0; index < string_length; index++)
		{
			if(isupper(string[index]))
			{
				New[index] =  ((string[index]-A_index_value)+(toupper(key[index % key_length])- A_index_value) % UpperCaseArrayLength) + A_index_value;
			}

			else if(islower(string[index]))
			{
				New[index] =  ((string[index]-a_index_value)+(tolower(key[index % key_length])- a_index_value) % LowerCaseArrayLength) + a_index_value;
			}

			else if(isdigit(string[index]))
			{
				New[index] =  ((string[index]-zero_index_value)+(toupper(key[index % key_length])- zero_index_value) % NumberArrayLength) + zero_index_value;
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

		for(unsigned int index = 0; index < string_length; index++)
		{
			if(isupper(string[index]))
			{
				New[index] =  ((string[index]- A_index_value)+(UpperCaseArrayLength-(toupper(key[index % key_length]) - A_index_value)) % UpperCaseArrayLength) + UpperCaseArrayLength;
			}

			else if(islower(string[index]))
			{
				New[index] =  ((string[index]- a_index_value)+(LowerCaseArrayLength-(tolower(key[index % key_length]) - a_index_value)) % LowerCaseArrayLength) + a_index_value;
			}

			else if(isdigit(string[index]))
			{
				New[index] =  ((string[index]- zero_index_value)+(NumberArrayLength-(toupper(key[index % key_length]) - zero_index_value)) % NumberArrayLength) + zero_index_value;
			}

		}

	return New;
	}
}

TCHAR * Extension::UppercaseArrayKey()
{
	return	Runtime.CopyString(UpperCaseArray);
}
TCHAR * Extension::LowercaseArrayKey()
{
	return	Runtime.CopyString(LowerCaseArray);
}
TCHAR * Extension::DigitArrayKey()
{
	return	Runtime.CopyString(NumberArray);
}