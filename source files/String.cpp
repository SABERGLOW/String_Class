#include <iostream>
#include "String.h"

using namespace std;
using namespace HomeMadeString;

		// Default constructor (without arguments):
		String::String()
        {
            elementNum = 0;
            pData = new char[elementNum];
        }


		// Copy constructor:
		String::String(const String &COPY)
        {
            elementNum = COPY.elementNum;
            char *temp = new char[elementNum+1];
            for(int x=0; x<elementNum; x++) 
            {
                temp[x] = COPY.pData[x];
            }
            temp[elementNum] = '\0';
            pData = temp;
        }



		// Conversion constructor that expects a char* with '\0' at the end
		// This constructor is responsible for the conversion char*-> String
		String::String(const char* str)
        {
            elementNum = 0;
            for(int x=0; str[x] != '\0'; x++) 
            {
                elementNum++;
            }

            pData = new char[elementNum+1];
            for(int x=0; x<elementNum; x++) 
            {
                pData[x] = str[x];
            }
            pData[elementNum] = '\0';
        }

        // Destructor:
		String::~String()
        {
            elementNum = 0;
            delete []pData;
            pData = NULL;
        }


		// Constructor with a char (c) and an int parameter (times)
		// This constructor creates a string that contains 'times' pieces of the character c
		// e.g. if c='$' and times=5 then String="$$$$$"
		String::String(const char c, int times)    //........................................... ADDED CONST HERE
        {
            elementNum = times;
            pData = new char[elementNum+1];
            for(int x=0; x<elementNum; x++) 
            {
                pData[x] = c;
            }
            pData[elementNum] = '\0';
        }



		// Copies the string to the buffer and terminates it with '\0' (string terminating character)
		// Memory allocation for the buffer is to be done by a caller
		void String::getStr(char *pBuff)
        {
            for(int x=0; x<elementNum; x++) 
            {
                pBuff[x] = pData[x];
            }
            pBuff[elementNum] = '\0';
        }
		
		// Returns with the string length
		int String::getLength()
        {
            return elementNum;
        }

		// Writes the string to the given stream		
		void String::print(std::ostream& os)
        {
            for(unsigned int i=0;i<elementNum;i++)
            {
                os<<pData[i];
            }
        }

		// Returns with the character at the given position, othewise 0
		char String::getChar(int pos)
        {
            if((pos<0) || (pos>=elementNum))
            {
                return 0;
            }
            else
            {
                return pData[pos];
            }
            
        }


		// --- Static Class Members. They work with two strings passed as parameters. ---
		
		// Returns with a concatenated string
		String String::concatenate(const String &string1, const String &string2)
		{
			String Concat_String;
			Concat_String.elementNum = string1.elementNum + string2.elementNum;
			Concat_String.pData = new char[Concat_String.elementNum+1];

			for(int x=0; x<string1.elementNum; x++)
			{
				Concat_String.pData[x] = string1.pData[x];
			}
			for(int x=0; x<string2.elementNum; x++)
			{
				Concat_String.pData[string1.elementNum+x-1] = string2.pData[x];
			}
			Concat_String.pData[Concat_String.elementNum] = '\0';
			return Concat_String;
		}

		// Compares two strings
		bool String::compare(const String &string1, const String &string2)
        {
			if(string1.elementNum != string2.elementNum)
			{
				return false;
			}
			else
			{
				for(int x=0; x<string1.elementNum; x++) 		
            	{
                	if(string1.pData[x] != string2.pData[x])
					{
						return false;
					}
            	}
				return true;
			}
        }

		// Copies string2 to string1
		void String::copy(String &string1,const String &string2)
		{
			string1 = string2; //.......used the copy contructor here. alternate method listed below.

		/*                                                        ////////////////////////////////////////////////////////
			string1.elementNum = string2.elementNum;            // This is a manual method to copy string2 to string 1.//
			string1.pData = new char[string2.elementNum+1];    /////////////////////////////////////////////////////////
			for(int x=0; x<string1.elementNum; x++) 		
            {
                string1.pData[x] = string2.pData[x];
            }
            string1.pData[string1.elementNum] = '\0';  
		*/

		}