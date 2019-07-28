/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        stack<int>  si                  ;
        ListNode*   temp        = head  ;
        int         val_temp    = 0     ;
        
        while(temp!=NULL)
        {
            si.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            temp->val = si.top();
            si.pop();
            temp = temp->next;
        }
        return head;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了59.98% 的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了20.28%的用户
*/