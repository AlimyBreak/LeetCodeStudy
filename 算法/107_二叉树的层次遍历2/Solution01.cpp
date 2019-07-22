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
        vector<vector<int>> levelOrderBottom(TreeNode* root)
        {
            stack<vector<int>>      svi                 ;   /*层次遍历辅助队列*/
            queue<TreeNode*>        qt                  ;   /*逆序层次遍历辅助栈*/
            vector<vector<int>>     vvi                 ;   /*返回数据结构*/
            vector<int>             vi                  ;   /*存储每层遍历结果*/
            TreeNode*               temp    =   NULL    ;
            int                     num_1   =   0       ;
            int                     num_2   =   0       ;
            int                     i       =   0       ;
            
            if(root==NULL)
            {
                return vvi;
            }
            
            qt.push(root);
            num_1 = 0;
            num_2 = 1;
        
            /*从上而下的层序遍历并将结果推入栈*/
            while(num_2!=0)
            {
                num_1 = num_2;
                num_2 = 0;
                vi.clear();
                for(i=0;i<num_1;i++)
                {
                    temp = qt.front();
                    if(temp->left)
                    {
                        num_2 ++;
                        qt.push(temp->left);
                    }
                    
                    if(temp->right)
                    {
                        num_2 ++;
                        qt.push(temp->right);
                    }
                    
                    vi.push_back(temp->val);
                    qt.pop();
                }
                svi.push(vi);
            }
            
            /*依次出栈,完成逆序*/
            while(svi.empty()!=true)
            {
                vvi.push_back(svi.top());
                svi.pop();
            }
            return vvi;
       }
};


/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 C++ 提交中击败了82.26%的用户
内存消耗 :13.6 MB, 在所有 C++ 提交中击败了96.42%的用户
*/