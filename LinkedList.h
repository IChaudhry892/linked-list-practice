#include "Node.h"

class LinkedList{
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();

    void insertAtHead(int val);
    void insertAtTail(int val);
    void selectionSortValue(); //ignore
    void selectionSortPointer1(); //ignore
    void selectionSortPointer2();
    void insertionSort();
    void insertionSort2(); //ignore
    bool deleteAtIndex(int index); //ignore
    void printList();
};