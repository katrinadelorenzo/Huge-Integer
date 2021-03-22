#include <iostream>
using namespace std;


class HugeInteger{
public:
  HugeInteger();
  HugeInteger(int d[], int len);
  
  //member function that initializes calling object from user input
  void input(); 


  void output(); 


  // add calling object with "second", and return the result
  
  HugeInteger operator + (HugeInteger const &second);
  
  HugeInteger multiply (int x);

  bool isEqualTo (const HugeInteger & that);
  bool isNotEqualTo (const HugeInteger & that);
  bool isGreaterThanorEqualTo (const HugeInteger & that);
  bool isLessThanorEqualTo (const HugeInteger & that);

  bool isZero ();


private:
  const static int MAXDIGITS=40;
  int digits[MAXDIGITS];



  
};

