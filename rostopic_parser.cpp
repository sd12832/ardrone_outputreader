#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

// Initialization Namespaces 
using namespace std;

int main(int argc, char* argv[]) {

	// Initialization Varibales 
	bool file ; 

	// ------------------------------------------------------------------------
	// 							Choose Input     							 //

	string inputType = "";

	cout << "============================================================";
	cout << endl; 
	cout << "Please input a number from the list below: " << endl << endl;
	cout << "1. File (Read from a file that has already been saved)" << endl;
	cout << "2. Command (Program reads from stream of the input command)"
					<< endl << endl;
	getline(cin, inputType);

	cout << endl; 
	cout << "============================================================";
	cout << endl; 
	
	// Choosing the mode of input through bool
	if (inputType[0] == '1') {
		file = 1;
	} else  {
		file = 0; 
	}
	
	// ------------------------------------------------------------------------
	// 							Get Input 									 //

	if (file != 1) {

		string input = ""; 

		cout << "Please input the topic would like to build the table from : ";
		cout << endl; 
		getline(cin, input);
		cout << "============================================================";
		cout << endl << "Executing the Command: " << endl << endl;
		cout << "rostopic echo " << input << endl << endl;
		cout << "============================================================";
		cout << endl; 

	} else {

		cout << "Please input the file would like to build the table from : ";
		cout << endl; 


	}

	// ------------------------------------------------------------------------
	// 							Execute Input 							     //

	sorter(); 

	// ------------------------------------------------------------------------
	// 							Select Output 							     //	

	cout << "============================================================";
	cout << endl;
	cout << "Please input a number from the list below: " << endl << endl;
	cout << "1. File (Output to a file that will be saved)" << endl;
	cout << "2. Terminal (Output to a )"
	getline(cin, input);

	return 0; 

}