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
        vector<int> postorder(Node* root) 
        {
            vector<int>     ret_val             ;
            stack<Node*>    sn                  ;
            Node*           temp    =   NULL    ;
            int             i       =   0       ;
            int             size    =   0       ;
            
            if(root!=NULL)
            {
                sn.push(root);
                while(!sn.empty())
                {
                    temp = sn.top();
                    sn.pop();
                    ret_val.push_back(temp->val);
                    size = temp->children.size();
                    for(i=0;i<size;i++)
                    {
                        sn.push(temp->children[i]);
                    }
                }
            }
            
            reverse(ret_val.begin(), ret_val.end());
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :208 ms, 在所有 C++ 提交中击败了94.31% 的用户
内存消耗 :32.9 MB, 在所有 C++ 提交中击败了66.88%的用户
*/