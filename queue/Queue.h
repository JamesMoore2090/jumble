
#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    public:
        Queue();
        ~Queue();
        int front() const;
        bool isEmpty() const;
        int dequeue();
        void enqueue(int n);
    private:
        void resize();
        int *array;
        int frontIndex, endIndex;
        int capacity;
};

#endif
