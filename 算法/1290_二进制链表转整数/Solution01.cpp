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
        int getDecimalValue(ListNode* head)
        {
            int temp = 0;
            while(head)
            {
                temp = temp * 2 + head->val;
                head = head->next;
            }
            return temp;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了73.12% 的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了100.00%的用户
*/