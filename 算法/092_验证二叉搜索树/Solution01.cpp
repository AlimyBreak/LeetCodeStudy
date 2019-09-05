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
        bool ret_val;
        
        void __midOrder(TreeNode* node,stack<int>& si)
        {
            if(  (node==NULL)
               ||(ret_val == false)
            )
            {
                return;
            }
            
            __midOrder(node->left,si);
            if((si.size()<1) || (si.top() < node->val))
            {
                si.push(node->val);
            }
            else
            {
                ret_val = false;
                return;
            }
            __midOrder(node->right,si);
        }
    
    public:
        bool isValidBST(TreeNode* root)
        {
            stack<int> sil;
            ret_val = true;
            __midOrder(root,sil);
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :32 ms, 在所有 C++ 提交中击败了19.37% 的用户
内存消耗 :21.1 MB, 在所有 C++ 提交中击败了7.93%的用户
*/