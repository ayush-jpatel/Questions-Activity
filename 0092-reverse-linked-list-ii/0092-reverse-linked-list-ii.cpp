/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode **prev = &head;
        for (int i=1; i<left; i++)
            prev = &(*prev)->next;
        ListNode *pivot = *prev;
        for (int i=left; i<right; i++) {
            swap(*prev, pivot->next->next);
        swap(*prev, pivot->next);
    }
    return head;
    }
};


 // ListNode* temp = head;
        // for(int i=0;i<left-1;i++)
        // {
        //     temp = temp->next;
        // }
        // ListNode* forward1=temp;
        // ListNode* forward2=temp;
        // ListNode* first = temp;
        // for(int i=left+1;temp!= nullptr && i<=right-1;i++)
        // {
        //     forward1 = first->next;
        //     first ->next = temp;
        //     forward2 = temp->next;
        //     temp->next = forward1;
        //     forward1->next = forward2;
        //     temp = forward2;
        // }
        // return head;