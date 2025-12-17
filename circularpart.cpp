#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        node* next;
        int data;

        node(int data){
            this->data = data;
            this-> next = NULL;
        }

};

void insertanode(node* &tail, int element,int data) {
    if(tail==NULL){
        node* newnode = new node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        node* current = tail;
        while(current->data != element){
            current = current->next;
        }
        node* temp = new node(data);
        temp->next = current -> next;
        current->next = temp;
    }
}

void print(node* tail){
    node* temp = tail;
    if(temp == NULL){
        cout<< "List is empty" << endl;
        return;
    }
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(tail!=temp);
    cout << endl;
}
void separate(node* &tail, int sep){
    int count = 1;
    node* temp = tail; 
    while(count < sep){
        temp = temp->next;
        count++;
    }
    node* newnode = temp->next;
    node* temp1 = newnode;
    temp -> next = tail;
    while(temp1->next != tail){
        temp1 = temp1->next;
    }
    temp1 ->next = newnode;
    print(tail);
    print(newnode);
}

int main() {
    node* tail = NULL;
    insertanode(tail,1,1);
    //print(tail);

    insertanode(tail,1,2);
    //print(tail);

    insertanode(tail,2,3);
    //print(tail);

    insertanode(tail,3,4);
    //print(tail);

    insertanode(tail,4,5);
    print(tail);

    separate(tail,3);
}