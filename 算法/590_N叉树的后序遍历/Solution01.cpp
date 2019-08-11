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
    
        void __PostOrder(Node* node)
        {
            int size = 0;
            int i    = 0;
            if(node==NULL)
            {
                return; 
            }
            else
            {
                size = node->children.size();
                for(i=0;i<size;i++)
                {
                    __PostOrder(node->children[i]);
                }
                ret_val.push_back(node->val);
            }
        }
    
    public:
        vector<int> postorder(Node* root) 
        {
            ret_val.clear();
            __PostOrder(root);
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :216 ms, 在所有 C++ 提交中击败了84.34% 的用户
内存消耗 :32.7 MB, 在所有 C++ 提交中击败了78.75%的用户
*/