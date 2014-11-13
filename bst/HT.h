
#ifndef HT_H
#define HT_H

#include<string>

using namespace std;


class KVPair {
    public:
        KVPair(string k, string v) { key = k; value = v; }
        string key;
        string value;
        
};

class HT {
    public:
        const static int HT_SIZE = 100000000;
        void insert(string key, string value);
        string getValue(string key) const;
        HT();

    private:
        int hash(string key) const;
        int openAddr(string key) const;
        KVPair **table;
};
#endif
