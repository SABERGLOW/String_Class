#include <iostream>
#include "String.h"
#include "String.cpp"


using namespace std;
using namespace HomeMadeString;

int main()
{
	// Test the default constructor
	String s1;
	// Test the conversion constructor
	String s2="Hello, hello!";

	// Let's see the results
	cout<<endl<<"TESTING s1: "<<endl;
	s1.print(cout);
	cout<<endl;
	cout<<endl<<"TESTING s2: "<<endl;
	s2.print(cout);
	cout<<endl<<endl;

	// Test the copy function
	String::copy(s1,s2);
	cout<<endl<<"COPY FUNCTION TESTING: "<<endl;
	s1.print(cout);
	cout<<endl;
	s2.print(cout);
	cout<<endl;

	// Test the compare function
	cout<<endl<<"COMPARE FUNCTION TESTING: "<<endl;
	if(String::compare(s1,s2))
		cout<<"s1 and s2 are the same!"<<endl;

	// Test the special constructor with two parameters 
	String s3('-',15);
	cout<<endl<<"SPECIAL CONSTRUCTOR TESTING: "<<endl;
	s3.print(cout);
	cout<<endl;

	// Test the concatenate function and the copy constructor
	cout<<endl<<"CONCATENATE FUNCTION TESTING: "<<endl;
	String s4=String::concatenate(s2,s3);
	s4.print(cout);
	cout<<endl;

	// Test the GetChar function
	cout<<endl<<"get Char TESTING: "<<endl;
	for(int i=0; i<s4.getLength();i++)
	{
		cout<<s4.getChar(i);
	}
	cout<<endl;

	// Test the getStr function
	char* pStr=new char[s4.getLength()+1]; // Reserving memory for string and terminating character
	s4.getStr(pStr);
	cout<<pStr<<endl;	// cout can work with strings
	delete[] pStr;		// delete the buffer and release the allocated memory

	return 0;
}
