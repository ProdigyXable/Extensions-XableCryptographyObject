        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�  (   E D I F   ��e       0 	        �PNG

   IHDR           ���   tRNS      n��  �IDATx���1K1��������""������Mp��(
V<��*��(�U\��I�z��:�>��]��%o�����җ�`��v�K=�`̗�(�Ls�*D�FI !8RJ��M~ks5�%�k#c�B^}�3@5�l���9#g�3L�3�`0t�09p�P
Wə����"F��T��� "�?k0�̉�H+7o��7'��{� qxP4���V0� ����
�-t��8m��C�>�V����i�}ia��>���lh����x^�r�����KwQV�r��>���{(6_hɢY�7�\ 0�|T^�����8��'��jͽ�u`f`��9�h�uP�ҷ9Kj�2*�-f��=�V�UĐC�eO����ԡz�M���/��%d�/aw    IEND�B`�  `  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Crypt. Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright � 2013 Xable Enterprises",
        "Comment": "An extension used to perform basic cryptography encryption and decryption as Caesar Shifts ",
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
			"Separator",
			[6,"Substitution Cipher"],
			"Separator",
			[8,"Caesar Cipher [Safe]"],
			[10,"Affine Cipher [Safe]"],
			[12,"Vigener Cipher [Safe]"],
		],
		"Separator",
		["Decrypt",
			[1,"Caesar Cipher"],
			[3,"Affine Cipher"],
			[5,"Vigener Cipher"],
			"Separator",
			[7,"Substitution Cipher"],
			"Separator",
			[9,"Caesar Cipher [Safe]"],
			[11,"Affine Cipher [Safe]"],
			[13,"Vigener Cipher [Safe]"],
		],
		["Substitution Keys",
			[14, "Return Uppercase Key"],
			[15, "Return Lowercase Key"],
			[16, "Return Digit Key"],
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
				["Integer","Shift amount"],
            ]
        },
		 {"Title": "DecryptCaesarCipher(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Message"],
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
		 {"Title": "ReturnUppercaseKey(",
         "Returns": "Text",
        },
		{"Title": "ReturnLowercaseKey(",
         "Returns": "Text",
        },
		{"Title": "ReturnNumericKey(",
         "Returns": "Text",
        },
      
    ]
}&       �� ��     0	           M F 2                               