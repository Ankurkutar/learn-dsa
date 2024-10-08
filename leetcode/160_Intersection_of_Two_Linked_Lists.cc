#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(!headA || !headB) return NULL;

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1 != ptr2){
            if(ptr1 == NULL){
                ptr1 = headB;
            }else{
                ptr1 = ptr1->next;
            }

            if(ptr2 == NULL){
                ptr2 = headA;
            }else{
                ptr2 = ptr2->next;
            }
        }
        return ptr1;
    }
};

// Helper function to print a list
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create two intersecting linked lists
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);
    
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common; // 4 -> 1 -> 8 -> 10
    
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common; // 5 -> 6 -> 1 -> 8 -> 10
    
    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);
    
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    cout<<"List printing......"<<endl;
    printList(headA);

    cout<<"List printing......"<<endl;
    printList(headB);


    return 0;
}
