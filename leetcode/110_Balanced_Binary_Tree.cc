#include<iostream>
#include<cmath>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution{
    public:
        bool isBalanced(TreeNode* root){
            return checkHeight(root) != -1;
        }
    private:
        int checkHeight(TreeNode* root){
            if(root == nullptr) return 0;

            int leftHeight = checkHeight(root->left);
            if(leftHeight == -1){
                return -1;
            }

            int rightHeight = checkHeight(root->right);
            if(rightHeight == -1){
                return -1;
            }

            if(abs(leftHeight - rightHeight) > 1){
                return -1;
            }

            return max(leftHeight, rightHeight) + 1;
        }


};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Helper function to print the tree (in-order traversal)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Example: Constructing a balanced binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(3);
    root->right->left = newNode(3);
    root->right->right = newNode(3);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(4);

    Solution solution;
    bool result = solution.isBalanced(root);
    cout << "The tree is " << (result ? "balanced" : "not balanced") << endl;

    return 0;
}
