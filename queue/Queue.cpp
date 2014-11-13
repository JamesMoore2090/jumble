
#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue() {
    array = new int[40];
    capacity = 40;
    frontIndex = 0;
    endIndex = -1;
}

Queue::~Queue() {
    delete [] array;
}

int Queue::front() const {
    if (frontIndex % capacity == (endIndex + 1) % capacity) {
        throw "empty queue!";
    }
    return array[frontIndex];
}

int Queue::dequeue() {
    if (frontIndex == endIndex + 1) {
        throw "empty queue!";
    }
    int oldFront = frontIndex;
    frontIndex = (frontIndex + 1) % capacity;
    return array[oldFront];
}

void Queue::enqueue(int n) {
    if ((frontIndex % capacity) == (endIndex + 2)% capacity) {
        resize();
    }
    endIndex = (endIndex + 1) % capacity;
    array[endIndex] = n; 
}

bool Queue::isEmpty() const {
    if (frontIndex % capacity == (endIndex + 1) % capacity) {
        return true;
    } else {
        return false;
    }
}

void Queue::resize() {
    throw "Queue full!";   // stephen is lazy
    // Do the normal copy-into-a-larger-array-then-deallocate-the-old-one
    // thing.
}
