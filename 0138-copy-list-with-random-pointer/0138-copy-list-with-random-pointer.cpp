/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        mp[nullptr] = nullptr;
        if(head == nullptr)
            return head;
        Node* res = new Node(0);
        Node* ptr = head;
        Node* newptr = res;
        mp[ptr] = newptr;
        while(ptr!= nullptr)
        {
            newptr->val = ptr->val;
            if(mp.count(ptr->next))
            {
                newptr->next = mp[ptr->next];
            }
            else
            {
                Node* temp = new Node(ptr->next->val);
                newptr->next = temp;
                mp[ptr->next] = temp;
            }
            if(mp.count(ptr->random))
            {
                newptr->random = mp[ptr->random];
            }
            else
            {
                Node* temp = new Node(ptr->random->val);
                newptr->random = temp;
                mp[ptr->random] = temp;
            }
            ptr = ptr->next;
            newptr = newptr->next;
        }
        return res;
    }
};






