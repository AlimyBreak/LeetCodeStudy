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
        int ret_val     = 0;
        int target_sum  = 0;
        
        void __pathSum(TreeNode* node , int level_sum)
        {
            if(node==NULL)
            {
                return ;
            }
            
            int temp = level_sum + node->val;
            
            if(temp==target_sum)
            {
                ret_val++;
                //return;
            }
            __pathSum(node->left,temp);
            __pathSum(node->right,temp);
        }


        /* 根左右*/
        void dfs(TreeNode* node)
        {
            if(node==NULL)
            {
                return;
            }

            __pathSum(node,0);
            dfs(node->left);
            dfs(node->right);
        }

    public:
        int pathSum(TreeNode* root, int sum)
        {
            ret_val     = 0;
            target_sum  = sum;
            dfs(root);
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :44 ms, 在所有 C++ 提交中击败了41.65% 的用户
内存消耗 :14.6 MB, 在所有 C++ 提交中击败了84.96%的用户
*/