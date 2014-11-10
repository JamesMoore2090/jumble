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

// functions protypes
string descramble(string &, const BinaryTree &);
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
		dictionary.insert(dict[i], dict[i]);
	}// end for 
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
	char scrambled[length];
	for(int i =0; i < length; i++){
		line1[i] = tolower(line1[i]);
		scrambled[i] = line1[i];
	} 
	answer = descramble(line1 , dictionary); 


	// now read in the file
cout << "this program will do really cool stuff...." << endl;

}// end main

// this function is used to de scramble the letters
// then it returns the descrambled word!
string descramble(string &scrambledWord, const BinaryTree &Dict){
	string answerWord;
	int length = scrambledWord.length();
	length /= 2;
	char word[length];
	for(int i = 0; i < length; i++){
		word[i] = scrambledWord[i];
		cout << word[i] << endl;
	}
	while(next_permutation(word, word+length-1)){
	cout << word << endl;
	}


}// end function
