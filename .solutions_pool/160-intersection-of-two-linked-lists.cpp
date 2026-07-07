class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            
            int lenA = getListLength(headA);
            int lenB = getListLength(headB);

            if (lenA<=0 || lenB<=0 ) return NULL;

            
            if (lenA < lenB){
                swap(headA, headB);
            }

            
            for (int i=0; i<abs(lenA-lenB); i++){
                headA = headA->next;
            }

            
            while (headA != headB){
                headA = headA->next;
                headB = headB->next;
            }

            return headA;
        }
    private:    
        inline int getListLength(ListNode *head){
            int len=0;
            while(head!=NULL){
                head = head->next;
                len++;
            }
            return len;
        }
};