#include <iostream>
#include <vector>

struct TreeNode {
    // properties
    int val;
    TreeNode *left;
    TreeNode *right;

    // 3 possible constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        // case 1: both null --> symmetric
        if (left == nullptr && right == nullptr) return true;

        // case 2: only one null --> not symmetric
        if (left == nullptr || right == nullptr) return false;

        // case 3: values are different --> not symmetric
        if (left->val != right->val) return false;

        // case 4: compare mirrored children
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};

int main() {

    //            A:1               *
    //        /         \           *
    //      B:2         C:2         *
    //     /   \       /    \       *
    //    D:3   E:4  F:4    G:3     *

    // create tree
    TreeNode *A = new TreeNode(1);
    TreeNode *B = new TreeNode(2);
    TreeNode *C = new TreeNode(2);
    TreeNode *D = new TreeNode(3);
    TreeNode *E = new TreeNode(4);
    TreeNode *F = new TreeNode(4);
    TreeNode *G = new TreeNode(3);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;

    Solution solution;
    bool output = solution.isSymmetric(A);
    std::cout << "isSymmetric: " << output << std::endl;

    // should delete the pointers,
    // but it's not really necessary for this example

    return 0;
}