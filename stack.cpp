#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int data){
            this -> data = data;
            this->next =NULL;
        }
};

class stack{
    private:
        node* top;
    public:
        stack(){
            top = NULL;
        }
        void push(int data){
            node* newNode = new node(data);
            newNode->next = top;
            top = newNode;

        }
        void pop() {
            if(isEmpty){
                cout << "Stack is empty"<<endl;
                return;
            }
            node* temp = top;
            top = top ->next;
            delete temp;

        }
        int peek(){  
            if(isEmpty()){
                cout << "stack is empty"<<endl;
                return -1;
            }
            else{
                return top->data;
            }
        }
        bool isEmpty() {
            if(top == NULL) return true;
            else return false;
        }
        void display(){

        }
};

int main() {

}