#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    //constructor
    node(int data) {
        this-> prev = NULL;
        this-> next = NULL;
        this->data = data;
    }
    //destructor
    ~node() {
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for node in data: "<< val <<endl;
    }
};

void print(node* &head) {
    node*temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getlen(node* &head) {
    node*temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertatHead(node* &head,node* &tail, int data){
    if(head == NULL) {
        node*temp = new node(data);
        head = temp;
        tail = temp;
    }
    else{
        node*temp = new node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertatTail(node*&head, node* &tail, int data){
    if(tail == NULL){
        node* temp = new node(data);
        tail = temp;
        head = temp;
    }
    else{
        node* temp = new node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}
void insertatPosition(node* &tail,node* &head, int position, int data){
    if(position == 1) {
        insertatHead(head,tail, data);
        return;
    }
    
    node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp-> next;
        cnt++;
    }

    if(temp->next == NULL){
        insertatTail(head,tail, data);
        return;
    }
    node* nodetoinsert = new node(data);
    nodetoinsert->next = temp ->next;
    nodetoinsert->prev = temp;
    temp -> next -> prev = nodetoinsert;
    temp->next = nodetoinsert;
}

void deleteNode(node* &tail,node* &head, int position){
    if(position == 1){
        node*temp = head;
        temp->next->prev = NULL;
        head = temp ->next;
        temp ->next = NULL;
        delete temp;
    }
    else{
        node* current = head;
        node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = current;
            current = current -> next;
            cnt++;
        }
        if(current->next == NULL){
            tail = prev;
        }
        prev->next = current ->next;
        current->prev = NULL;
        current ->next =NULL;
        delete current;
    }
}

int main() {
    
    node* head = NULL;
    node* tail = NULL;

    print(head);
    cout << getlen(head) <<endl;
    
    insertatPosition(tail, head, 1 , 100);
    print(head);

    insertatHead(head,tail, 11);
    print(head);
    cout << getlen(head) <<endl;

    insertatTail(head,tail, 25);
    print(head);

    deleteNode(tail,head,3);
    print(head);
    cout << "head " << head->data <<endl;
    cout << "tail " << tail->data <<endl;

    return 0;
}