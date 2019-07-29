/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector<int>> levelOrder(Node* root)
        {
            vector<vector<int>>     ret_val             ;
            vector<int>             level_vector        ;
            queue<Node*>            qn                  ;
            Node*                   temp        = NULL  ;
            int                     num_1       = 0     ;
            int                     num_2       = 0     ;
            int                     i           = 0     ; 
            int                     j           = 0     ;
            
            if(root==NULL)
            {
                return ret_val;
            }
            
            qn.push(root)   ;
            num_1 = 0       ;
            num_2 = 1       ;
            while(1)
            {
                level_vector.clear();
                num_1   =   num_2   ;
                num_2   =   0       ;
                for(i=0;i<num_1;i++)
                {
                    temp = qn.front();
                    for(j = 0; j < temp->children.size();j++)
                    {
                        qn.push(temp->children[j]);
                        num_2++;
                    }
                    level_vector.push_back(temp->val);
                    qn.pop();
                }
                ret_val.push_back(level_vector);
                if( num_2 == 0 )
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
执行用时 :388 ms, 在所有 C++ 提交中击败了9.38%的用户
内存消耗 :33.4 MB, 在所有 C++ 提交中击败了95.49%的用户
*/

