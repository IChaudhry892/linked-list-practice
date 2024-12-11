#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList(){
    Node* temp;
    while (head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtHead(int val){
    Node* newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::insertAtTail(int val){
    Node* newNode = new Node(val);
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::selectionSortValue(){
    if (head == nullptr || head->next == nullptr) return;

    Node *head, *curNode, *minNode;
    for (head = head; head != nullptr; head = head->next){
        minNode = head;
        curNode = head->next;

        for (curNode = head->next; curNode != nullptr; curNode = curNode->next){
            if (curNode->data < minNode->data){
                minNode = curNode;
            }
        }

        if (minNode != head){
            int temp = head->data;
            head->data = minNode->data;
            minNode->data = temp;
        }
    }
}

void LinkedList::selectionSortPointer1(){ //hard
    if (head == nullptr || head->next == nullptr) return;

    Node* sorted = nullptr; //Marks the end of the sorted section of the list
    Node* head = head;

    while (head != nullptr){
        Node* minNode = head;
        Node* minPrev = nullptr;
        Node* curNode = head->next;
        Node* prevNode = head;

        //Finds the node w/smallest data
        while (curNode != nullptr){
            if (curNode->data < minNode->data){
                minNode = curNode;
                minPrev = prevNode;
            }
            prevNode = curNode;
            curNode = curNode->next;
        }

        // If minNode is not the current node head, move it to the front of the unsorted section
        if (minNode != head){
            // Unlink minNode from its current position
            if (minPrev != nullptr) {
                minPrev->next = minNode->next;
            }

            // Move minNode to the front of the unsorted section
            if (head == head){
                head = minNode;
            } else {
                sorted->next = minNode;
            }

            // Swap head and minNode
            minNode->next = head;
        }

        // Update sorted section
        sorted = minNode;
        head = minNode->next;
    }

    // Ensure tail is correct
    tail = sorted;
}

void LinkedList::selectionSortPointer2(){ //easy, working
    if (head == nullptr || head->next == nullptr) return;

    Node* sorted = nullptr;

    while (head != nullptr){
        Node* minNode = head;
        Node* minPrev = nullptr;
        Node* curNode = head;
        Node* prevNode = nullptr;

        //Finds the node w/smallest data
        while (curNode != nullptr){
            if (curNode->data < minNode->data){
                minNode = curNode;
                minPrev = prevNode;
            }
            prevNode = curNode;
            curNode = curNode->next;
        }

        //Remove minNode from the unsorted list
        if (minNode == head){
            head = head->next;
        } else{
            minPrev->next = minNode->next;
        }

        //Insert minNode at the beginning of the sorted list
        minNode->next = sorted; //the sorted node is like the head of the sorted list
        sorted = minNode;
    }

    //Sorted contains the sorted list but in reverse order
    //Reverse the sorted list
    Node* prevNode = nullptr;
    Node* curNode = sorted;
    while (curNode != nullptr){
        Node* sucNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = sucNode;
    }

    head = prevNode;

    tail = head;
    while (tail != nullptr && tail->next != nullptr){
        tail = tail->next;
    }
}

void LinkedList::insertionSort(){ //working
    if (head == nullptr || head->next == nullptr) return;

    Node* sorted = nullptr;
    Node* curNode = head;

    while (curNode != nullptr){
        Node* sucNode = curNode->next;

        if (sorted == nullptr || sorted->data >= curNode->data){
            curNode->next = sorted;
            sorted = curNode;
        } else{
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < curNode->data){
                temp = temp->next;
            }
            curNode->next = temp->next;
            temp->next = curNode;
        }
        curNode = sucNode;
    }
    head = sorted;

    tail = head;
    while (tail != nullptr && tail->next != nullptr){
        tail = tail->next;
    }
}

void LinkedList::insertionSort2(){
    if (head == nullptr || head->next == nullptr) return;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prevNode = head;
    Node* curNode = head->next;

    while (curNode != nullptr){
        if (curNode->data >= prevNode->data){
            prevNode = curNode;
            curNode = curNode->next;
            continue;
        }
        Node* temp = dummy;
        while (temp->next->data < curNode->data){
            temp = temp->next;
        }
        prevNode->next = curNode->next;
        curNode->next = temp->next;
        temp->next = curNode;
        curNode = prevNode->next;
    }
    Node* sortedHead = dummy->next;
    delete dummy;
    head = sortedHead;

    tail = head;
    while (tail != nullptr && tail->next != nullptr){
        tail = tail->next;
    }
}

bool LinkedList::deleteAtIndex(int index){
    if (head == nullptr){
        cout << "List is empty, can't delete" << endl;
        return false;
    }

    if (index == 0){
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr){
            tail = nullptr;
        }
        return true;
    }

    Node* curNode = head;
    int i = 0;
    while(curNode != nullptr && i < index - 1){
        curNode = curNode->next;
        i++;
    }

    if (curNode != nullptr && curNode->next != nullptr){
        Node* targetNode = curNode->next;

        if (targetNode == tail){
            tail = curNode;
        }

        curNode->next = targetNode->next;
        delete targetNode;
        return true;
    }

    cout << "Index out of bounds" << endl;
    return false;
}

void LinkedList::printList(){
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}