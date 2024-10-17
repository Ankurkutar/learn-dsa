#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right; 
    TreeNode() : val(0) , left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        void postOrder(TreeNode* root, vector<int>& result){
            if(root == nullptr) return;

            postOrder(root->left, result);
            postOrder(root->right, result);
            result.push_back(root->val);
        }
        
        vector<int> postOrderTraversal(TreeNode* root){
            vector<int>result;
            postOrder(root, result);
            return result;
        }
};


TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createTree();  // Create the tree from input
    vector<int> result = solution.postOrderTraversal(root);

    // Output the preorder traversal
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}