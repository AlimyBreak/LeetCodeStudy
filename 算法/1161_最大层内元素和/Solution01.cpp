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
        int maxLevelSum(TreeNode* root)
        {
            queue<TreeNode*>    qtn                             ;
            int                 ret_val             =   0       ;
            int                 num_1               =   0       ;
            int                 num_2               =   0       ;
            int                 i                   =   0       ;
            vector<int>         vi                              ;
            TreeNode*           tnd                 =   NULL    ;
            int                 level_sum           =   0       ;
            if(root)
            {
                qtn.push(root);
                num_1 = 0;
                num_2 = 1;
                while(num_2)
                {
                    num_1       =   num_2   ;
                    num_2       =   0       ;
                    level_sum   =   0       ;
                    for(i = 0 ; i < num_1 ; i++)
                    {
                        tnd = qtn.front();
                        level_sum += tnd->val;
                        if(tnd->left)
                        {
                            num_2++;
                            qtn.push(tnd->left);
                        }
                        if(tnd->right)
                        {
                            num_2++;
                            qtn.push(tnd->right);
                        }
                        qtn.pop();
                    }
                    vi.push_back(level_sum);
                }
                ret_val = 0;
                for(i=1;i<vi.size();i++)
                {
                    if(vi[i] > vi[ret_val])
                    {
                        ret_val = i ;
                    }
                }
                ret_val += 1;
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :272 ms, 在所有 C++ 提交中击败了85.06%的用户
内存消耗 :72.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/