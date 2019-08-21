/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
    struct ListNode*    front = node        ;
    struct ListNode*    cur   = node->next  ;
        
    while(cur->next)
    {
        front->val = cur->val   ;
        front      = cur        ;
        cur        = cur->next  ;
    }

    front->val = cur->val       ;
    free(front->next)           ;
    front->next = NULL          ;

    return ;
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了87.65% 的用户
内存消耗 :7.7 MB, 在所有 C 提交中击败了5.09%的用户
*/

