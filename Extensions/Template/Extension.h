
class Extension
{
public:

    LPRDATA rdPtr;
    LPRH    rhPtr;

    Edif::Runtime Runtime;

    static const int MinimumBuild = 251;
    static const int Version = 1;

    static const int OEFLAGS = 0;
    static const int OEPREFS = 0;
    
    static const int WindowProcPriority = 100;

    Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
    ~Extension();


    /*  Add any data you want to store in your extension to this class
        (eg. what you'd normally store in rdPtr)

        Unlike rdPtr, you can store real C++ objects with constructors
        and destructors, without having to call them manually or store
        a pointer.
    */

    // int MyVariable;

	TCHAR UppercaseArray[27];
	TCHAR LowercaseArray[27];
	TCHAR DigitArray[11];


    /*  Add your actions, conditions and expressions as real class member
        functions here. The arguments (and return type for expressions) must
        match EXACTLY what you defined in the JSON.

        Remember to link the actions, conditions and expressions to their
        numeric IDs in the class constructor (Extension.cpp)
    */

    /// Actions

       TCHAR * EncryptCaesarCipher(TCHAR * string, int shift);
	   TCHAR * DecryptCaesarCipher(TCHAR * string, int shift);

	   TCHAR * EncryptAffineShift(TCHAR * string, int offset, int multiplier);
	   TCHAR * DecryptAffineShift(TCHAR * string, int offset, int multiplier);

	   TCHAR * EncryptVigenerCipher(TCHAR * string, TCHAR * key);
	   TCHAR * DecryptVigenerCipher(TCHAR * string, TCHAR * key);

	   TCHAR * EncryptSubstitutionCipher(TCHAR * string, TCHAR * lowercase_map, TCHAR * uppercase_map, TCHAR * number_map);
	   TCHAR * DecryptSubstitutionCipher(TCHAR * string, TCHAR * lowercase_map, TCHAR * uppercase_map, TCHAR * number_map);

	   TCHAR * EncryptSafeCaesarCipher(TCHAR * string, int shift);
	   TCHAR * DecryptSafeCaesarCipher(TCHAR * string, int shift);

	   TCHAR * EncryptSafeAffineShift(TCHAR * string,int offset, int multiplier);
	   TCHAR * DecryptSafeAffineShift(TCHAR * string, int offset, int multiplier);

	   TCHAR * EncryptSafeVigenerCipher(TCHAR * string, TCHAR * key);
	   TCHAR * DecryptSafeVigenerCipher(TCHAR * string, TCHAR * key);

	   TCHAR * UppercaseArrayKey();
	   TCHAR * LowercaseArrayKey();
	   TCHAR * DigitArrayKey();


	   void EditUppercaseArray(TCHAR * NewKey);
	   void EditLowercaseArray(TCHAR * NewKey);
	   void EditDigitArray(TCHAR * NewKey);

	   bool ImproperKeyLength();


	   /* These are called if there's no function linked to an ID */

    void Action(int ID, LPRDATA rdPtr, long param1, long param2);
    long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
    long Expression(int ID, LPRDATA rdPtr, long param);




    /*  These replace the functions like HandleRunObject that used to be
        implemented in Runtime.cpp. They work exactly the same, but they're
        inside the extension class.
    */

    short Handle();
    short Display();

    short Pause();
    short Continue();

    bool Save(HANDLE File);
    bool Load(HANDLE File);

};