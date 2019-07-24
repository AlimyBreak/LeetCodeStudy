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
        bool isUnivalTree(TreeNode* root)
        {
            int                 val         = 0     ;
            int                 num_1       = 0     ;
            int                 num_2       = 0     ;
            int                 i           = 0     ;
            TreeNode*           temp        = NULL  ;
            queue<TreeNode*>    qu                  ;
            
        
            if(root==NULL)
            {
                return true;
            }
            val = root->val;
            qu.push(root);
            num_1 = 0;
            num_2 = 1;
            while(num_2!=0)
            {
                num_1 = num_2;
                num_2 = 0;
                for(i = 0; i < num_1;i++)
                {
                    temp = qu.front();
                    if(val!=temp->val)
                    {
                        return false;
                    }
                    if(temp->left != NULL)
                    {
                        qu.push(temp->left);
                        num_2++;
                    }
                    if(temp->right !=NULL)
                    {
                        qu.push(temp->right);
                        num_2++;
                    }
                    qu.pop();
                }
            }
            return true;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了61.30% 的用户
内存消耗 :10.5 MB, 在所有 C++ 提交中击败了97.15%的用户
*/