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
        ListNode* middleNode(ListNode* head)
        {
            ListNode temp(0);
            temp.next = head;
            ListNode* slower    =   &temp;
            ListNode* faster    =   &temp;
            
            
            while(faster->next && faster->next->next)
            {
                slower = slower->next;
                faster = faster->next->next;
            }
            
            
            return slower->next;
         
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了72.23%的用户
内存消耗 :8.5 MB, 在所有 cpp 提交中击败了24.13%的用户
*/