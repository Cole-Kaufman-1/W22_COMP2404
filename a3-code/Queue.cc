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

void Queue::peekFirst(WHLocation** loc) const {
    if(isEmpty()){
        *loc = NULL;
        return;
    }
    *loc = head->data;
}

void Queue::popFirst(WHLocation** loc) {
    if(isEmpty()) {
        *loc = NULL;
        return;
    }
    Node* firstNode = head;
    if (firstNode->next != NULL){
        *loc = firstNode->data;
        firstNode = firstNode->next;
        delete head;
        head = firstNode;
    }
    else{
        *loc = head->data;
        delete head;
        head = NULL;
        tail = NULL;
    }
}

void Queue::addLast(WHLocation* loc){
    Node *newNode = new Node();
    newNode->data = loc;
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