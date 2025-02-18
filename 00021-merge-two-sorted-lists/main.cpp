#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {};
};

class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {

        // in case one of the lists is empty, just return the other
        if (list1 && !list2) return list1;
        if (!list1 && list2) return list2;

        Node* current1 = list1;
        Node* current2 = list2;

        Node* mergedHead= nullptr;
        Node* lastMerged = nullptr;

        // traverse each list with its corresponding pointer (current1 and current2)
        // compare the values of each current Node to decide which will be the next in the merged list
        // mergedHead just stores the address of the head of the merged list
        // lastMerged keeps track of the last Node added to the merged list
        while (current1 || current2) {
            if (!current1) {
                lastMerged->next = current2;
                break;
            }

            if (!current2) {
                lastMerged->next = current1;
                break;
            }

            if (current1->val <= current2->val) {
                if (!mergedHead) {
                    mergedHead = current1;
                    lastMerged = current1;
                } else {
                    lastMerged->next = current1;
                    lastMerged = lastMerged->next;
                }
                current1 = current1->next;
            } else {
                if (!mergedHead) {
                    mergedHead = current2;
                    lastMerged = current2;
                } else {
                    lastMerged->next = current2;
                    lastMerged = lastMerged->next;
                }
                current2 = current2->next;
            }
        }
        return mergedHead;
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
    std::vector<int> list1 = {1,2,4};
    std::cout << "list1: ";
    for (int num : list1) std::cout << num << " ";
    std::cout << std::endl;
    
    std::vector<int> list2 = {1,3,4};
    std::cout << "list2: ";
    for (int num : list2) std::cout << num << " ";
    std::cout << std::endl;

    Node* linkedList1 = createLinkedList(list1);
    printLinkedList(linkedList1);

    Node* linkedList2 = createLinkedList(list2);
    printLinkedList(linkedList2);

    Solution solution;
    Node* mergedLinkedList = solution.mergeTwoLists(linkedList1, linkedList2);
    printLinkedList(mergedLinkedList);

    return 0;
}