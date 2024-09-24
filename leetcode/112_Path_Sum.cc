// path sum in binary tree 

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public: 
        bool hasPathSum(TreeNode* root, int targetSum){
            if(root == nullptr){
                return false;
            }

            if(root->left == nullptr && root->right == nullptr){
                return targetSum == root->val;
            }

            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        }
};

int main(){

// Example tree:
    //         5
    //        / \
    //       4   8
    //      /   / \
    //     11  13  4
    //    /  \      \
    //   7    2      1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution solution;
    int targetSum = 22;
    
    bool result = solution.hasPathSum(root, targetSum);
    cout << "Has path sum: " << (result ? "true" : "false") << endl;

    return 0;
}