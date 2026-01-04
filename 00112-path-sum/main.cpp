#include <iostream>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // base case: return false is received node is null
        if (root == nullptr) return false;
        return hts(root, 0, targetSum);  
    }

    bool hts(TreeNode *node, int currentSum, int targetSum) {
        currentSum += node->val;

        // if LEAF NODE: check if current sum equals the target sum
        if (node->left == nullptr && node->right == nullptr)
            return currentSum == targetSum;
        
        bool answerLeft = false;
        bool answerRight = false;

        // at each node:
        // - ask the left subtree: “do you have a valid path?”
        // - ask the right subtree: “do you have a valid path?”
        if (node->left) answerLeft = hts(node->left, currentSum, targetSum);
        if (node->right) answerRight = hts(node->right, currentSum, targetSum);

        // if either one says true: return true
        return answerLeft || answerRight;
    }
};

int main() {

    //          A:5             *
    //        /     \           *
    //      B:4     C:8         *
    //     /       /    \       *
    //    D:11   E:13   F:4     *

    // create tree
    TreeNode *A = new TreeNode(5);
    TreeNode *B = new TreeNode(4);
    TreeNode *C = new TreeNode(8);
    TreeNode *D = new TreeNode(11);
    TreeNode *E = new TreeNode(13);
    TreeNode *F = new TreeNode(4);

    A->left = B;
    A->right = C;
    B->left = D;
    C->left = E;
    C->right = F;

    int targetSum;
    std::cout << "targetSum: ";
    std::cin >> targetSum;

    Solution solution;
    bool output = solution.hasPathSum(A, targetSum);
    std::cout << "hasPathSum: " << output << std::endl;

    // should delete the pointers,
    // but it's not really necessary for this example

    return 0;
}