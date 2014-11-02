// James Moore
// jumble.cpp
// start date 11/2/2014
// Davies


#include "BTNode.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){

	if(argc != 2){
		cout << "Usage: jumble [jumbleTemplateFile]." << endl;
		return 1;
	}// end if
	ifstream file(argv[1]);
	if(!file){
		cout << "Could not open template file " << argv[1] << "!" << endl;
		return 2;
	}// end if

	// now read in the file
cout << "this program will do really cool stuff...." << endl;

}// end main
