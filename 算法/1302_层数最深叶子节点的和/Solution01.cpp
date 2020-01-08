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
        int deepestLeavesSum(TreeNode* root)
        {
            int                 layer_sum = 0   ;
            queue<TreeNode *>   qtn             ;
            int                 num_1     = 0   ;
            int                 num_2     = 0   ;
            int                 i         = 0   ;
            TreeNode *          temp      = NULL;
            
            if(root)
            {
                qtn.push(root);
                num_2 = 1;
                num_1 = 0;
                
                while(num_2)
                {
                    num_1       = num_2 ;
                    layer_sum   = 0     ;
                    num_2       = 0     ;
                    for(i = 0 ; i < num_1 ;i++)
                    {
                        temp = qtn.front();
                        layer_sum += temp->val;
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
                        qtn.pop();
                    }   
                }   
            }            
            return layer_sum;
        
        }
};


/*
执行结果：
通过
显示详情
执行用时 :52 ms, 在所有 C++ 提交中击败了72.83% 的用户
内存消耗 :31.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/