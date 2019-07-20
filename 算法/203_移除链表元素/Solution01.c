/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* cur    = NULL;
    struct ListNode* front  = NULL;
    

    /*首先删除链表首val节点,保证head节点的值不是val*/
    while(  (head!=NULL)
          &&(head->val==val)
    )
    {
        cur     =   head;
        head    =   head-> next;
        free(cur);
    }
    
    if(head!=NULL)
    {
        
        front   = head;
        cur     = front->next;
        while(cur!=NULL)
        {
            if(cur->val == val)
            {
                front->next = cur->next;
                free(cur);
                cur = front->next;
            }
            else
            {
                front = cur;
                cur = front->next;
            }
        }
    } 
    return head;
}


/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了95.57% 的用户
内存消耗 :9.4 MB, 在所有 C 提交中击败了87.50%的用户
*/