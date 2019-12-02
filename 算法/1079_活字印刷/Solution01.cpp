class Solution
{
    private:
    
        void helper(    int&                    ret_val     ,
                        vector<int>&            vi          ,
                        vector<int>&            visited     
        )
        {
            
            ret_val++;
            for (int i = 0; i < vi.size();i++)
            {
                if (visited[i] == 1)
                {
                    continue;
                }
                if(   i > 0
                   && vi[i] == vi[i - 1] 
                   && visited[i-1] == 0
                )
                {
                    continue;
                }
                visited[i] = 1;
                helper(ret_val, vi, visited);
                visited[i] = 0;
            }
        }

    public:
        int numTilePossibilities(string tiles)
        {
            if (tiles.size() <= 1)
            {
                return tiles.size();
            }
            vector<int> vi(tiles.size(), 0);
            vector<int> visited(tiles.size(), 0);
            int         ret_val = 0 ;
            
            for (int i = 0; i < tiles.size(); i++)
            {
                vi[i] = (int)(tiles[i] - 'A');
            }
            
            sort(vi.begin(), vi.end());
            helper(ret_val, vi, visited);
            return ret_val-1; /*去掉空集*/
        }
};

/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了80.00% 的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了100.00%的用户
*/