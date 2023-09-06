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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head; 
        while(temp!= nullptr)
        {
            n++;
            temp = temp->next;
        }
        int rem = n%k;
        int div = n/k;
        int count = 0;
        temp = head;
        vector<ListNode*> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(temp);
            int a = 0;
            if(i<rem)
                a = 1;
            for(int j=0;j<div-1 + a;j++)
            {
                temp = temp->next;
            }
            if(temp == nullptr)
            {
                continue;
            }
            ListNode* forward = temp->next;
            temp ->next = nullptr;
            temp = forward;
        }
        return res;


    }
};