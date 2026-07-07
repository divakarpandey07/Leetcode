class Solution {
public:
    
    Solution(ListNode* head) {
        this->head = head;
        this->len = 0;
        for(ListNode*p = head; p!=NULL; p=p->next, len++);
        srand(time(NULL));
    }
    
    
    int getRandom() {
        int pos = rand() % len;
        ListNode *p = head;
        for (; pos > 0; pos--, p=p->next);
        return p->val;
    }
    ListNode* head;
    int len;
};