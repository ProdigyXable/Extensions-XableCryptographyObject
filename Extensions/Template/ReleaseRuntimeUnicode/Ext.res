        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y7  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Cryptography Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright (C) 2013 Xable Enterprises",
        "Comment": "An extension used to perform basic cryptography encrpytion and decrpytion as Caesar Shifts ",
        "URL": "http://www.xable.us",
        "Help": "http://www.xable.us/xable-cryptography-object.html",
        "Identifier": "PXCC"
    },
    "ActionMenu": 
	[],

    "ConditionMenu": [],
    "ExpressionMenu": [
		
        ["Encrypt",
			[0,"Caesar Cipher"],
			[2,"Affine Cpher"],
			[4,"Vigener Cipher"],
			[6,"Substitution Cipher"],
			[8,"Caesar Cipher [Safe]"],
			[10,"Affine Cipher [Safe]"],
			[12,"Vigener Cipher [Safe]"],
		],
		"Separator",
		["Decrypt",
			[1,"Caesar Cipher"],
			[3,"Affine Cipher"],
			[5,"Vigener Cipher"],
			[7,"Substitution Cipher"],
			[9,"Caesar Cipher [Safe]"],
			[11,"Affine Cipher [Safe]"],
			[13,"Vigener Cipher [Safe]"],
		],
		"Separator",
    ],
    "Actions": [],
    "Conditions": [],
    "Expressions": [
        {"Title": "EncryptCaesarCipher(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Length of Message"],
				["Integer","Shift amount"],
            ]
        },
		 {"Title": "DecryptCaesarCipher(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Length of Message"],
				["Integer","Shift amount"],
            ]
        },
		{"Title": "EncryptAffineShift(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
               	["Integer","Offset amount"],
				["Integer","Multiplier (integer)"],
            ]
        },
		{"Title": "DecryptAffineShift(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Offset amount"],
				["Integer","Multiplier (integer)"],
            ]
        },
      {"Title": "EncryptVigener(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Text","Key"],
				
            ]
        },
		  {"Title": "DecryptVigener(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Text","Key"],
				]
        },
		 {"Title": "EncryptSubstitutionTable(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Text","Lowercase Key"],
				["Text","Uppercase Key"],
				["Text","Number Key"],
            ]
        },
		{"Title": "DecryptSubstitutionTable(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Text","Lowercase Key"],
				["Text","Uppercase Key"],
				["Text","Number Key"],
            ]
        },

		{"Title": "EncryptSafeCaesarCipher(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Shift amount"],
            ]
        },
		 {"Title": "DecryptSafeCaesarCipher(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Shift amount"],
            ]
        },
		{"Title": "EncryptSafeAffineShift(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Offset amount"],
				["Integer","Multiplier (integer)"],
            ]
        },
		{"Title": "DecryptSafeAffineShift(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Integer","Offset amount"],
				["Integer","Multiplier (integer)"],
            ]
        },
      {"Title": "EncryptSafeVigener(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Text","Key"],
				]
        },
		  {"Title": "DecryptSafeVigener(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
                ["Text","Key"],
				
            ]
        },
		
		
      
    ]
} &       �� ��     0	           M F 2                               