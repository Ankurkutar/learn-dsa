#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public: 
        TreeNode* sortedArrayToBST(vector<int>& nums){
            return helper(nums, 0, nums.size()-1);
        }
    private:
        TreeNode* helper(vector<int>& nums, int left, int right){
            if(left > right) return nullptr;

            int mid = (left + right) / 2;
            TreeNode *node = new TreeNode(nums[mid]);
            node->left = helper(nums, left, mid-1);
            node->right = helper(nums, mid+1, right);
        }
};

// Function to print the BST in order (Utility function to test the result)
void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* bst = solution.sortedArrayToBST(nums);

    cout << "In-order traversal of the constructed BST: ";
    inOrderTraversal(bst);
    cout << endl;

    return 0;
}
