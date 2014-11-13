
#include"LL.h"
#include<iostream>
#include<cstdlib>

using namespace std;


std::string LLNode::getValue(std::string key) const {
    if (key == this->key) {
        return this->value;
    }
    if (next == NULL) {
        throw exception();
    }
    return next->getValue(key);
}

LLNode::LLNode(std::string key, std::string value) {
    next = NULL;
    this->key = key;
    this->value = value;
}


void LL::insert(std::string key, std::string value) {
    LLNode *tmp = head;
    head = new LLNode(key, value);
    head->next = tmp;
}

std::string LL::getValue(std::string key) const {
    LLNode *curr = head;
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }
    throw exception();
}

LL::LL() {
    head = NULL;
}

