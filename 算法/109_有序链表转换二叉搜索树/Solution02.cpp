/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    
    TreeNode* __sortedListToBST(ListNode* head)
    {
        /*极端情况,输入没有节点或者只有一个节点*/
        if(head==NULL)
        {
            return NULL;
        }
        else if(head->next == NULL)
        {
            return new TreeNode(head->val);
        }
        
        ListNode* pre   =   head;
        ListNode* slow  =   pre->next   ;/*慢指针*/
        ListNode* fast  =   slow->next  ;/*快指针*/
        
        while(  (fast!=NULL)
              &&(fast->next!=NULL)
        )
        {
            pre     = slow; /*保存中间节点的前一个节点,用于链表截断*/
            slow    = slow->next;
            fast    = fast->next->next;
        }
        
        /*
            head...pre-->slow-->slow_next-->...
            截断到pre
            slow用来构造根节点返回
            head和slow_next分别用构造左子树和右子树.
        */
        pre->next = NULL;   /*截断链表*/
        TreeNode* tn = new TreeNode(slow->val);   /*用中间节点构造根节点*/
        tn->left  =   __sortedListToBST(head);
        tn->right =   __sortedListToBST(slow->next);
        return tn;
    }
    public:
        TreeNode* sortedListToBST(ListNode* head)
        {
            return __sortedListToBST(head);
        }
};


/*
执行结果：
通过
显示详情
执行用时 :56 ms, 在所有 C++ 提交中击败了43.52% 的用户
内存消耗 :24.3 MB, 在所有 C++ 提交中击败了89.95%的用户
缺点:破坏了原有链表结构.
*/