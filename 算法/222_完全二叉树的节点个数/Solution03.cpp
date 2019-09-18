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
            queue<TreeNode*>        qtn                     ;
            TreeNode*               temp        =   NULL    ;
            int                     ret_val     =   0       ;
            int                     numNull     =   0       ;
            int                     numLevel    =   0       ;
            int                     num_1       =   0       ;
            int                     num_2       =   0       ;
            
            if(root)
            {
                qtn.push(root);
                num_2 = 1;
                num_1 = 0;
                while(1)
                {
                    numLevel++; /*计算层数*/
                    num_1 = num_2;
                    num_2 = 0;
                    for(int i = 0; i < num_1 ; i++)
                    {
                        temp = qtn.front();
                        qtn.pop();
                        if(temp->left!=NULL)
                        {
                            qtn.push(temp->left);
                            num_2++;
                        }
                        else
                        {
                            numNull++;
                        }
                        if(temp->right!=NULL)
                        {
                            qtn.push(temp->right);
                            num_2++;
                        }
                        else
                        {
                            numNull++;
                        }
                    }
                    /*完全二叉树非满二叉树*/
                    if(numNull!=0)
                    {
                        numLevel++;
                        break;
                    }
                    /*满二叉树*/
                    if(num_2==0)
                    {
                        numNull = 0;
                    }
                }
                return pow(2,numLevel)-1-numNull;
            }
            else
            {
                return 0;
            }
        }
};


/*
执行结果：
通过
显示详情
执行用时 :72 ms, 在所有 C++ 提交中击败了27.59% 的用户
内存消耗 :29.3 MB, 在所有 C++ 提交中击败了6.98%的用户
*/