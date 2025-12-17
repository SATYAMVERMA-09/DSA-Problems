#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node* prev;
        node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
void insertathead(node* &head,int data){
    node*temp = new node(data);
    temp ->next = head;
    head ->prev = temp;
    head = temp;
}
void reverse(node* &head,node* &tail){
    tail = head;
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    while(current != NULL){
        next = current->next;
        current ->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    head = prev;
    
}


void print(node* &head, node* &tail) {
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << "Head: " << head->data << "  ,Tail: " << tail->data<<endl;
}
int main() {

    node* node1 = new node(10);
    node*head = node1;
    node*tail = node1;

    print(head,tail);

    insertathead(head, 9);
    print(head,tail);

    insertathead(head, 8);
    print(head,tail);

    insertathead(head, 7);
    print(head,tail);

    insertathead(head, 6);
    print(head,tail);

    insertathead(head, 5);
    print(head,tail);

    reverse(head,tail);
    print(head,tail);
}