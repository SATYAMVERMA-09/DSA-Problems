#include<bits/stdc++.h>
using namespace std;


class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
node* buildTree(node* root){
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if(data == -1){
        return NULL;
    }
    root = new node(data);

    cout << "enter data for inserting in left of: "<< data<<endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in right of: "<< data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelorderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << temp->data <<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    levelorderTraversal(root);
}