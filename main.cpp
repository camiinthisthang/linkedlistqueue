//
//  main.cpp
//  LinkedListPractice
//
//  Created by Camila Ramos on 8/24/21.
//  Copyright © 2021 Camila Ramos. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class linkedList{
private:
    node *head,*tail;
public:
    linkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(int n){ //add a new node to the back of the linked list
        node *tempNode = new node;
        tempNode->data = n;
        tempNode->next = NULL; //adding to the back, this will always happen;
        
        if (head == NULL){ // if this is the only node in the list
            head = tempNode;
            tail = tempNode;
        } else { //if there's already another node(s)
            tail->next = tempNode;
            tail=tail->next; //can this be done with temporaryNode instead of tail->next?
        }
        cout << "Node successfully added" << endl;
    }
    
    void dequeue(){
        if (head == NULL) { // if there are no nodes in the list
            cout << "there are no nodes to dequeue" << endl;
            return;
        } else {
            node *tempHolder = head; // the one we are going to pop off
            head = head->next; // move head over now that we've saved the old head
            delete (tempHolder);
            cout << "Successfully dequeued node" << endl;
        }
    }
    
    void printList(){
        if(head == NULL){
            cout << "The list is empty - nothing to print" << endl;
        }
        node *iterator;
        iterator = head;
        while(iterator != nullptr){
            cout << iterator->data << "-->";
            iterator = iterator->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    linkedList L;
    int menuSelection;
    while (menuSelection!=4){
        cout << "\n------MENU-------" << endl;
        cout << "1 - Enque (add node to the end of the list)" << endl;
        cout << "2 - Deque (pop the first node off the list)" << endl;
        cout << "3 - Print linked list" << endl;
        cout << "4 - Quit" << endl;
        cin >> menuSelection;
        switch (menuSelection) {
            case 1:
                int input;
                cout << "Enter the data for this node" << endl;
                cin >> input;
                L.enqueue(input);
                break;
            case 2:
                L.dequeue();
                break;
            case 3:
                L.printList();
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    }
}
