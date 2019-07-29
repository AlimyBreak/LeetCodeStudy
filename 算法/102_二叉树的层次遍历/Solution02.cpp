class Solution
{
    private:
        void __preOrder(TreeNode* node , int depth, vector<vector<int>>& ret_val)
        {
            if(node==NULL)
            {
                return ;
            }
            
            /* 根左右*/
            if(depth>=ret_val.size())
            {
                vector<int> temp;
                temp.push_back(node->val);
                ret_val.push_back(temp);
            }
            else
            {
                ret_val[depth].push_back(node->val);
            }
            
            __preOrder(node->left,depth+1,ret_val);
            __preOrder(node->right,depth+1,ret_val);            
        }
        
    public:
        vector<vector<int>> levelOrder(TreeNode* root)
        {
            vector<vector<int>> ret_val;
            __preOrder(root,0,ret_val);
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了16.73%的用户
内存消耗 :15.7 MB, 在所有 C++ 提交中击败了5.05%的用户
*/

