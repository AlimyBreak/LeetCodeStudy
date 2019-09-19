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
        vector<int> ret_val;
        void __dfsPostOrder(TreeNode* node)
        {
            if(node==NULL)
            {
                return ;
            }
            __dfsPostOrder(node->left);
            __dfsPostOrder(node->right);
            ret_val.push_back(node->val);
        }
    
    public:
        vector<int> postorderTraversal(TreeNode* root)
        {
            ret_val.clear();
            __dfsPostOrder(root);
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了83.30% 的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了43.66%的用户
*/