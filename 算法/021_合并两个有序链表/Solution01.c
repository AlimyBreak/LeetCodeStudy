/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* mergeTwoLists( struct ListNode*    l1 ,
                                struct ListNode*    l2
                              )
{
    struct ListNode         head               ;
    struct ListNode*        tail_node   = NULL ;
    
    head.next = NULL;
    tail_node = &head;
    while(1)
    {
        if((l1!=NULL)&&(l2!=NULL))
        {
            if(l1->val <= l2->val)
            {
                tail_node->next =   l1          ;
                tail_node       =   l1          ;
                l1              =   l1->next    ;
                tail_node->next =   NULL        ;
            }
            else
            {
                tail_node->next =   l2          ;
                tail_node       =   l2          ;
                l2              =   l2->next    ;
                tail_node->next =   NULL        ;
            }
        }
        else if(l1!=NULL)
        {
            tail_node->next     =   l1          ;
            tail_node           =   l1          ;            
            l1                  =   l1->next    ;
            tail_node->next     =   NULL        ;            
        }
        else if(l2!=NULL)
        {
            tail_node->next     =   l2          ;
            tail_node           =   l2          ;
            l2                  =   l2->next    ;
            tail_node->next     =   NULL        ; 
        }
        else
        {
            break;
        }   
    }    
    return head.next;
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了68.29% 的用户
内存消耗 :7.5 MB, 在所有 C 提交中击败了77.42%的用户
*/

