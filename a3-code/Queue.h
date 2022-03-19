#ifndef QUEUE_H
#define QUEUE_H

#include "WHLocation.h"

class Queue{

    class Node {
        public:
            WHLocation* data;
            Node*    next;
    };

    public:
        Queue();
        ~Queue();
        void addLast(WHLocation*);
        void peekFirst(WHLocation**) const;
        void popFirst(WHLocation**);
        bool isEmpty() const;
        void print() const;

    private:
        Node* head;
        Node* tail;
};

#endif