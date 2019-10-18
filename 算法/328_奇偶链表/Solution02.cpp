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
            ListNode    head_odd(0)                 ;
            ListNode*   tail_odd        =   NULL    ;
            ListNode    head_even(0)                ;
            ListNode*   tail_even       =   NULL    ;
            int         count           =   0       ;
            
            if(head)
            {
                tail_odd    =   &head_odd;
                tail_even   =   &head_even;
                
                while(head)
                {
                    /*奇*/
                    if(++count %2)
                    {
                        tail_odd->next  =   head            ;
                        tail_odd        =   tail_odd->next  ;
                    }
                    /*偶*/
                    else
                    {
                        tail_even->next =   head;
                        tail_even       =   tail_even->next;
                    }
                    head = head->next;
                }
                tail_odd->next  = head_even.next;
                tail_even->next = NULL;
            }
            
            return head_odd.next;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :32 ms, 在所有 cpp 提交中击败了32.78%的用户
内存消耗 :9.7 MB, 在所有 cpp 提交中击败了78.19%的用户
*/