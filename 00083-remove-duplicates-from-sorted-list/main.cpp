#include <iostream>
#include <vector>
#include <climits>

struct Node {
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {};
};

class Solution {
public:
    Node* deleteDuplicates(Node* head) {
        Node* current = head;
        Node* lastValidNode = nullptr;
        int lastValue = INT_MIN;
        bool hasRepeated = false;
        while (current) {
            if (current->val != lastValue) {
                if (lastValidNode) lastValidNode->next = current;
                lastValidNode = current;
                lastValue = current->val;
                hasRepeated = false;
            } else hasRepeated = true;
            current = current->next;
        }

        // in case that linked list ends with repeated values
        if (hasRepeated) lastValidNode->next = nullptr;

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
    std::vector<int> input = {1,1,2,3,4,4,5,5,5,6,6};
    std::cout << "input:";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Node* linkedList = createLinkedList(input);
    printLinkedList(linkedList);

    Solution solution;
    Node* newLinkedList = solution.deleteDuplicates(linkedList);
    printLinkedList(newLinkedList);

    return 0;
}