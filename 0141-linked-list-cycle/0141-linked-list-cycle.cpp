/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//can also be done by fast/slow model where both intersect at same node if there is a loop
    bool hasCycle(ListNode *head) {
        int i = 0;
        // ListNode * ptr=head;
        for(i=0;i<=10000;i++)
        {
            if(head == nullptr)
            {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};