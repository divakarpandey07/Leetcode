class Solution {
public:
    bool hasCycle(ListNode *head) {
        return hasCycle04(head);
        return hasCycle03(head);
        return hasCycle02(head);
        return hasCycle01(head);
    }

    
    bool hasCycle01(ListNode *head) {
        unordered_map<ListNode*,bool > m;
        ListNode* p = head;
        m[(ListNode*)NULL] = true;
        while( m.find(p) == m.end() ) {
            m[p] = true;
            p = p -> next;
        }
        return p != NULL;
    }

    
    bool hasCycle02(ListNode *head) {
        ListNode* p = head;
        
        while( p &&  p->val != INT_MAX ) {
            p->val = INT_MAX;
            p = p -> next;
        }
        return p != NULL;
    }

    
    bool hasCycle03(ListNode *head) {
        if (head==NULL || head->next==NULL) return false;
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(fast != NULL && fast->next != NULL && fast != slow);
        return fast == slow? true : false;
    }

    
    bool hasCycle04(ListNode *head) {
         ListNode dummy (0);
        ListNode* p = NULL;

        while (head != NULL) {
            p = head;
            head = head->next;

            
            
            if (p->next == &dummy) return true;

            p->next = &dummy; 
        }
        return false;
    }

};