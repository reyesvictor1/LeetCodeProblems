#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {};
};

class Solution {
public:
    Node* reverseList(Node* head) {
        Node* current = head;
        Node* newHead = nullptr;
        Node* originalNext = nullptr;
        Node* originalPrev = nullptr;
        while(current) {
            originalNext = current->next;
            current->next = originalPrev;
            originalPrev = current;
            current = originalNext;
        }
        newHead = originalPrev;
        return newHead;
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
    Node* linkedList = createLinkedList(input);
    printLinkedList(linkedList);

    Solution solution;
    Node* reversedLinkedList = solution.reverseList(linkedList);
    printLinkedList(reversedLinkedList);

    return 0;
}