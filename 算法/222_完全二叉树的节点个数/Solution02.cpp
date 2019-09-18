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
    public:
        int countNodes(TreeNode* root)
        {
            queue<TreeNode*>        qtn                 ;
            TreeNode*               temp    =   NULL    ;
            int                     ret_val =   0       ;
            int                     num_1   =   0       ;
            int                     num_2   =   0       ;
            
            if(root)
            {
                qtn.push(root);
                num_2 = 1;
                num_1 = 0;
                
                while(!qtn.empty())
                {
                    ret_val += num_2;
                    num_1 = num_2;
                    num_2 = 0;
                    for(int i = 0 ; i < num_1;i++)
                    {
                        temp = qtn.front();
                        qtn.pop();
                        if(temp->left)
                        {
                            qtn.push(temp->left);
                            num_2++;
                        }
                        if(temp->right)
                        {
                            qtn.push(temp->right);
                            num_2++;
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
执行用时 :80 ms, 在所有 C++ 提交中击败了15.54% 的用户
内存消耗 :29 MB, 在所有 C++ 提交中击败了17.44%的用户
*/