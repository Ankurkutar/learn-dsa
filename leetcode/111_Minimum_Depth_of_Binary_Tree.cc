#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    int minDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        if(root->left == nullptr){
            return minDepth(root->right) + 1;
        }

        if(root->right == nullptr){
            return minDepth(root->left)+1;
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

        //      1
        //    /  \ 
        //   2    3
        //  / \   
        // 4  5   

    Solution solution;
    cout<<"Minimum Depth of Tree: "<<solution.minDepth(root);
    return 0;
}