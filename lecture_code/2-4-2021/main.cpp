#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void addToList(Node* head){
    // If we were in a class, we would make a temporary pointer
    // so that we don't have to update/change head
    // Node* temp = head;
    while(head->next != NULL){
        head = head->next;
    }
    // At the end of the while loop, we should be pointing to
    // the last node in the list
    Node* n = new Node;
    n->next = NULL;
    head->next = n;
}

void delList(Node* head){
    Node* deleter;
    while(head != NULL){
        // prepare the deleter
        deleter = head;
        // go to next node
        head = head->next;
        // commence deletion
        delete deleter;
    }
}

int main() {
    Node* head = new Node;
    head->next = NULL;
    addToList(head);
    addToList(head);
    delList(head);
}