// Problem Statement
// You are given two s: N and K. Lun the dog is interested in strings that satisfy the following conditions:

// The string has exactly N characters, each of which is either 'A' or 'B'.
// The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.
// If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.

// Definition
// Class: AB
// Method: createString
// Parameters: int, int
// Returns: string
// Method signature: string createString(int N, int K)
// (be sure your method is public)
// Limits
// Time limit (s): 2.000
// Memory limit (MB): 256
// Constraints
// - N will be between 2 and 50, inclusive.
// - K will be between 0 and N(N-1)/2, inclusive.

// Examples
// 0)
// 3
// 2
// Returns: "ABB"
// This string has exactly two pairs (i, j) mentioned in the statement: (0, 1) and (0, 2).
// 1)
// 2
// 0
// Returns: "BA"
// Please note that there are valid test cases with K = 0.
// 2)
// 5
// 8
// Returns: ""
// Five characters is too short for this value of K.
// 3)
// 10
// 12
// Returns: "BAABBABAAB"
// Please note that this is an example of a solution; other valid solutions will also be accepted.

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Our mission: Create the AB class

class AB{
public:
	// put our function here. Public method
	string txt; 	// Class can have a text value
	int length; 	// Length of string
	double numAB;	// Number of AB pairs in string
	// text = "ABB"; 	// Temp set our string value

	// Member Function declarations
	double countAB(void);
	void setString(string input);


	// string createString(int N, int K){
	// 	return "A";
	// 	cout << "Class working";
	// }

};

// Member Function Definitions
void AB::setString(string input){
	txt = input;
	// length = strlen(input);
	length = input.length();
}

double AB::countAB(void){
	// This function will count the AB pairs in a given string
	cout << "We opened the function \n";
	int count = 0; // Initialize counter
	for(int i=0; i<length-1;i++){
		// Start search for A at i = 0, iterative through string
		for(int j=i+1; j<=length-1; j++){
			// Start search for B at j = 1, iterate through
			// cout << i << txt[i];
			// cout << j << txt[j] << endl;
			// if (txt[i] == 'A'){cout<<"yes";}
			if (txt[i] == 'A' && txt[j] == 'B'){
				count++;
			}
		}
	}
	// We can save this value to the AB string object, but also return it as a value if desired
	numAB = count;
	// cout << "Number of Forward AB pairs is " << count << endl;
	return count;

}

int main()
{
	cout << "We will try to do a AB count \n\n";
	AB astring; // create special string object
	string string1 = "ABB"; // set our string value
	// string string1 = "BAABBABAAB";
	// int len1 = string1.length(); // calculate the length
	astring.setString(string1);
	// Try to count a length on AB String
	astring.countAB();

	// Try to retrieve the count value
	cout << "Counted size is " << astring.numAB << endl;

}