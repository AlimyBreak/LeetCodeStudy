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
        TreeNode* insertIntoBST(TreeNode* root, int val)
        {
            TreeNode*   dstNode =   new TreeNode(val)   ;
            TreeNode*   temp    =   NULL                ;
            if(root!=NULL)
            {
                temp = root;
                while(1)
                {
                    if(temp->val > val )
                    {
                        if(temp->left == NULL)
                        {
                            temp->left = dstNode;
                            break;
                        }
                        else
                        {
                            temp = temp ->left;
                        }
                    }
                    else
                    {
                        if(temp->right == NULL)
                        {
                            temp->right = dstNode;
                            break;
                        }
                        else
                        {
                            temp = temp ->right; 
                        }
                    }
                }
            }
            else
            {
                root = dstNode;
            }
            return root;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :116 ms, 在所有 C++ 提交中击败了83.39% 的用户
内存消耗 :32.6 MB, 在所有 C++ 提交中击败了98.12%的用户
*/