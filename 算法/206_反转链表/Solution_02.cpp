/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    public:
        ListNode* reverseList(ListNode* head)
        {
            stack<struct ListNode*> sl          ;
            ListNode*               temp = head ;
            
            while(temp!=NULL)
            {
                sl.push(temp);
                temp = temp->next;
            }
            if(sl.empty()!=true)
            {
                head = sl.top()     ;
                temp = head         ;
                sl.pop()            ;
                while(sl.empty()!=true)
                {
                    temp->next = sl.top();
                    sl.pop();
                    temp = temp -> next;
                }
                temp->next = NULL;
            
            }
            return head;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 C++ 提交中击败了87.55% 的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了14.09%的用户
*/