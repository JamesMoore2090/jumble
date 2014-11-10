

#include "BTNode.h"
#include <iostream>
#include <string>
using namespace std;

// constructor for the BTNode class
BTNode::BTNode(string key, string value){
	left = right = NULL;
	this-> key = key;
	this->value = value;
}// end constructor

string BTNode::getValue(string key) const{
	if(key == this->key){
		return this->value;
	}// end if
	if(key < this->key){
		if(left == NULL){
			return "Null";
		}// end if
		else{
			return left->getValue(key);
		}// end else
	}// end if
	else{
		if(right == NULL){
			return "Null";
		}// end if
		else{
			return right->getValue(key);
		}// end else
	}// end else
}//end method

void BTNode::insert(string key, string value){
	if(key < this-> key){
		if(left == NULL){
			left = new BTNode(key, value);
		}// end if
		else {
			left->insert(key, value);
		}//end else
	}// end if
	else{	
		if(right == NULL){
			right = new BTNode(key, value);
		}// end if
		else{
			right->insert(key,value);
		}// end else
	}// end else
}// end method

// constructor for the BST class
BinaryTree::BinaryTree(){
	root = NULL;
}// end constructor

void BinaryTree::insert(string key, string value){
	if(root == NULL){
		root = new BTNode(key, value);
	}// end if
	else{
		root-> insert(key, value);
	}// end else
}// end insert method

string BinaryTree::getValue(string key) const{
	if(root != NULL){
		return root-> getValue(key);
	}// end if
	cout << "not here" << endl;
}// end getValue method
