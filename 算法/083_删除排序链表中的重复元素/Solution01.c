/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    
    struct ListNode*  frame_head = NULL;
    struct ListNode*  frame_tail = NULL;
    struct ListNode*  temp       = NULL;
    
    do{
        
        if(  (head == NULL)
           ||(head->next == NULL)
        )
        {
            break;
        }
        else
        {
            frame_head = head           ;
            frame_tail = head->next     ;
            
            while(frame_tail!=NULL)
            {
                if(frame_head->val == frame_tail->val)
                {
                    temp = frame_tail;
                    frame_tail = frame_tail->next;
                    frame_head->next = frame_tail;
                    free(temp);
                }
                else
                {
                    frame_head = frame_tail;
                    frame_tail = frame_tail -> next;
                    
                }
            }
        }
    
    }while(0);
    
    return head;
}


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了86.25% 的用户
内存消耗 :7.8 MB, 在所有 C 提交中击败了5.21%的用户
*/
