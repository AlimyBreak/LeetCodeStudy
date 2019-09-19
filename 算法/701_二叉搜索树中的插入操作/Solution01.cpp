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
        TreeNode* __insertNode(TreeNode* node , int val)
        {
            if(node==NULL)
            {
                return new TreeNode(val);
            }
            if(node->val > val)
            {
                node->left = __insertNode(node->left,val);
            }
            else
            {
                node->right = __insertNode(node->right,val);
            }
            return node;
        }
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val)
        {
            return __insertNode(root,val);   
        }
};


/*
执行结果：
通过
显示详情
执行用时 :164 ms, 在所有 C++ 提交中击败了40.41% 的用户
内存消耗 :32.8 MB, 在所有 C++ 提交中击败了74.65%的用户
*/


