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
    
        void helper (   TreeNode*&  ret_val     ,
                        TreeNode*   node        , 
                        TreeNode*   p           ,
                        TreeNode*   q
        )
        {
            if(node==NULL)
            {
                return;
            }
            
            if(node->val < p->val && node->val < q->val)
            {
                helper(ret_val,node->right,p,q);
                return;
            }
            
            if(node->val > p->val && node->val > q->val)
            {
                helper(ret_val,node->left,p,q);
                return;
            }
            ret_val = node;
            return;
            
            
            
            
            
        }
    
    
    public:
        TreeNode* lowestCommonAncestor( TreeNode*   root    ,
                                        TreeNode*   p       ,
                                        TreeNode*   q
                                       )
        {
            TreeNode* ret_val = NULL;
            helper(ret_val,root,p,q);
            return ret_val;
        
        }
};


/*
执行结果：
通过
显示详情
执行用时 :40 ms, 在所有 cpp 提交中击败了82.59% 的用户
内存消耗 :25.5 MB, 在所有 cpp 提交中击败了96.73%的用户
*/