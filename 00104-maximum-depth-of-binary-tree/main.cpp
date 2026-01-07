#include <iostream>

struct TreeNode {
    //properties
    int val;
    TreeNode* left;
    TreeNode* right;

    // 3 possible constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // early guard clause: return 0 if root node is null
        if (root == nullptr) return 0;
        return goDeeper(root, 0);
    }
    int goDeeper(TreeNode* node, int currentDepth) {
        // update: current depth
        currentDepth++;

        // base case: if leaf node, return the current depth
        if (node->left == nullptr && node->right == nullptr)
            return currentDepth;
        
        // recursion: ask the children
        int leftDepth = 0;
        int rightDepth = 0;
        if (node->left) 
            leftDepth = goDeeper(node->left, currentDepth);
        if (node->right)
            rightDepth = goDeeper(node->right, currentDepth);

        // combine: combine children's results
        return std::max(leftDepth, rightDepth);
    }
};

int main() {
    //          A:5             *
    //        /     \           *
    //      B:4     C:8         *
    //                 \        *
    //                 D:4      *

    // create tree
    TreeNode *A = new TreeNode(5);
    TreeNode *B = new TreeNode(4);
    TreeNode *C = new TreeNode(8);
    TreeNode *D = new TreeNode(4);

    A->left = B;
    A->right = C;
    C->right = D;

    Solution solution;
    int output = solution.maxDepth(A);
    std::cout << "maxDepth: " << output << std::endl;

    return 0;
}