#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList list;
    int choice, value;

    while (true){
        cout << "1. Insert Data at Head" << endl;
        cout << "2. Insert Data at Tail" << endl;
        cout << "3. Print List" << endl;
        cout << "4. Sort List using Selection Sort" << endl;
        cout << "5. Sort List using Insertion Sort" << endl;
        cout << "6. Delete Node at Specified Index" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtTail(value);
                break;
            case 3:
                cout << "Current list: ";
                list.printList();
                break;
            case 4:
                cout << "Sorting list using Selection Sort." << endl;
                list.selectionSortPointer2();
                cout << "Sorted Llist: ";
                list.printList();
                break;
            case 5:
                cout << "Sorting list using Insertion Sort." << endl;
                list.insertionSort();
                cout << "Sorted list: ";
                list.printList();
                break;
            case 6:
                cout << "Enter index of node to delete: ";
                cin >> value;
                list.deleteAtIndex(value);
                cout << "Updated list: ";
                list.printList();
                break;
            case 7:
                cout << "Exiting program, bye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}