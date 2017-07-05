// string::length
#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string string1 = "1234567890";
	cout << string1.length() << endl;

	std::string str ("Test string");
	std::cout << "The size of str is " << str.length() << " bytes.\n";
	return 0;
}