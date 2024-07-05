#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode dummy;
            ListNode *tail = &dummy;

            while(list1 != nullptr && list2 != nullptr){
                if(list1->val < list2->val){
                    tail->next = list1;
                    list1 = list1->next;
                }else{
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }


            // Attach the remaining nodes from either list1 or list2
            if (list1 != nullptr) {
                tail->next = list1;
            } else {
                tail->next = list2;
            }

            return dummy.next;
        }
};


void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Create first sorted linked list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Create second sorted linked list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merge the two lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    return 0;
}