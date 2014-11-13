
#include"HT.h"
#include<iostream>

using namespace std;


int HT::hash(string key) const {
    long sum = 0;
    long factor = 1;
    for (int i=0; i<key.length(); i++) {
        sum += key[i] * factor;
        factor *= 25;
    }
    return (int) (sum % HT_SIZE);
}

int HT::openAddr(string key) const {
    long sum = 0;
    long factor = 1;
    for (int i=0; i<3; i++) {
        sum += key[i] * factor;
        factor *= 3;
    }
    return (int) (sum % HT_SIZE);
}

void HT::insert(string key, string value) {
    int h = hash(key);
    while (table[h] != NULL) {
        h = (h + openAddr(key)) % HT_SIZE;
    }
    table[h] = new KVPair(key,value);
}


string HT::getValue(string key) const {
    int h = hash(key);
    while (table[h] != NULL) {
        if (table[h]->key == key) {
            return table[h]->value;
        }
        h = (h + openAddr(key)) % HT_SIZE;
    }
    throw exception();
}

HT::HT() {
    table = new KVPair*[HT_SIZE];
    for (int i=0; i<HT_SIZE; i++) {
        table[i] = NULL;
    }
}

