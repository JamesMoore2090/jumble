// James Moore
// jumble.cpp
// start date 11/2/2014
// Davies

#include <cctype>
#include "BTNode.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
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
	// this creates the dictionary
	BinaryTree dictionary;
	// opens the  word file
	ifstream wordList;
	wordList.open("words.txt");
	vector<string> dict;
	string words;
	int count = 0;
	// puts wordList into words
	while(wordList){
	wordList >> words;
	dict.push_back(words);
	count++;
	}
	// now its time to shuffle the words
	random_shuffle(dict.begin(), dict.end());
	// this inserts the words into the BST
	for(int i= 0; i < count; i++){
//		dict[i] = toupper(dict[i]);
		dictionary.insert(dict[i], dict[i]);
	} 
	string line1, line2, line3, line4, question, answer;
	getline(file, line1);
	getline(file, line2);
	getline(file, line3);
	getline(file, line4);
	getline(file, question);
	getline(file, answer);
int length = 0;
	length = line1.length();
	length /= 2;
	string scrambled[length];
	for(int i =0; i < length; i++){
		scrambled[i] = line1[i];
	} 
	string answerWord;
	for(int j =0; j < 26; j++){
		scrambled[j] = scrambled[j] +1;
	cout << scrambled[j] << endl;
		answerWord = dictionary.getValue(scrambled);
	}
	// now read in the file
cout << "this program will do really cool stuff...." << endl;

}// end main

