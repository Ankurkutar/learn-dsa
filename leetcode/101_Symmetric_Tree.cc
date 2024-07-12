#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper functions to create and print the tree
TreeNode* createNode(int value) {
    return new TreeNode(value);
}

class Solution {
    public:
     bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;
        return isMirror(root->left, root->right);
     }

     private:
        bool isMirror(TreeNode* left, TreeNode* right){
            if(left == nullptr && right == nullptr) return true;
            if(left == nullptr || right == nullptr) return false;

            return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }
};




void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    // Create a symmetric tree:
    //       1
    //      / \
    //     2   2
    //    / \ / \
    //   3  4 4  3
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);

    cout << "The tree is " << (result ? "symmetric" : "not symmetric") << endl;

    // Cleanup dynamic memory
    deleteTree(root);

    return 0;
}