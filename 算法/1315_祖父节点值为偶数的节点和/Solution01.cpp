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
        int ret_val = 0;
        
        
        void travelGrandson(TreeNode* node)
        {
            if(node==NULL)
            {
                return;
            }
            
            if(node->left)
            {
                ret_val += node->left->val;
            }
            
            if(node->right)
            {
                ret_val += node->right->val;
            }
            
            
        }
        
        void dfs(TreeNode* node )
        {
            if(node==NULL)
            {
                return;
            }
            
            if(node->val%2==0)
            {
                travelGrandson(node->left);
                travelGrandson(node->right);
                
            }
            
            dfs(node->left);
            dfs(node->right);
        }
        
        
        
    public:
        int sumEvenGrandparent(TreeNode* root)
        {
            ret_val = 0;
            dfs(root);
            return ret_val;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :44 ms, 在所有 C++ 提交中击败了94.30% 的用户
内存消耗 :31.7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/