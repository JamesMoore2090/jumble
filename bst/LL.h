
#ifndef LL_H
#define LL_H

#include<string>

class LLNode {

    public:
        void insert(std::string key, std::string value);
        std::string getValue(std::string key) const;
        LLNode(std::string key, std::string value);

    private:
        std::string key;
        std::string value;
        LLNode *next;

    friend class LL;
};

class LL {

    public:
        void insert(std::string key, std::string value);
        std::string getValue(std::string key) const;
        LL();

    private:
        LLNode *head;
};
#endif

