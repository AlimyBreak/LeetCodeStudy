

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
        int rangeSumBST(TreeNode* root, int L, int R)
        {
            stack<TreeNode*>    stn             ;
            int                 ret_val = 0     ;
            TreeNode*           temp    = NULL  ;
            if(root!=NULL)
            {
                stn.push(root);
                while(!stn.empty())
                {
                    temp = stn.top();
                    stn.pop();
                    if(temp == NULL)
                    {
                        continue;
                    }

                    if(temp->val < L )
                    {
                        stn.push(temp->right);
                    }
                    else if(temp->val > R)
                    {
                        stn.push(temp->left);
                    }
                    else
                    {
                        ret_val += temp->val;
                        stn.push(temp->right);
                        stn.push(temp->left);
                    }
                }
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :276 ms, 在所有 C++ 提交中击败了28.21% 的用户
内存消耗 :41.1 MB, 在所有 C++ 提交中击败了91.02%的用户
*/



class Solution
{
    public:
        int rangeSumBST(TreeNode* root, int L, int R)
        {
            stack<TreeNode*>    stn             ;
            int                 ret_val = 0     ;
            TreeNode*           temp    = NULL  ;
            if(root!=NULL)
            {
                stn.push(root);
                while(!stn.empty())
                {
                    temp = stn.top();
                    stn.pop();

                    if(temp->val < L )
                    {
                        if(temp->right)
                        {
                            stn.push(temp->right);
                        }
                    }
                    else if(temp->val > R)
                    {
                        if(temp->left)
                        {
                            stn.push(temp->left);
                        }
                    }
                    else
                    {
                        ret_val += temp->val;
                        if(temp->right)
                        {
                            stn.push(temp->right);
                        }
                        if(temp->left)
                        {
                            stn.push(temp->left);
                        }
                    }
                }
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :276 ms, 在所有 C++ 提交中击败了28.21% 的用户
内存消耗 :41.1 MB, 在所有 C++ 提交中击败了87.11%的用户
*/