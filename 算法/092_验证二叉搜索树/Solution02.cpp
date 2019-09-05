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
    
    public:
        bool isValidBST(TreeNode* root)
        {
            
            stack<TreeNode*>    stn             ;
            TreeNode*           temp    = NULL  ;
            TreeNode*           pre     = NULL  ;
            
            temp = root;
            while((!stn.empty())||(temp))
            {
                if(temp)
                {
                    stn.push(temp);
                    temp = temp ->left;
                }
                else
                {
                    temp    =   stn.top();
                    stn.pop();
                    if(pre && pre->val >= temp->val)
                    {
                        return false;
                    }
                    pre     =   temp;
                    temp    =   temp -> right;
                }
            }

            return true;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了89.50% 的用户
内存消耗 :20.6 MB, 在所有 C++ 提交中击败了52.90%的用户
*/