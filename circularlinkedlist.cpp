#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~node() {
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data: " << val <<endl;
    }
};

void insertaNode(node* &tail, int element,int data){
    if(tail == NULL){
        node* newone = new node(data);
        tail = newone;
        newone->next = newone;
    }
    else{
        node*current = tail;
        while(current->data != element){
            current = current->next;
        }

        node*temp = new node(data);
        temp->next = current->next;
        current->next= temp;
    }
}
void deleteNode(node* &tail,int value){
    //empty node
    if(tail == NULL){
        cout << "The node is already empty, check your node "<<endl;
        return;
    }
    else{
        // non empty
        node* prev = tail;
        node* current = tail->next;

        while(current ->data != value){
            prev = current;
            current = current->next;
        }
        
        prev->next = current->next;
        if(current == prev){
            tail = NULL;
        }
        else if(tail == current){
            tail = prev;
        }
        current->next = NULL;
        delete current; 
    }

}
void print(node*tail){
    node* temp = tail;
    if(tail == NULL) {
        cout << "List is empty" <<endl;
        return;
    }

    do{
        cout << tail->data << " ";
        tail = tail->next; 
    }while(tail != temp);
    cout << endl;
}

int main() {
    node* tail = NULL;
    insertaNode(tail,5,3);
    print(tail);
/*
    insertaNode(tail,3,5);
    print(tail);

    insertaNode(tail,5,7);
    print(tail);

    insertaNode(tail,5,6);
    print(tail);
    cout << "tail " << tail->data <<endl;
*/
    deleteNode(tail, 3);
    print(tail);
    

    return 0;
}   