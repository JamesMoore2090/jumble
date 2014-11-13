
#ifndef BST_H
#define BST_H

#include<string>

using namespace std;

class BSTNode {

    public:
        void insert(string key, string value);
        string getValue(string key) const;
        BSTNode(string key, string value);

    private:
        string key;
        string value;
        BSTNode *left, *right;
};

class BST {

    public:
        void insert(string key, string value);
        string getValue(string key) const;
        BST();

    private:
        BSTNode *root;
};
#endif
