
#include"BST.h"
#include"LL.h"
#include"HT.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<sys/time.h>

using namespace std;

double numMicros(struct timeval t1, struct timeval t2) {
    return ((t2.tv_sec * 1000000 + t2.tv_usec) -
            (t1.tv_sec * 1000000 + t1.tv_usec)) / 1000000.0;
}

int main(int argc, char *argv[]) {

    BST testBST;
    LL testLL;
    HT testHT;

    cout << "Building BST and LL and HT..." << endl;

    char keyS[100];

    struct timeval start, finishBuilding, finishSearching;
    gettimeofday(&start,NULL);

    for (int i=0; i<2000000; i++) {

        int key = rand();
        sprintf(keyS,"%d",key);

        try {
            testBST.insert(keyS, keyS);
//            testLL.insert(keyS, keyS);
//            testHT.insert(keyS, keyS);
        } catch (char const * str) {
            cout << "caught: " << str << endl;
            return 1;
        }

        if (i % 100000 == 0) {
            cout << "Key #" << i << " is: " << keyS << endl;
        }
    }
    gettimeofday(&finishBuilding,NULL);

//    cout << "Press ENTER to search the BST for 1000 elements.";
//    cin.get();
    string value;

    for (int i=0; i<1000; i++) {
        int r = rand();
        char searchS[100]; 
        sprintf(searchS,"%d",r);
        if (i%10 == 0) {
            cout << i << " Searching for " << r << "..." << endl;
        }
        try {
            value = testBST.getValue(searchS);
            // Try using testLL here instead and see the diff!
            // value = testLL.getValue(searchS);
            cout << "Found " << value << "!" << endl;    
        } catch (exception & e) {
        }
    }
    gettimeofday(&finishSearching,NULL);

    cout << numMicros(start, finishBuilding) << " secs to build." << endl;
    cout << numMicros(finishBuilding, finishSearching) << " secs to search."
        << endl;

}
