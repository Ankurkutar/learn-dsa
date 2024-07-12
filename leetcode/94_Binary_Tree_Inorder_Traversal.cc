#include<iostream>
#include<vector>
using namespace std;

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
        vector<int> inorderTraversal(TreeNode* root){
            vector<int>ans;
            inorderHelper(root, ans);
            return ans;
        } 

        void inorderHelper(TreeNode* root, vector<int>&ans){
            if(root == nullptr) return;

            inorderHelper(root->left, ans);
            ans.push_back(root->val);
            inorderHelper(root->right, ans);
        }
};

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree: 
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the inorder traversal result
    cout << "Inorder Traversal: ";
    printVector(result);

    // Cleanup dynamic memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}