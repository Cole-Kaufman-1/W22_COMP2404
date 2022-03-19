#include <iostream>
#include "Queue.h"

Queue::Queue() : head(NULL), tail(NULL){}

Queue::~Queue() {
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

bool Queue::isEmpty() const {
    if (head == NULL) return true;
    return false;
}

void Queue::peekFirst(WHLocation** stu) const {
    if(isEmpty()){
        *stu = NULL;
        return;
    }
    *stu = head->data;
}

void Queue::popFirst(WHLocation** stu) {
    if(isEmpty()) {
        *stu = NULL;
        return;
    }
    Node* firstNode = head;
    *stu = head->data;
    head = head->next;
}

void Queue::addLast(WHLocation* stu){
    Node *newNode = new Node();
    newNode->data = stu;
    newNode->next = NULL;
    
    if(isEmpty()){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void Queue::print() const {
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    Node* currNode = head;
    
    while(currNode!=NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}