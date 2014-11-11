#ifndef BTNode_H
#define BTNode_H

#include <string>
using namespace std;


class BTNode{
public:
	void insert(string key, string value);
	string getValue(string key) const;
	BTNode(string key, string value);
private:
	string key;
	string value;
	BTNode *left, *right;
	
};


class BinaryTree{

public:
	void insert(string key, string value);
	string getValue(string key) const;
	BinaryTree();
private:
	BTNode *root;
};	



#endif
