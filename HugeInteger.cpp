#include <string>
#include <iostream>
#include <array>
#include <assert.h>
#include "HugeInteger.h"
using namespace std;

//Constructor
HugeInteger::HugeInteger()
{
	//set it to zero
	for (int i=0;i<MAXDIGITS;i++)
		digits[i]=0;
}

//d stores the digits, and len is the lenght of d array
HugeInteger::HugeInteger(int d[], int len)
{
	assert (len<=MAXDIGITS);

	for (int i=0;i<len;i++)
		digits[i]=d[i];

	for (int i=len+1; i< MAXDIGITS; i++)
		digits[i] = 0;
}

//member function that initializes calling object from user input
void HugeInteger::input(){
	string input;

	cin >> input;

	int len = input.length();
	
	for (int i=0;i<len;i++)
	{
		digits[i] = input[len-1-i]-'0';
	}

	for (int i=len;i<MAXDIGITS; i++)
		digits[i] = 0;

}

//member function that outputs value inputted using input function
void HugeInteger::output()
{
	bool display=false;

	for (int i=MAXDIGITS-1;i>=0;i--)
	{
		if (digits[i]!=0)
			display = true; //turn on the flag to display 

		if (display || i==0)	//need to display 0 properly
			cout <<digits[i];

	}
	
}

//member overloading operator function for addition of HugeInteger objects
HugeInteger HugeInteger::operator + (HugeInteger const &second)
{
	HugeInteger result;
	
	int carry = 0, sum = 0;
	for (int i=0; i < MAXDIGITS; i++) {
      		sum = digits[i] + second.digits[i] + carry;
      		if (sum <= 9) {
         		result.digits[i] = sum;
         		carry = 0;
      		}
      		else {
         		result.digits[i] = (sum % 10);
         		carry = sum/10 % 10;
      		}
   	}


   	if (carry > 0) {
      		cout << "Overflow" << endl;
   	}

	return result;

}

//member function for multiplication of HugeInteger objects
HugeInteger HugeInteger::multiply (int x)
{
  
  HugeInteger result; 
  int carry = 0; // Number that carries when result >= 10
  
    
  for (int i = 0; i < MAXDIGITS; i++) {
    if (digits[i] == 0)
      carry = 0; 
    int temp = digits[i] * x + carry; // temp result value
    if (temp < 10) {
      result.digits[i] = temp; 
    }
    else {
      result.digits[i] = temp % 10; // separates the one's digit from the ten's digit
      carry = temp/10 % 10; // separates the ten's digit and carries it over to the next number
    }
  }
  return result; // total product
  
}



bool HugeInteger::isEqualTo (const HugeInteger & that)
{

	for (int i=0;i<MAXDIGITS;i++)
		if (digits[i]!=that.digits[i])
			return false;

	return true;

}

bool HugeInteger::isNotEqualTo (const HugeInteger & that)
{
	return (!(isEqualTo (that)));
}

bool HugeInteger::isGreaterThanorEqualTo (const HugeInteger & that)
{
	for (int i=0;i<MAXDIGITS;i++)
		if (digits[i]<that.digits[i])
			return false;
	return true;
}


bool HugeInteger::isLessThanorEqualTo (const HugeInteger & that)
{
	for (int i=0;i<MAXDIGITS;i++)
		if (digits[i]>that.digits[i])
			return false;
	return true;
}


bool HugeInteger::isZero ()
{
	for (int i=0;i<MAXDIGITS;i++)
		if (digits[i]!=0)
			return false;

	return true;
}

