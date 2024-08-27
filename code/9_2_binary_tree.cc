// binary tree representation using array 
// binary tree representation using linked list

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void traverser(struct Node* p){
    if(p == nullptr){
        return;
    }

    cout << p->data << " ";
    traverser(p->left);
    traverser(p->right);
}

int main(){

    // Creating nodes using createNode function
    struct Node *p = createNode(10);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(30);
    struct Node *p3 = createNode(40);
    struct Node *p5 = createNode(50);

    p->left = p1;
    p->right = p2;

    cout << "Printing tree nodes in preorder traversal: " << endl;
    traverser(p);

    return 0;
}
