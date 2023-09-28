#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;   // value stored in the ListNode
    ListNode* next; // pointer to the next ListNode
};

class Solution {
public:
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
            ListNode *specialAddress = nullptr;
            while (currentNode->next) { // keep looking until the next ListNode pointer is nullptr (the end of the list)
                currentNode = currentNode->next;
                if (currentNode->val == 2) specialAddress = currentNode;
            }
            currentNode->next = newListNode; // once the end of the list is found, append the new ListNode to it
            
            // special case to make the list cyclic
            if (newListNode->val == -4) 
            newListNode->next = specialAddress;
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

    bool hasCycle(ListNode *head) {
                
        std::unordered_set<ListNode*> checkedAddresses;
        ListNode* currentListNode = head;
        
        while (currentListNode) {
            if (checkedAddresses.find(currentListNode) != checkedAddresses.end())
            return true; // cycle found
            checkedAddresses.insert(currentListNode);
            currentListNode = currentListNode->next;
        }
        return false; // no cycle found
    } 

};

int main() {

    // initialize the empty linked list
    ListNode *linkedList = nullptr;

    Solution solution;

    // insert elements at the end of the linked list
    solution.insertEnd(linkedList, 3);
    solution.insertEnd(linkedList, 2);
    solution.insertEnd(linkedList, 0);
    solution.insertEnd(linkedList, -4);

    std::cout << "output: " << solution.hasCycle(linkedList) << std::endl;
    // // display the linked list
    // std::cout << "Linked List: ";
    // solution.displayList(linkedList);

    return 0;
}