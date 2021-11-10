#include <iostream>
#include <string>
using namespace std;
int main()
{
  string str("String to character array");
  // Casting a const char * containing the string on a char *
  char *cstr = (char *)str.c_str();
  // Right now cstr has the same adress and content as str
  // Good in case we want to pass a char array but only have a string
  cout << cstr;
  delete[] cstr;
  return 0;
}