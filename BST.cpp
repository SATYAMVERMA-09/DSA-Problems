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

node* insertIntoBST(node* root, int data){
    //base case
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}

void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    //base case
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
node* minVal(node* root){
    node* temp = root;
    
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}
node* maxVal(node* root){
    node* temp = root;
    
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

node* deletefromBST(node* root,int x){
    if(root == NULL){
        return root;
    }
    if(root->data == x){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left == NULL && root->right != NULL){
            node*temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right !=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            return deletefromBST(root->right,mini);
        }
        

    }
    else if(root->data > x){
        root->left = deletefromBST(root->left,x);
        return root;
    }
    else{
        root->right = deletefromBST(root->right,x);
        return root;
    }
    return root;
}

void levelorderTraversal(node* root){
    queue<node*> q;
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
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void traverseRight(node* root,vector<int>& ans){
    if(root == NULL || (root->right == NULL && root->left == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    
}
void traverseLeaf(node* root,vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->right,ans);
    traverseLeaf(root->left,ans);
}
void traverseLeft(node* root,vector<int>& ans){
    if(root == NULL || (root->right == NULL && root->left == NULL)){
        return;
    }

    
    if(root->left){
        traverseRight(root->left,ans);
    }
    else{
        traverseRight(root->right,ans);
    }
    ans.push_back(root->data);
}

void takeinput(node* &root){

    int data;
    cin >> data;
    
    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

int main() {
    node* root = NULL;

    cout << "Enter data to create BST: "<<endl;
    takeinput(root);
    levelorderTraversal(root);

    cout << endl << "preorder: "<<endl;
    preorder(root);

    cout << endl << "inorder: "<<endl;
    inorder(root);

    cout << endl << "postorder: "<<endl;
    postorder(root);

    vector<int>ans;
    ans.push_back(root->data);
    traverseRight(root->right, ans);
    traverseLeaf(root->right,ans);
    traverseLeaf(root->left,ans);
    traverseLeft(root->left,ans);
    cout << endl << " BOUNDARY : "<< endl; //20 8 22 4 12 10 14 -1
    for(int i =0;i<ans.size();i++){
        cout << ans[i]<<" ";
    }

    cout << "\n min val: "<< minVal(root)->data <<endl;
    cout << "max val: "<< maxVal(root)->data <<endl;

    root = deletefromBST(root,8);
    levelorderTraversal(root);
    return 0;
}