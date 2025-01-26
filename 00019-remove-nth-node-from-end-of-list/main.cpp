#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {};
};

class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {
        // APPROACH: Think of this as a race with three participants:
        //      a) 'current' - starts immediately and moves through the list
        //      b) 'nodeToRemove' - starts after 'n' steps
        //      c) 'nodeBeforeNodeToRemove' - starts after 'n+1' steps
        // They all move at the same pace, but they start after different delays
        // The goal is for 'nodeToRemove' to point to the node to be removed when 'current' reaches the end of the list
        // And 'nodeBeforeNodeToRemove' will end up right before the 'nodeToRemove'
        Node* nodeToRemove = head;
        Node* nodeBeforeNodeToRemove = head;
        Node* current = head;
        while (current) {
            // delay 'nodeToRemove' by 'n' steps
            if (n == 0) {
                nodeToRemove = nodeToRemove->next;
            }
            // delay 'nodeBeforeNodeToRemove' by 'n+1' steps
            else if (n < 0) {
                nodeToRemove = nodeToRemove->next;
                nodeBeforeNodeToRemove = nodeBeforeNodeToRemove->next;
            }
            n--;  // countdown
            current = current->next;
        }

        // if the node to be removed is the head, move head to the next node
        if (nodeToRemove == head) head = head->next;
        // otherwise, skip the node to be removed
        else nodeBeforeNodeToRemove->next = nodeToRemove->next;

        return head;
    }
};

Node* createLinkedList(std::vector<int> input) {
    if (input.empty()) return nullptr;

    Node* head = new Node(input[0]);
    Node* current = head;

    for (int i = 1; i < input.size(); i++) {
        current->next = new Node(input[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    std::vector<int> input = {1,2,3,4,5};
    int n = 2;
    
    std::cout << "input:";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Node* linkedList = createLinkedList(input);
    printLinkedList(linkedList);

    Solution solution;
    Node* newLinkedList = solution.removeNthFromEnd(linkedList, n);
    printLinkedList(newLinkedList);

    return 0;
}