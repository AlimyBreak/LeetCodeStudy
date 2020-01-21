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
        void midOrderTravel(TreeNode* node,vector<int>& vi)
        {
            if(node==NULL)
            {
                return ;
            }
            midOrderTravel(node->left,vi);
            vi.push_back(node->val);
            midOrderTravel(node->right,vi);
        }
    
    public:
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
        {
            vector<int> temp1           ;
            vector<int> temp2           ;
            vector<int> ret_val         ;
            int         length1 =   0   ;
            int         length2 =   0   ;
            int         i       =   0   ;
            int         j       =   0   ;.
            
            
            midOrderTravel(root1,temp1);
            midOrderTravel(root2,temp2);
            length1 = temp1.size();
            length2 = temp2.size();

            while(1)
            {
                if(i < length1 && j < length2)
                {
                    if(temp1[i] < temp2[j])
                    {
                        ret_val.push_back(temp1[i]) ;
                        i++;
                    }
                    else
                    {
                        ret_val.push_back(temp2[j]) ;
                        j++;
                    }
                }
                else if(i < length1)
                {
                    ret_val.push_back(temp1[i]) ;
                    i++;
                }
                else if(j < length2)
                {
                    ret_val.push_back(temp2[j]) ;
                    j++;
                }
                else
                {
                    break;
                }
                
                
            }

            return ret_val;
            
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :224 ms, 在所有 C++ 提交中击败了92.91% 的用户
内存消耗 :63.5 MB, 在所有 C++ 提交中击败了6.13%的用户
*/