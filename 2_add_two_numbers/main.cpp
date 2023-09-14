#include <iostream>

struct ListNode {
    int val;   // value stored in the ListNode
    ListNode* next; // pointer to the next ListNode
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2) {
        ListNode *currentNode1 = list1;
        ListNode *currentNode2 = list2;
        ListNode *additionList = nullptr;
        bool overflow = false;
        while (currentNode1 || currentNode2) {
            int sum = 0;
            if (currentNode1 && currentNode2) sum = currentNode1->val + currentNode2->val;
            if (currentNode1 && !currentNode2) sum = currentNode1->val;
            if (!currentNode1 && currentNode2) sum = currentNode2->val;
            if (overflow) {
                sum++;
                overflow = false;
            }
            if (sum > 9) {
                sum -= 10;
                overflow = true;
            }
            insertEnd(additionList, sum);
            if (currentNode1) currentNode1 = currentNode1->next;
            if (currentNode2) currentNode2 = currentNode2->next;
        }
        if (overflow) {
            insertEnd(additionList, 1);
            overflow = false;
        }
        return additionList;
    }


    void insertEnd(ListNode*& head, int value) {
        ListNode *newListNode = new ListNode;
        newListNode->val = value;
        newListNode->next = nullptr;

        if (!head) {
            // if the list is empty, set the new ListNode as the head of the list
            head = newListNode; // the head pointer now points to the memory address of newListNode
        } else {
            // otherwise, append the new ListNode to the end of the list
            ListNode *currentNode = head;
            while (currentNode->next) { // keep looking until the next ListNode pointer is nullptr (the end of the list)
                currentNode = currentNode->next;
            }
            currentNode->next = newListNode; // once the end of the list is found, append the new ListNode to it
        }
    }


    void displayList(const ListNode* head) {
        const ListNode* currentNode = head; // currentNode takes the memory address of the head (first element in the list)
        while (currentNode) { // while not reaching the end of the list (nullptr)
            std::cout << currentNode->val << " ";
            currentNode = currentNode->next; // currentNode now takes the memory address of the next ListNode
        }
        std::cout << std::endl;
    }
};

int main() {

    // initialize the empty linked lists
    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;

    Solution solution;

    // insert elements at the end of the linked list
    solution.insertEnd(list1, 2);
    solution.insertEnd(list1, 4);
    solution.insertEnd(list1, 3);

    // insert elements at the end of the linked list
    solution.insertEnd(list2, 5);
    solution.insertEnd(list2, 6);
    solution.insertEnd(list2, 9);

    ListNode *total = solution.addTwoNumbers(list1, list2);

    // display the linked list
    std::cout << "Linked List 1: ";
    solution.displayList(list1);
    std::cout << "Linked List 2: ";
    solution.displayList(list2);
    std::cout << "Total: ";
    solution.displayList(total);

    return 0;
}