#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* arrayToBinaryTree(vector<int>&arr){
    if(arr.empty()) return NULL;

    TreeNode *node = new TreeNode;
    node->val = arr[0];

}

int main(){
    vector<int>arr = {1,2,3,4,5,6, 7};
    TreeNode *root = arrayToBinaryTree(arr);

    cout << "Level order traversal of the binary tree: ";
    printLevelOrder(root);
    return 0;
}