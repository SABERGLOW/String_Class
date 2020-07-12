#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace HomeMadeString
{
	class String
	{
		// Number of characters in the string
		int elementNum;
		// Pointer to the memory segment containing the characters
		char *pData;
		
	public:

		static int selementNum;
		static char *spData;
		// Default constructor (without arguments):
		String();


		// Copy constructor:
		String(const String &COPY);


		// Conversion constructor that expects a char* with '\0' at the end
		// This constructor is responsible for the conversion char*-> String
		String(const char* str);

		// Constructor with a char (c) and an int parameter (times)
		// This constructor creates a string that contains 'times' pieces of the character c
		// e.g. if c='$' and times=5 then String="$$$$$"
		String(const char c, int times);    //........................................... ADDED CONST HERE

		// Destructor:
		~String();


		// Copies the string to the buffer and terminates it with '\0' (string terminating character)
		// Memory allocation for the buffer is to be done by a caller
		void getStr(char * pBuff);
	
		// Returns with the string length
		//int getLength(const char &str, int elementNum);
		int getLength();

		// Writes the string to the given stream		
		void print(std::ostream& os);

		// Returns with the character at the given position, othewise 0
		char getChar(int pos);



		// --- Static Class Members. They work with two strings passed as parameters. ---
		
		// Returns with a concatenated string
		static String concatenate(const String &string1, const String &string2);
		// Compares two strings
		static bool compare(const String &string1, const String &string2);
		// Copies string2 to string1
		static void copy(String &string1,const String &string2);
	};

}

#endif /* STRING_H */