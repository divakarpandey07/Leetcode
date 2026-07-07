#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    TreeLinkNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
    if (root==NULL) return;

    if (root->left && root->right){
        root->left->next = root->right;
    }

    if (root->next) {
        
         TreeLinkNode *left=NULL, *right=NULL;
         left = root->right ? root->right: root->left;

         for (TreeLinkNode *p = root->next; p!=NULL; p=p->next) {
             if (p->left){
                 right = p->left;
                 break;
             }
             if (p->right){
                 right = p->right;
                 break;
             }
         }
         if (left){
             left->next = right;
         }   
    }
    connect(root->right);
    connect(root->left);
}

void connect1(TreeLinkNode *root) {

    if (root==NULL){
        return;
    }
    
    vector<TreeLinkNode*> v;

    v.push_back(root);
    
    while(v.size()>0){
        
        if ( (root->left && root->left->next==NULL) || (root->right && root->right->next==NULL) ) {

            if (root->left && root->right){
                root->left->next = root->right;
            }
            
            if (root->next){
                TreeLinkNode *left=NULL, *right=NULL;
                left = root->right ? root->right: root->left;
                
                for (TreeLinkNode *p = root->next; p!=NULL; p=p->next) {
                    if (p->left){
                        right = p->left;
                        break;
                    }
                    if (p->right){
                        right = p->right;
                        break;
                    }
                }

                if (left){
                    left->next = right;
                }   
            }
            if (root->left) {
                v.push_back(root->left);
            }
            if (root->right) {
                v.push_back(root->right);
            }
        }
        root = v.back();
        v.pop_back();
    }
}

void connect3(TreeLinkNode *root) {
    if(root == NULL) return;

    queue<TreeLinkNode*> q;
    TreeLinkNode *prev, *last;
    prev = last = root;

    q.push(root);
    while(!q.empty()) {
        TreeLinkNode* p = q.front();
        q.pop();

        prev->next = p;
        if(p->left ) q.push(p->left);
        if(p->right) q.push(p->right);

        if(p == last) { 
            
            last = q.back();
            p->next = NULL; 
            prev = q.front();
        }
        else {
            prev = p;
        }
    }
}

void connect4(TreeLinkNode *root) {
    if(root == NULL) return;

    TreeLinkNode *head, *tail;
    TreeLinkNode *prev, *last;

    head = tail = NULL;
    prev = last = root;

#define push(p) \
    if(head == NULL) { head = tail = p; } \
    else { tail->next = p; tail = p; }

    push(root);
    while(head != NULL) {
        TreeLinkNode* p = head;
        head = head->next; 

        prev->next = p;
        if(p->left ) push(p->left);
        if(p->right) push(p->right);

        if(p == last) {
            last = tail;
            p->next = NULL; 
            prev = head;
        }
        else {
            prev = p;
        }
    }
#undef push
}

void printTree(TreeLinkNode *root){
    if (root == NULL){
        return;
    }
    printf("[%2d] : left[%d], right[%d], next[%d]\n",
            root->val,
            root->left ? root->left->val : -1,
            root->right ? root->right->val : -1,
            root->next?root->next->val : -1 );

    printTree(root->left);
    printTree(root->right);

}

int main()
{
    const int cnt = 15; 
    TreeLinkNode a[cnt];
    for(int i=0; i<cnt; i++){
        a[i].val = i+1;
    } 
    
    for(int i=0, pos=0; pos<cnt-1; i++ ){
        a[i].left = &a[++pos];
        a[i].right = &a[++pos];
    }
    a[5].left = a[5].right = NULL;
    a[3].right = NULL;

    
    

    
    
    TreeLinkNode b(100), c(200);
    
    
    a[9].left = &b;

    connect(&a[0]); 

    printTree(&a[0]);

    return 0;
}