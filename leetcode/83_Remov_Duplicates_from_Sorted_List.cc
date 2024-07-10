#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *ptr = head;
        while (ptr != nullptr && ptr->next != nullptr)
        {
            if (ptr->val == ptr->next->val)
            {
                ListNode *duplicateNode = ptr->next;
                ptr->next = ptr->next->next;
                delete duplicateNode;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        return head;
    }
};

ListNode *createNode(int value)
{
    return new ListNode(value);
}

// Function to print the list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    Solution solution;
    ListNode *newHead = solution.deleteDuplicates(head);

    // Print the modified list
    printList(newHead);

    return 0;
}