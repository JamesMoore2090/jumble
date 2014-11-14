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
string missingLetter(const string &, const string&);
string AnswerDescrambler(string &, const BinaryTree&);
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
	// create a vector!!!
	vector<string> dict;
	string words;
	int count = 0;
	// puts wordList into words
	while(wordList){
	wordList >> words;
	// this make all the words uppercase
	for(int i = 0; i < words.length(); i++){
		words[i] = toupper(words[i]);
	}
	dict.push_back(words);
	count++;
	}
	// now its time to shuffle the words
	random_shuffle(dict.begin(), dict.end());
	// this inserts the words into the BST
	for(int i= 0; i < count; i++){
		dictionary.insert(dict[i], dict[i]);
	}// end for 
	// these are most of what the varibles for the next few lines
	string line1, line2, line3, line4, question, answer, finalAnswer;
	string unscrambled1, unscrambled2, unscrambled3, unscrambled4;
	// get the info from the file!
	getline(file, line1);
	getline(file, line2);
	getline(file, line3);
	getline(file, line4);
	getline(file, question);
	getline(file, answer, '_');
	// send the words the the descramble fuction
	unscrambled1 = descramble(line1 , dictionary); 
	unscrambled2 = descramble(line2 , dictionary); 
	unscrambled3 = descramble(line3 , dictionary); 
	unscrambled4 = descramble(line4 , dictionary); 
	// Need more varibles and then run the missing letter function
	string Letter1, Letter2, Letter3, Letter4;
	Letter1 = missingLetter(line1 , unscrambled1);
	Letter2 = missingLetter(line2 , unscrambled2);
	Letter3 = missingLetter(line3 , unscrambled3);
	Letter4 = missingLetter(line4 , unscrambled4);
	// now Add the strings together then run the AnswerDescrambled function
	string scrambledLetters = Letter1 + Letter2 + Letter3 + Letter4;
	finalAnswer = AnswerDescrambler(scrambledLetters, dictionary);
	// now print out the final!!!
	cout << unscrambled1 << endl << unscrambled2 << endl;
	cout << unscrambled3 << endl << unscrambled4 << endl;
	cout << question << endl;
	int fvalue = 1;
	for(int i = 0; i < answer.length(); i++){
		if(answer[i] == 34){
			cout << answer << " " << finalAnswer << " \" " << endl;
			fvalue = 0;
		} // end if
	}// end for
	if(fvalue != 0){
	cout << answer << " " << finalAnswer << endl;
	}

}// end main

// this function is used to de scramble the letters
// then it returns the descrambled word!
string descramble(string &scrambledWord, const BinaryTree &Dict){
	string answerWord;
	// check to see of what is being passed is a real word
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
	// check to see of what is being passed is a real word
	answerWord = Dict.getValue(word);
	if(answerWord != "Null"){
		return answerWord;
	}// end if
	word[length] = '\0';
	sort(word, word+length);
	// because we have sort the letter in aplh order we have to test to see if it is the dictionary.
	answerWord = Dict.getValue(word);
	if(answerWord != "Null"){
		return answerWord;
	}// end if
	//use the next_permutation and the dictionary to find the word!
	while(next_permutation(word, word+length)){
		answerWord = Dict.getValue(word);
		if(answerWord != "Null"){
			return answerWord;
		}// end if
	} // end while loop
}// end function


// this functions is used to find which position of the missing letters and return them.
// then you will "add all the letters up" in a string then descramble the word!
string missingLetter(const string & scrambledLine, const string &word){
	//lets create a char array to hold letters to return
	char letters[100];
	int length = scrambledLine.length();
	// now use half the length to create a new array
	int halfLength = (length/2);
	char Line[halfLength];
	int a = halfLength+1;
	// lets copy the orginal to scrambledLine to a char array half the size
	for(int j = 0; j < halfLength; j++){
		Line[j] = scrambledLine[a];
		a++;
	}
	//lets find where all the "O" then compare where they are in the word then copy
	// copy the letter at index "O" to the letters array
	int n = 0;
	for(int i = 0; i < halfLength; i++){
		if(Line[i] == 'O'){
			letters[n] = word[i];
			n++;
		}// end if	 
	}// end for
	// at the end of letters[n] put a null treminal then return
	letters[n] = '\0';
	return string(letters);
}// end function


// This shall de scramble the answer!!
string AnswerDescrambler(string & word, const BinaryTree & Dict){
	string answerWord;
	// get length
	int length = word.length();
	// the dummy check. 
	answerWord = Dict.getValue(word);
	if(answerWord != "Null"){
		return answerWord;
	}// end if
	// sort the word so we get all the permutation
	sort(word.begin(), word.end());
	// Because we sorted the letters now check to  see if it in the dictionary.
	answerWord = Dict.getValue(word);
	if(answerWord != "Null"){
		return answerWord;
	}// end if
	
	//use the next_permutation and the dictionary to find the word!
	while(next_permutation(word.begin(), word.end())){
		answerWord = Dict.getValue(word);
		if(answerWord != "Null"){
			return answerWord;
		}// end if
	}// end while
}// end function
