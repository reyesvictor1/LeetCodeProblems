#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {};
};

class Solution {
public:
    Node* removeElements(Node* head, int val) {
        // traverse the entire linked list, removing val
        Node* current = head;
        Node* firstValidNode = nullptr;
        Node* lastValidNode = nullptr;
        while (current) {
            // if current node is valid, then it becomes the last valid node (and first, if applicable)
            if (current->val != val) {
                if (!firstValidNode) firstValidNode = current;
                lastValidNode = current;
            } else { // if current node is NOT valid, update the address to which the last valid node points
                if (lastValidNode) lastValidNode->next = current->next;
            }
            current = current->next;
        }
        return firstValidNode;
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
    std::vector<int> input = {1,2,6,3,4,5,6};
    int val = 6;
    std::cout << "input:";
    for (int num : input) std::cout << num << " ";
    std::cout << std::endl;

    Node* linkedList = createLinkedList(input);
    printLinkedList(linkedList);

    Solution solution;
    Node* newLinkedList = solution.removeElements(linkedList, 1);
    printLinkedList(newLinkedList);

    return 0;
}