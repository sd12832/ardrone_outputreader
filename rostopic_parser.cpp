#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <vector>

// Initialization Namespaces 
using namespace std;

// Function to get the terminal output
std::stringstream getStdoutFromCommand(string cmd) { 

	std::stringstream emptyOutput; 
	emptyOutput.str("");
	return emptyOutput; 

}

// Function to make the tables
string sorter(string input) {

	return "nothing"; 
}

// Main
int main(int argc, char* argv[]) {

	// Initialization Varibales 
	bool file; 
	bool oFile; 

	// ------------------------------------------------------------------------
	// 							Choose Input     							 //

	string inputType = "";

	cout << "============================================================"
									<< endl; 
	cout << "Please input a number from the list below: " << endl << endl;
	cout << "1. File (Read from a file that has already been saved)" << endl;
	cout << "2. Command (Program reads from stream of the input command)"
					<< endl << endl;
	getline(cin, inputType);

	cout << endl; 
	cout << "============================================================"
									<< endl; 
	
	// Choosing the mode of input through bool
	if (inputType[0] == '1') {
		file = 1;
	} else  {
		file = 0; 
	}
	
	// ------------------------------------------------------------------------
	// 							Get Input 									 //

	std::stringstream output;

	if (file != 1) {

		// If Command Line 

		string input = "";
 
		/*-------------------------------------------------------------------*/

		cout << "Please input the topic would like to build the table from : "
									<< endl; 
		getline(cin, input);
		cout << endl << "Executing the Command: " << endl << endl;
		cout << "rostopic echo " << input << endl << endl;
		cout << "============================================================"
									<< endl; 

		/*-------------------------------------------------------------------*/

		string command = "rostopic echo " + input; 
		output = getStdoutFromCommand(command);

	} else {

		// If Directory

		string directory; 

		cout << "Please input the file directory from where the table needs to" 
					<< endl << "be built from : "<< endl; 
		getline(cin, directory);
		cout << "Reading from directory: " << file; 
		cout << "============================================================"
									<< endl; 
		
		std::ifstream t(directory);
		output << t.rdbuf();

	}

	// ------------------------------------------------------------------------
	// 							Execute Input 							     //

	string table; 
	if (!(output.rdbuf()->in_avail() == 0)) {
		table = sorter(output.str()); 
	}
	
	// ------------------------------------------------------------------------
	// 							Select Output 							     //	

	string outputType = "";

	cout << "============================================================";
	cout << endl;
	cout << "Please input a number from the list below: " << endl << endl;
	cout << "1. File (Output to a file that will be saved)" << endl;
	cout << "2. Terminal (Output to the command line)" << endl;
	getline(cin, outputType); 
	cout << endl; 

	// Choosing the mode of output through bool
	if (outputType[0] == '1') {
		oFile = 1;
	} else  {
		oFile = 0; 
	}

	if (oFile != 1) {

		// If Command Line 
 
		/*-------------------------------------------------------------------*/

		cout << "Currently Printing Results of Table Down Below: " << endl;
		cout << table;
 
		/*-------------------------------------------------------------------*/

	} else {

		// If Directory

		string outputdirectory = "";

		cout << "Please input the file directory where the table needs to be " 
						<< "written to : "<< endl; 
		getline(cin, outputdirectory);
		cout << "Writing to file: " << outputdirectory << endl; 

		std::ofstream out(outputdirectory);
		out << table; 

		cout << "============================================================"
									<< endl; 

	}

	// End of Main 
	return 0; 

}