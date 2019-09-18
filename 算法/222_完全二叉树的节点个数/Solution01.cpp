/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        int __nodeNum(TreeNode* node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return 1 + __nodeNum(node->left) + __nodeNum(node->right);
        }
    
    public:
        int countNodes(TreeNode* root)
        {
            if(root!=NULL)
            {
                return 1 + __nodeNum(root->left) + __nodeNum(root->right); 
            }
            return 0;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :48 ms, 在所有 C++ 提交中击败了74.73% 的用户
内存消耗 :28.6 MB, 在所有 C++ 提交中击败了86.43%的用户
*/