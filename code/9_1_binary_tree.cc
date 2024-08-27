#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *right;
    struct Node *left;

    Node(int data) {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};


class BinaryTree{
    private:
        Node* root;

    public:
        BinaryTree(int data) {
            root = new Node(data);
        }

        Node* getRoot(){
            return root;
        }

        void insertLeft(Node *parent, int data){
            if(parent->left == nullptr){
                parent->left = new Node(data);
                cout<<"Node Inserted: "<<data<<" to the left of "<<parent->data<<endl;
            }else{
                cout << "Left child already exists." << endl;
            }
        }

        void insertRight(Node* parent, int data){
            if(parent->right == nullptr){
                parent->right = new Node(data);
                cout<<"Node Inserted: "<<data<<" to the right of "<<parent->data<<endl;
            }else{
                cout << "Right child already exists." << endl;
            }
        }

        void inOrdertraversal(Node* head){
            if(head == nullptr){
                return;
            }else{
                // cout<<"Element are: "<<endl;
                inOrdertraversal(head->left);
                cout<<head->data<<" ";
                inOrdertraversal(head->right);
            }
        }

        void preOrderTraverser(Node *node){
            if(node == nullptr){
                return;
            }else{
                cout<<node->data<<" ";
                preOrderTraverser(node->left);
                preOrderTraverser(node->right);
            }
        }

        void postOrderTraverser(Node *node){
            if(node == nullptr){
                return;
            }else{
                postOrderTraverser(node->left);
                postOrderTraverser(node->right);
                cout<<node->data<<" ";
            }
        }
};

int main(){
    BinaryTree tree(10);
    tree.insertLeft(tree.getRoot(),20);
    tree.insertRight(tree.getRoot(),20);

    tree.insertLeft(tree.getRoot()->left, 3);
    tree.insertRight(tree.getRoot()->left, 7);

    cout << "Inorder Traversal: "<<endl;
    tree.inOrdertraversal(tree.getRoot());
    cout << endl;

    cout << "Preorder Traversal: "<<endl;
    tree.preOrderTraverser(tree.getRoot());
    cout << endl;

    cout << "Postorder Traversal: "<<endl;
    tree.postOrderTraverser(tree.getRoot());
    cout << endl;

    return 0;

}