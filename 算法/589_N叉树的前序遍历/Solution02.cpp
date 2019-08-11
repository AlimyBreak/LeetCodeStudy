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
    private:
        vector<int> ret_val;

    public:
        vector<int> preorder(Node* root)
        {
            vector<int>     ret_val     ;
            stack<Node*>    sn          ;
            Node*           temp        ;
            int             size = 0    ;
            int             i    = 0    ;
            
            if(root!=NULL)
            {
                sn.push(root);

                while(!sn.empty())
                {
                    temp = sn.top();
                    sn.pop();
                    ret_val.push_back(temp->val);
                    size = temp->children.size();
                    for(i=size-1;i>=0;i--)
                    {
                        sn.push(temp->children[i]);
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
执行用时 :372 ms, 在所有 C++ 提交中击败了17.57% 的用户
内存消耗 :32.9 MB, 在所有 C++ 提交中击败了71.23%的用户
*/