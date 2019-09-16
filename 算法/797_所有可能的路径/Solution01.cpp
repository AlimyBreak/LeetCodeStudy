class Solution
{
    private:
        vector<vector<int>> ret_val;
        int max_level;
        void __visited(vector<vector<int>>& graph, int level, vector<int> last_vec)
        {

            vector<int> cur_vec(last_vec);

            cur_vec.push_back(level);

            if (level == max_level)
            {
                ret_val.push_back(cur_vec);
                return;
            }
            
            /*防止成环的死循环*/
            if(cur_vec.size() > max_level)
            {
                return ;
            }
            for (int i = 0; i < graph[level].size(); i++)
            {
                __visited(graph, graph[level][i], cur_vec);
            }
        }
        
    public:
        /* graph 是邻接表保存的*/
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
        {
            
            vector<int> temp;
            ret_val.clear();
            max_level = graph.size() - 1;
            if(max_level >= 0)
            {
                __visited(graph,0,temp);
            }
            return ret_val;
        }
};



/*
执行结果：
通过
显示详情
执行用时 :276 ms, 在所有 C++ 提交中击败了6.94% 的用户
内存消耗 :20.4 MB, 在所有 C++ 提交中击败了12.00%的用户
*/