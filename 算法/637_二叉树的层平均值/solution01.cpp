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
        vector<double> averageOfLevels(TreeNode* root) 
        {
            vector<double>      ret_val         ;
            queue<TreeNode*>    qt              ;
            int                 num_1   = 0     ;
            int                 num_2   = 0     ;
            TreeNode*           temp_tn = NULL  ;
            double              temp_db = 0     ;
            int                 i       = 0     ;
            if(root!=NULL)
            {
                qt.push(root);
                num_2 = 1;
                num_1 = 0;
                
                while(!qt.empty())
                {
                    num_1   = num_2     ;
                    num_2   = 0         ;
                    temp_db = 0         ;
                    
                    for(i = 0; i < num_1 ; i++)
                    {
                        temp_tn =   qt.front();
                        temp_db +=  temp_tn->val;
                        if(temp_tn->left!=NULL)
                        {
                            qt.push(temp_tn->left);
                            num_2++;
                        }
                        if(temp_tn->right!=NULL)
                        {
                            qt.push(temp_tn->right);
                            num_2++;
                        }
                        
                        qt.pop();
                    }
                    ret_val.push_back(temp_db/num_1);
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 C++ 提交中击败了72.10% 的用户
内存消耗 :21.7 MB, 在所有 C++ 提交中击败了83.54%的用户
*/


