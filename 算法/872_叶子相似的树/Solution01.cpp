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
    
        void genSeriesRoot  (   vector<int>&    vi      ,
                                TreeNode*       node    
                            )
        {
            if(node==NULL)
            {
                return;
            }
            
            
            genSeriesRoot(vi,node->left);
            if(node->left==NULL && node->right== NULL)
            {
                vi.push_back(node->val);
                return;
            }
            genSeriesRoot(vi,node->right);
        }
    
    
    public:
        bool leafSimilar(TreeNode* root1, TreeNode* root2)
        {
            
            vector<int>    vi1;
            vector<int>    vi2;
            genSeriesRoot(vi1,root1);
            genSeriesRoot(vi2,root2);
            
            if(vi1.size()!=vi2.size())
            {
                return false;
            }
            
            for(int i = 0 ; i < vi1.size() ;i++)
            {
                if(vi1[i]!=vi2[i])
                {
                    return false;
                }   
            }
            return true;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了58.47% 的用户
内存消耗 :14.1 MB, 在所有 cpp 提交中击败了64.13%的用户
*/