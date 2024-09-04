// complete opertion of binary tree through javaTpoint
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(Node *root){
    if(root == NULL){
        // cout<<"Tree is Empty: "<<endl;
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root){
    if(root == NULL){
        // cout<<"Tree is Empty: "<<endl;
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root){
    if(root == NULL){
        // cout<<"Tree is Empty: "<<endl;
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

Node* insertNode(Node *root, int data){
    if(root == NULL){
        root = createNode(data);
        cout<<"Node Inserted: "<<data<<endl;
        return root;
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data){
    if(root == NULL){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        // Node found
        // Case 1: No child or one child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Two children
        Node* temp = findMin(root->right); // Get the inorder successor (smallest in the right subtree)
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void searchElement(Node* root, int data){
    if(root == NULL){
        cout << "Element not found." << endl;
        return;
    }

    if(data == root->data){
        cout << "Element found: " << data << endl;
        return;
    }
    else if(data < root->data){
        searchElement(root->left, data);
    }else{
        searchElement(root->right,data);
    }
    
}

Node* findMax(Node* root){
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root; 
}

bool checkIfBSTHelper(Node* root, Node* minNode, Node* maxNode){
    if(root == nullptr){
        return true;
    }

    if((minNode != nullptr && root->data <= minNode->data) || (maxNode != nullptr && root->data >= maxNode->data)){
        return false;
    }

    return checkIfBSTHelper(root->left, minNode, root) && checkIfBSTHelper(root->right, root, maxNode);
}

bool checkIfBST(Node* root){
    return checkIfBSTHelper(root, nullptr, nullptr);
}

int getHeight(Node* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = NULL; 
    Node *temp = NULL; 
    int choice, data;
    while (1)
    {
        cout << "\n\n********* Binary Tree Operations Menu *********\n";
        cout << "Choose one option from the following list ...\n";
        cout << "===============================================\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search for an Element\n";
        cout << "4. Find Minimum Value\n";
        cout << "5. Find Maximum Value\n";
        cout << "6. Get Tree Height\n";
        cout << "7. Preorder Traversal\n";
        cout << "8. Inorder Traversal\n";
        cout << "9. Postorder Traversal\n";
        cout << "10. Level Order Traversal\n";
        cout << "11. Check if BST\n";
        cout << "12. Find Lowest Common Ancestor\n";
        cout << "13. Find Successor\n";
        cout << "14. Find Predecessor\n";
        cout << "15. Delete Tree\n";
        cout << "16. Mirror Tree\n";
        cout << "17. Print All Paths\n";
        cout << "18. Display Tree in all Order\n";
        cout << "19. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter Element: ";
            cin>>data;
            root = insertNode(root, data);
            break;
        case 2:
            cout<<"Enter Element Which you want to delete: ";
            cin>>data;
            root = deleteNode(root, data);
            break;
        case 3:
            cout<<"Enter Element Which you want to search: ";
            cin>>data;
            searchElement(root, data);
            break;
        case 4:
            temp = findMin(root);
            cout << "Minimum Node is: " << temp->data;
            break;
        case 5:
            temp = findMax(root);
            cout << "Maximum Node is: " << temp->data;
            break;
        case 6:
            // getHeight(root);
            cout << "The height of the tree is: " << getHeight(root) << endl;
            break;
        case 7:
            cout<<"Pre Order Traversal is: "<<endl;
            preOrderTraversal(root);
            break;
        case 8:
            cout<<"In Order Traversal is: "<<endl;
            inOrderTraversal(root);
            break;
        case 9:
            cout<<"Post Order Traversal is: "<<endl;
            postOrderTraversal(root);
            break;
        // case 10:
        //     levelOrderTraversal();
        //     break;
        case 11:
            if (checkIfBST(root)) {
                cout << "The tree is a BST" << endl;
            } else {
                cout << "The tree is not a BST" << endl;
            }
            break;
        // case 12:
        //     findLowestCommonAncestor();
        //     break;
        // case 13:
        //     findSuccessor();
        //     break;
        // case 14:
        //     findPredecessor();
        //     break;
        // case 15:
        //     deleteTree();
        //     break;
        // case 16:
        //     mirrorTree();
        //     break;
        // case 17:
        //     printAllPaths();
        //     break;
        case 18:
            cout<<"Pre Order Traversal is: "<<endl;
            preOrderTraversal(root);
            cout<<"\nIn Order Traversal is: "<<endl;
            inOrderTraversal(root);
            cout<<"\nPost Order Traversal is: "<<endl;
            postOrderTraversal(root);
            break;
        case 19:
            exit(0);
            break;
        default:
            cout << "Enter a valid choice: ";
        };
    }

    return 0;
}
