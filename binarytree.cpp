#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data) {
            this->data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* builtTree(node* root){
    int data;
    cout << "Enter the data: " <<endl;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<< "Enter data for inserting in left of: "<< data <<endl;
    root->left = builtTree(root->left); 
    cout<< "Enter data for inserting in right of: "<< data <<endl;
    root->right = builtTree(root->right);

    return root;
}

void levelorderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}
void builtfromlevelOrder(node* &root){
    queue<node*> q;
    int data;
    cout << "Enter root data: "<<endl;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<< "Enter left node data for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        
        if(leftdata!= -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<< "Enter right node data for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        
        if(rightdata!= -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }


}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    
    preorder(root->right);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main() {
    node* root = NULL;
    
    builtfromlevelOrder(root);
    levelorderTraversal(root);

    /*
    root = builtTree(root);
    levelorderTraversal(root);

    cout << "inorder traversal: "<<endl;
    inorder(root);

    cout << endl << "preorder traversal: "<<endl;
    preorder(root);

    cout << endl << "postorder traversal: "<<endl;
    postorder(root);
    */
   return 0;
}