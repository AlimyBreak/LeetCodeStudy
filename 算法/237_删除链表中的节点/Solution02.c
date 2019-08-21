/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
    struct ListNode*    temp = NULL ;

    temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
    return ;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了99.09% 的用户
内存消耗 :7.7 MB, 在所有 C 提交中击败了5.09%的用户
*/

