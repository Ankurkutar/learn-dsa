#include<iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createNode(int value) {
    return new TreeNode(value);
}

class Solution{
    public:
        int maxDepth(TreeNode* root){
            if(root == nullptr){
                return 0;
            }
  
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            return max(leftDepth, rightDepth) + 1;
        }
};

// Function to insert nodes in level order for simplicity
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = createNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    Solution solution;

    // Example tree: [3, 9, 20, null, null, 15, 7]
    int arr[] = {3, 9, 20, -1, -1, 15, 7}; // -1 represents null nodes
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = insertLevelOrder(arr, root, 0, n);

    int depth = solution.maxDepth(root);
    cout << "The maximum depth of the tree is: " << depth << endl;

    return 0;
}