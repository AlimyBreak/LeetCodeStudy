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
        

        void __dfsSubTree(TreeNode* pnode,TreeNode* cnode)
        {
            int temp = 0;
            if(cnode==NULL)
            {
                return ;
            }
            /*根左右*/
            temp = abs(pnode->val - cnode->val);
            if( temp > ret_val)
            {
                ret_val = temp;
            }
            
            __dfsSubTree(pnode,cnode->left);
            __dfsSubTree(pnode,cnode->right);
            
        }
        
        void __dfsTree(TreeNode* node)
        {
            if(node==NULL)
            {
                return;
            }
            // 根左右
            __dfsSubTree(node,node->left);
            __dfsSubTree(node,node->right);
            __dfsTree(node->left);
            __dfsTree(node->right);
            
        }
        
    public:
    
        int maxAncestorDiff(TreeNode* root)
        {
            ret_val = 0;
            __dfsTree(root);
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :192 ms, 在所有 cpp 提交中击败了11.40% 的用户
内存消耗 :11.4 MB, 在所有 cpp 提交中击败了100.00%的用户
*/