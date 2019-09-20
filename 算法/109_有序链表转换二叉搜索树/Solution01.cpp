/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    private:
        TreeNode* __sortedListToBST(vector<int>& vi , int left , int right)
        {
            if(left > right)
            {
                return NULL;
            }
            if(left == right)
            {
                return new TreeNode(vi[left]);
            }
            
            int mid = left + ( right - left) / 2;/*防止假加法溢出*/
            TreeNode* tnp = new TreeNode(vi[mid]);
            tnp->left  = __sortedListToBST(vi,left,mid-1);
            tnp->right = __sortedListToBST(vi,mid+1,right);
            return tnp;
        }
    public:
        TreeNode* sortedListToBST(ListNode* head)
        {
            vector<int> vi;
            while(head)
            {
                vi.push_back(head->val);
                head = head->next;
            }
            
            return __sortedListToBST(vi,0,vi.size()-1);
        }
};


/*
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 C++ 提交中击败了92.29% 的用户
内存消耗 :24.7 MB, 在所有 C++ 提交中击败了20.10%的用户
*/