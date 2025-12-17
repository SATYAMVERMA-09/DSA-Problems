#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        //constructor
        node(int data) {
            //cout << this-> data<<endl;  
            //cout << data <<endl <<endl <<endl;
            this -> data = data;
            this -> next = NULL;
        }

        //destructor
        ~node() {
            int val = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout << "memory is free for node: " << val <<endl;
        }
        
};

void insertAtHead(node* &head, int data) {
    //new node
    node*temp = new node(data);
    temp -> next = head;
    head = temp;
}
void insertAtTail(node* &tail, int data) {
    node*temp= new node(data);
    tail->next = temp;
    tail = tail->next;
}
void insertatPosition(node* &tail, node* &head, int position ,int data){

    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    node* temp = head;
    int cnt = 1;
    
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    node* nodetoInsert = new node(data);
    nodetoInsert -> next = temp ->next;
    temp->next = nodetoInsert;
}
void deleteNode(node* &tail,node* &head, int data){
    if(head->data == data){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    node* current = head;
    node* prev = NULL;

    
    while(current-> data != data ){
        prev = current;
        current = current-> next;
        
    }
    if(current->next == NULL) {
        tail = prev;
    }
    prev->next = current -> next;
    
    current -> next = NULL;
    delete current;

};
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

int main() {
    //dma, created a new node
    node* node1 = new node(10);
    //cout << node1 -> data <<endl;
    //cout << node1-> next << endl;
    
    // head pointed to node1
    node*head = node1;
    node*tail = node1;

    print(head);
    insertAtHead(head, 12);
    print(head);

 //   insertAtHead(head, 15);
 //   print(head);

    insertAtTail(tail,11);
    print(head); 

    insertatPosition(tail, head, 1, 69);
    print(head);

//    insertatPosition(tail, head, 6, 96);
//    print(head);
    deleteNode(tail,head, 11);
    print(head);
    cout << "head: " << head ->data <<endl;
    cout << "tail: " << tail ->data << endl;    
} 