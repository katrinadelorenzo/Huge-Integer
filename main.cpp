/* 
  This program uses the class HugeInteger to implement different operations. HugeInteger is a 40 digit integer.
  Author: Katrina DeLorenzo
  Last Modified: 10 October 2019
  Known bug: None
*/

#include <iostream>
#include <array>
using namespace std;
#include "HugeInteger.h"

int main()
{
	cout <<"This program tests HugeInteger class\n";
	HugeInteger a,b;
	string op;
	string answer;

	
	do {
		cout <<"Enter one huge integer:";
		a.input();
		cout <<"Enter another huge integer:";
		b.input();
		cout <<"Enter the operator:";
		cin >> op;

		if (op=="+"){
			HugeInteger result = a + b;
			
			a.output();
			cout <<"+";
			b.output();
			cout <<"=";
			result.output();
		} else if (op == "*") {
		  int integer;
		  
		  cout << "Enter an integer to multiply by a: ";
		  cin >> integer;
		  //Multiply function

		  HugeInteger result = a.multiply(integer);

		  //following code outputs "a * int = result"
		  a.output();
		  cout << " * ";
		  cout << integer;
		  cout << " = ";
		  result.output(); // outputs result
		  
		} else if (op=="==") {
			bool r = a.isEqualTo (b);

			a.output();
			if (r)
				cout <<"==";
			else
				cout <<"!=";
			b.output();

		} else if (op=="!=") {
			bool r = a.isNotEqualTo (b);

			a.output();
			if (r)
				cout <<"!=";
			else
				cout <<"==";
			b.output();
		} else if (op==">=") {
			bool r = a.isGreaterThanorEqualTo (b);

			a.output();
			if (r)
				cout <<">=";
			else
				cout <<"is not greater than or equal to";
			b.output();

		} else if (op=="<=") {
			bool r = a.isLessThanorEqualTo (b);

			a.output();
			if (r)
				cout <<"<=";
			else
				cout <<"is not less than or equal to";
			b.output();

		}

		cout << endl;
		cout <<"cont? (yes/no):";
		cin >>answer;

	} while (answer=="yes");

}
