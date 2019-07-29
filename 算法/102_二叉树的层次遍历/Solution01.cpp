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
        vector<vector<int>> levelOrder(TreeNode* root)
        {
            vector<vector<int>>     ret_val             ;
            vector<int>             level_vector        ;
            queue<TreeNode*>        qn                  ;
            TreeNode*               temp        = NULL  ;
            int                     num_1       = 0     ;
            int                     num_2       = 0     ;
            int                     i           = 0     ;
        
            if( root == NULL )
            {
                return ret_val;
            }
            else
            {
                qn.push(root);
                num_1 = 0;
                num_2 = 1;
                while(1)
                {
                    num_1 = num_2           ;
                    num_2 = 0               ;
                    level_vector.clear()    ;
                    for(i = 0; i < num_1 ; i++)
                    {
                        temp = qn.front();
                        if(temp->left)
                        {
                            qn.push(temp->left);
                            num_2++;
                        }
                        if(temp->right)
                        {
                            qn.push(temp->right);
                            num_2++;
                        }
                        level_vector.push_back(temp->val);
                        qn.pop();
                    }
                    ret_val.push_back(level_vector);
                    if(num_2==0)
                    {
                        break;
                    }
                }
                return ret_val;
        }
    }
};

/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 C++ 提交中击败了67.53%的用户
内存消耗 :13.7 MB, 在所有 C++ 提交中击败了76.76%的用户
*/
