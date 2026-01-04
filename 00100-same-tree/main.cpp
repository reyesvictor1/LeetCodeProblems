#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    // properties
    int val;
    TreeNode *left;
    TreeNode *right;

    // 3 possible constructors:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    // Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // early guard clause: both trees are nullptr
        if (p == nullptr && q == nullptr) return true;

        // declare stacks for a Depth First Search (DFS) traversal
        std::stack<TreeNode *> stackP;
        std::stack<TreeNode *> stackQ;

        // initialize the stacks
        stackP.push(p);
        stackQ.push(q);

        std::vector<std::stack<TreeNode *>> stacks = {stackP, stackQ};

        while (!stacks[0].empty()) {
            TreeNode *currentNodeA = stacks[0].top(); // access the top node

            for (int i = 1; i < stacks.size(); i++) {
                if (stacks[i].empty()) return false;
                TreeNode *currentNodeB = stacks[i].top(); // access the top node
                
                if (currentNodeA == nullptr && currentNodeB == nullptr) continue;
                if (currentNodeA == nullptr || currentNodeB == nullptr) return false;

                // main comparisons
                if (currentNodeA->val != currentNodeB->val) return false;
                if ((currentNodeA->left  == nullptr) != (currentNodeB->left  == nullptr)) return false;
                if ((currentNodeA->right == nullptr) != (currentNodeB->right == nullptr)) return false;

                stacks[i].pop(); // remove node from stack
                if (currentNodeB->right) stacks[i].push(currentNodeB->right); // push right child
                if (currentNodeB->left) stacks[i].push(currentNodeB->left); // push left child
            }

            stacks[0].pop(); // remove node from stack
            if (currentNodeA->right) stacks[0].push(currentNodeA->right); // push right child
            if (currentNodeA->left) stacks[0].push(currentNodeA->left); // push left child
        }

        return true;
    }
};

int main() {
    // create tree A
    TreeNode *A01 = new TreeNode(1);
    TreeNode *A02 = new TreeNode(2);
    TreeNode *A03 = new TreeNode(3);
    A01->left = A02;
    A01->right = A03;

    // create tree B
    TreeNode *B01 = new TreeNode(1);
    TreeNode *B02 = new TreeNode(2);
    TreeNode *B03 = new TreeNode(3);
    B01->left = B02;
    B01->right = B03;

    Solution solution;
    bool output = solution.isSameTree(A01, B01);
    std::cout << "isSameTree: " << output << std::endl;

    return 0;
}