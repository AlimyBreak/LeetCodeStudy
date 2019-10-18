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
        ListNode* oddEvenList(ListNode* head)
        {
            queue<ListNode*> qln_odd            ;
            queue<ListNode*> qln_even           ;
            ListNode         ret_val(0)         ;
            ListNode*        cur                ;
            int              count      = 0     ;
            
            if(head)
            {
                while(head)
                {
                    if(++count%2)
                    {
                        qln_odd.push(head);
                    }
                    else
                    {
                        qln_even.push(head);
                    }
                    head = head->next;
                }
                
                cur = &ret_val;
                
                while(qln_odd.size())
                {
                    cur->next   =   qln_odd.front();
                    cur         =   cur->next;
                    qln_odd.pop();
                }
                
                while(qln_even.size())
                {
                    cur->next   =   qln_even.front();
                    cur         =   cur->next; 
                    qln_even.pop();
                }
                cur->next = NULL;
            }     
            
            
            return ret_val.next;
        }
};



/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 cpp 提交中击败了39.56%的用户
内存消耗 :10.1 MB, 在所有 cpp 提交中击败了5.59%的用户
*/