
#include"BST.h"
#include<iostream>

using namespace std;

void BSTNode::insert(std::string key, std::string value) {
    if (key < this->key) {
        if (left == NULL) {
            left = new BSTNode(key, value);
        } else {
            left->insert(key, value);
        }
    } else {
        if (right == NULL) {
            right = new BSTNode(key, value);
        } else {
            right->insert(key, value);
        }
    }
}


std::string BSTNode::getValue(std::string key) const {
    if (key == this->key) {
        return this->value;
    }
    if (key < this->key) {
        if (left == NULL) {
            throw exception();
        } else {
            return left->getValue(key);
        }
    } else {
        if (right == NULL) {
            throw exception();
        } else {
            return right->getValue(key);
        }
    }
}

BSTNode::BSTNode(std::string key, std::string value) {
    left = right = NULL;
    this->key = key;
    this->value = value;
}


void BST::insert(std::string key, std::string value) {
    if (root == NULL) {
        root = new BSTNode(key, value);
    } else {
        root->insert(key,value);
    }
}


std::string BST::getValue(std::string key) const {
    if (root != NULL) {
        return root->getValue(key);
    }
    throw exception();
}

BST::BST() {
    root = NULL;
}

