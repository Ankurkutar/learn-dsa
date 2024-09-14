// complete operation of binary tree 
#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = data;
    return newNode;
}

void preOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

Node* insertNode(Node* root, int data){
    if(root == nullptr){
        root = createNode(data);
        cout<<"Node Inserted: "<<root->data<<endl;
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
    while (root->left != NULL)   
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int data){
    if(root == nullptr){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        // Node found here 
        // Case 1: No child or one child
        Node* temp = nullptr;
        if(root->left == nullptr){
            temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Two children
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    Node *root = NULL; 
    Node *temp = NULL; 
    int choice, data, n1, n2;
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
        cout << "16. Delete Particular Node\n";
        cout << "17. Print All Paths\n";
        cout << "18. Display Tree in all Order\n";
        cout << "19. Mirror Tree\n";
        cout << "20. Exit\n";
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
                // searchElement(root, data);
                break;
            case 4:
                // temp = findMin(root);
                cout << "Minimum Node is: " << temp->data;
                break;
            case 5:
                // temp = findMax(root);
                cout << "Maximum Node is: " << temp->data;
                break;
            case 6:
                // cout << "The height of the tree is: " << getHeight(root) << endl;
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
            case 10:
                // levelOrderTraversal(root);
                break;
            case 11:
                // if (checkIfBST(root)) {
                //     cout << "The tree is a BST" << endl;
                // } else {
                //     cout << "The tree is not a BST" << endl;
                // }
                // break;
            case 12:
                // cout << "Enter first value: ";
                // cin >> n1;
                // cout << "Enter second value: ";
                // cin >> n2;
                // temp = findLowestCommonAncestor(root, n1, n2);

                // if (temp != nullptr)
                //     cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << temp->data << endl;
                // else
                //     cout << "No common ancestor found." << endl;
                // break;
            case 13:
                // cout << "Enter Element for which you want to find the successor: ";
                // cin >> data;

                // // Find the node with the given data
                // temp = searchNode(root, data);
                // if (temp == nullptr) {
                //     cout << "Element not found in the tree!" << endl;
                //     break;
                // }

                // // Find the successor of the found node
                // temp = findSuccessor(root, temp);  // Use temp to find the successor

                // if (temp != nullptr) {
                //     cout << "The successor of " << data << " is: " << temp->data << endl;
                // } else {
                //     cout << "No successor found for " << data << endl;
                // }
                // break;
            case 14:
                // cout << "Enter Element for which you want to find the successor: ";
                // cin >> data;

                // // Find the node with the given data
                // temp = searchNode(root, data);
                // if (temp == nullptr) {
                //     cout << "Element not found in the tree!" << endl;
                //     break;
                // }
                // temp = findPredecessor(root, temp);
                // if (temp != nullptr) {
                //     cout << "The Predecessor of " << data << " is: " << temp->data << endl;
                // } else {
                //     cout << "No Predecessor found for " << data << endl;
                // }
                // break;
            case 15:
                // deleteTree(root);
                // root = NULL;
                // break;
            case 16:
                // cout << "Enter Element to delete: ";
                // cin >> data;
                // root = deleteTargetNode(root, data);
                // cout << "Node " << data << " deleted successfully." << endl;
                // break;
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
                // mirrorTree(root);
                // inOrderTraversal(root);
                break;
            case 20:
                exit(0);
                break;
            default:
                cout << "Enter a valid choice: ";
        };
    }

    return 0;
}
