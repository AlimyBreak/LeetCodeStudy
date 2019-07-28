/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* head_temp  = NULL;
    struct ListNode* tail_temp  = NULL;
    struct ListNode* temp       = NULL;
    
    if(  ( head       == NULL )
       ||( head->next == NULL )
    )
    {
        return head;
    }
    else
    {
        head_temp   = head              ;
        tail_temp   = head              ;
        temp        = tail_temp->next   ;
        while(1)
        {
            if(temp==NULL)
            {
                break;
            }
            else
            {
                tail_temp -> next   = tail_temp -> next -> next;
                temp->next          = head_temp;
                head_temp           = temp;
                temp                = tail_temp -> next;
            }
        }
    }
    return head_temp;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了93.16% 的用户
内存消耗 :7.6 MB, 在所有 C 提交中击败了23.61%的用户
*/
