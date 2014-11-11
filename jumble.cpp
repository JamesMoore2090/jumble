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
	string unscrambled1, unscrambled2, unscrambled3, unscrambled4;
	getline(file, line1);
	getline(file, line2);
	getline(file, line3);
	getline(file, line4);
	getline(file, question);
	getline(file, answer);
	int length1 = line1.length();
	int length2 = line2.length();
	int length3 = line3.length();
	int length4 = line4.length();
	for(int i =0; i < length1; i++){
		line1[i] = tolower(line1[i]);
	}// end for
 	for(int i =0; i < length2; i++){
		line2[i] = tolower(line2[i]);
	}
	for(int i =0; i < length3; i++){
		line3[i] = tolower(line3[i]);
	}
	for(int i =0; i < length4; i++){
		line4[i] = tolower(line4[i]);
	}
	unscrambled1 = descramble(line1 , dictionary); 
	unscrambled2 = descramble(line2 , dictionary); 
	unscrambled3 = descramble(line3 , dictionary); 
	unscrambled4 = descramble(line4 , dictionary); 
	cout << unscrambled1 << endl << unscrambled2 << endl;
	cout << unscrambled3 << endl << unscrambled4 << endl;
	cout << question << endl;
	cout << answer << endl;

cout << "this program will do really cool stuff...." << endl;

}// end main

// this function is used to de scramble the letters
// then it returns the descrambled word!
string descramble(string &scrambledWord, const BinaryTree &Dict){
	string answerWord;
	//This is the dummy proof test. is the word passing through 
	//an actual word? if so return no need to go any furter
	answerWord = Dict.getValue(scrambledWord);
	if(answerWord != "Null"){
		return answerWord;
	}// end if
	//We now know that what is being passed through is not a real word.
	int length = scrambledWord.length();
	length = (length/ 2);
	char word[length];
	//changing the string in to a char so we can use the next_permutation
	for(int i = 0; i < length; i++){
		word[i] = scrambledWord[i];
	}// end for
	sort(word, word+length);
	//use the next_permutation and the dictionary to find the word!
	while(next_permutation(word, word+length)){
		answerWord = Dict.getValue(word);
		if(answerWord != "Null"){
			return answerWord;
		}// end if
	} // end while loop
}// end function
