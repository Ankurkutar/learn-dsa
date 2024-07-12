#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createNode(int value) {
    return new TreeNode(value);
}


class Solution{
    public:
        bool isSameTree(TreeNode* p, TreeNode* q){

            if(p == nullptr && q == nullptr) return true;
            if(p == nullptr || q == nullptr) return false;

            return (p->val == q->val) && (p->left, q->left) && (p->right, q->right);
        }
}
;



int main() {
    // Create two sample trees
    // Tree 1:    1
    //           / \
    //          2   3
    TreeNode* p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    // Tree 2:    1
    //           / \
    //          2   3
    TreeNode* q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    Solution solution;
    bool result = solution.isSameTree(p, q);

    cout << "The trees are " << (result ? "the same" : "not the same") << endl;

    // Cleanup dynamic memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}