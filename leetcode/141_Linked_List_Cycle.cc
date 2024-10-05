#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
    public:
    bool hasCycle(ListNode* head){

        // Base case: if the list is empty or has only one node, there is no cycle
        if(head == nullptr || head->next == nullptr){
            return false;
        }

        ListNode *slow = head;
        ListNode * fast = head;

        // this condition check fast and fast->next not be null bcz need to assign value inside lopp fast = fast->next->next 
        
        while(fast != nullptr && fast->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;

            if(slow = fast){
                return true;
            }
        }

        // If fast reaches the end of the list, there is no cycle
        return false;
    }
};

// Function to create a cycle in the linked list
void createCycle(ListNode* &head, int pos) {
    if (pos == -1) return;

    ListNode* cycleNode = nullptr;
    ListNode* temp = head;
    ListNode* tail = nullptr;

    int index = 0;
    while (temp->next != nullptr) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }
    tail = temp;  // Last node
    tail->next = cycleNode;  // Creating cycle
}

int main(){
     ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    // Creating a cycle (linking the last node to the second node)
    createCycle(head, 1); // Cycle at position 1 (node with value 2)

    Solution solution;
    bool hasCycleFlag = solution.hasCycle(head);

    if (hasCycleFlag) {
        cout << "Cycle detected in the linked list!" << endl;
    } else {
        cout << "No cycle detected in the linked list!" << endl;
    }

    return 0;
}