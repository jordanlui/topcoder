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
#include <bitset>
#include <cmath>

using namespace std;

// Runtime compile parameters
const int bitlength = 50; // Max length of string as stated in problem definition

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
	string createString(int N, int K);
	string makeAB(int N);


	// string createString(int N, int K){
	// 	return "A";
	// 	cout << "Class working";
	// }

};

// Member Function Definitions

string AB::makeAB(int num){
	// Accept a digit and make the corresponding binary AB string
	// Writes this string into 
	bitset<bitlength> b1(num);
	string result =  b1.to_string('A','B');
	AB::setString(result);
	return result;
}

string AB::createString(int N, int K){
	// Routine to generate AB strings within parameters N and K, test them, and report any successful ones as output
	string string_found; // Create a blank string, which we output if we are not successful
	string string_try; // Blank string we try to search with
	int maxiter = pow(2,N); // Max number of iterations
	int count_AB;

	for (int i=1; i <= maxiter, i++;){
		
		string_try = AB::makeAB(i);
		// Now count the the AB pair in this string and compare
		AB::setString(string_try);
		count_AB = AB::countAB();
		if(count_AB == K){
			string_found = string_try;
			cout << "Found one " << string_found << endl;
			AB::setString(string_found);
			return string_found;
			break;
		}
	}

}
void AB::setString(string input){
	txt = input;
	// length = strlen(input);
	length = input.length();
}

double AB::countAB(void){
	// This function will count the AB pairs in a given string
	// cout << "We opened the function \n";
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
	cout << "We will do an AB count \n\n";

	// Inputs to our activities
	string string1 = "ABB"; // set our string value
	// string string1 = "BAABBABAAB";
	// int len1 = string1.length(); // calculate the length

	// Work with our AB object
	AB astring; // create special string object
	astring.setString(string1);
	// Try to count a length on AB String
	astring.countAB();

	// Retrieve the count value
	cout << "Counted size is " << astring.numAB << endl;

	// Create a string 
	// recreate ABB. N=3, K=2
	astring.makeAB(617);
	// note we will always get a 50 digit number. Slice the number, and replace the value
	cout << astring.txt.substr(40,10);
	astring.setString(astring.txt.substr(40,10));
	astring.countAB();
	cout << "String is " << astring.txt << endl;
	cout << "Counted size is " << astring.numAB << endl;
	// Now let's try to generate a string inside the class
	// astring.createString(3,2);
	

}