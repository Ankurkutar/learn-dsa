// deletion in binary tree

// #include<stdio.h>
#include<iostream>
using namespace std;
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

struct node* search(struct node* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        return root;
    }else if(data < root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

struct node* searchIterative(struct node* root, int data){
    while(root != NULL){
        if(root->data == data){
            return root;
        }else if(data < root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
}

void insert(struct node* root, int data){
    struct node* prev = NULL;
    while(root != NULL){
        prev = root;
        if(data == root->data){
            cout<<"Duplicate Node: "<<endl;
            return;
        }else if(data < root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    if(data < prev->data){
        prev->left = newNode;
    }else{
        prev->right = newNode;
    }

    cout<<"Node Inserted: "<<data<<endl;
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

// deletion in binary tree 
struct node* deleteNode(struct node* root, int data){
    struct node* iPre = NULL;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    // search node to be deleted
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->left  = deleteNode(root->right, data);
    }else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }

    return root;
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

   
    inOrder(p);
    
    struct node *Deldata = deleteNode(p, 3);
    // cout<endl;
    cout<<"\ndeleted node is: "<<p->data<<endl;
    inOrder(p);
    return 0;
}
