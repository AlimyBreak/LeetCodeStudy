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
    public:
    bool isUnivalTree(TreeNode* root)
    {
        int         val     =   0;
        TreeNode*   temp    =   NULL;
        queue<TreeNode*> qu;     
        
        if(root==NULL)
        {
            return true;
        }
        val = root->val;
        qu.push(root);
        while(qu.empty()!=true)
        {
            temp = qu.front();
            if(temp->val !=val)
            {
                return false;
            }
            if(temp->left)
            {
                qu.push(temp->left);
            }
            if(temp->right)
            {
                qu.push(temp->right);
            }
            qu.pop();   
        }        
        return true;
    }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了61.30% 的用户
内存消耗 :10.6 MB, 在所有 C++ 提交中击败了84.34%的用户
*/

