#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

// Initialization Namespaces 
using namespace std;

// Function to get the terminal output
string getStdoutFromCommand(string cmd) {

	string data;
	FILE * stream;
	char buffer[];
	cmd.append(" 2>&1");

	stream = popen(cmd.c_str(), "r");
	char chk; 

	if (stream) {
		cout << endl << "Press the 'C' Key to Stop Recording Data"; 
		while ((!feof(stream)) && ((chk != 'C') || (chk != 'c')) {
			chk = getch()
			if (fgets(buffer, max_buffer, stream) != NULL) {
				data.append(buffer);
			}
		}
		pclose(stream);
	}

	return data;

}

// Function to make the tables
string sorter(string input) {

	return "nothing"; 
}

// Main
int main(int argc, char* argv[]) {

	// Initialization Varibales 
	bool file; 

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

	string output = ""; 

	if (file != 1) {

		// If Command Line 

		string input = "";
 
		/*-------------------------------------------------------------------*/

		cout << "Please input the topic would like to build the table from : ";
		cout << endl; 
		getline(cin, input);
		cout << endl << "Executing the Command: " << endl << endl;
		cout << "rostopic echo " << input << endl << endl;
		cout << "============================================================";
		cout << endl; 

		/*-------------------------------------------------------------------*/

		string command = "rostopic echo " + input  
		output = getStdoutFromCommand(command);

	} else {

		// If Directory

		string directory; 

		cout << "Please input the file would like to build the table from : ";
		cout << endl; 
		getline(cin, directory);
		cout << "============================================================";

	}

	// ------------------------------------------------------------------------
	// 							Execute Input 							     //

	string table; 
	if (!(output.empty())) {
		table = sorter(output); 
	}
	
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