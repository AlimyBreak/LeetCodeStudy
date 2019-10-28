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
        
        void __dfsTree( TreeNode*   node    ,
                        int         _max   ,
                        int         _min
                      )
        {
            if(node==NULL)
            {
                return ;
            }
            _max = max(node->val,_max);
            _min = min(node->val,_min);
            
            /*叶子节点*/
            if(node->left == NULL && node->right == NULL)
            {
                ret_val = max(ret_val,abs(_max-_min));
            }
            
            //
            __dfsTree(node->left,_max,_min);
            __dfsTree(node->right,_max,_min);
        }
        
    public:
    
        int maxAncestorDiff(TreeNode* root)
        {
            ret_val = 0;
            if(root)
            {
                __dfsTree(root,root->val,root->val);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了83.94% 的用户
内存消耗 :12.3 MB, 在所有 cpp 提交中击败了100.00%的用户
*/