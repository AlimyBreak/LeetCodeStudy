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
            ListNode* temp  = head;
            int       count = 0;
            
            while(temp)
            {
                count++;
                temp = temp->next;
            }
            
            temp = head;
            count = count / 2;
            while(count--)
            {
                temp = temp -> next;
            }
            return temp ;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了72.23%的用户
内存消耗 :8.5 MB, 在所有 cpp 提交中击败了34.56%的用户
*/