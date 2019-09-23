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
        int findBottomLeftValue(TreeNode* root)
        {

            queue<TreeNode*>    qtn             ;
            int                 ret_val = 0     ;
            TreeNode*           temp            ;
            int                 num_1   = 0     ;
            int                 num_2   = 1     ;
            int                 i       = 0     ;
            int                 j       = 0     ;
        
            qtn.push(root);
            while(!qtn.empty())
            {
                num_1 = num_2;
                num_2 = 0;
                ret_val = qtn.front()->val; /*行首的指针节点的值*/
                for(i=0;i<num_1;i++)
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
            return ret_val;
    }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了88.68% 的用户
内存消耗 :20.8 MB, 在所有 C++ 提交中击败了66.24%的用户
*/