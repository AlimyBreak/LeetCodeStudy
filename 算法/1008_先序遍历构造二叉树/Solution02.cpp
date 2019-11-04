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
    
    void add_node(TreeNode*& node, int val)
    {
        if(node == NULL)
        {
            node = new TreeNode(val);
            return;
        }
        
        if( val < node->val)
        {
            add_node(node->left,val);
        }
        else
        {
            add_node(node->right,val);
        }
    }
    
    public:
        TreeNode* bstFromPreorder(vector<int>& preorder)
        {
            TreeNode*   root    =   NULL    ;
            int         i       =   0       ;
            
            for(i = 0 ; i < preorder.size();i++)
            {
                add_node(root,preorder[i]);
            }
            return root;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了74.75% 的用户
内存消耗 :10.8 MB, 在所有 cpp 提交中击败了70.49%的用户
*/