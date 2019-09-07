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
        vector<string> ret_val;
        void __pathRoot2Leaves(TreeNode* node,string& s)
        {
            string s1(s);
            s1 += to_string(node->val);
            if(  (node->left==NULL)
               &&(node->right==NULL)
            )
            {
                ret_val.push_back(s1);
            }
            
            s1 += "->";
            if(node->left)
            {
                __pathRoot2Leaves(node->left,s1);
            }
            
            if(node->right)
            {
                __pathRoot2Leaves(node->right,s1);
            }
        }
    
    public:
        vector<string> binaryTreePaths(TreeNode* root)
        {
            ret_val.clear();
            string s;
            if(root!=NULL)
            {
                __pathRoot2Leaves(root,s);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了93.07% 的用户
内存消耗 :11.7 MB, 在所有 C++ 提交中击败了80.95%的用户
*/