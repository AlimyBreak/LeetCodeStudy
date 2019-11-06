class Solution
{
    private:
        struct cmp
        {
            template<typename T, typename U>
            bool operator()(T const& left, U const &right)
            {
                /*小顶堆*/
                if (left.second > right.second)
                {
                    return true;
                }
                else
                {
                return false;
                }
            }
        };


    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
        {
            priority_queue<pair<int,unsigned long>,vector<pair<int,unsigned long >>,cmp> pq;
            vector<vector<int>>     ret_vvi                 ;
            int                     i           =   0       ;
            
            
            for(i=0;i<points.size();i++)
            {
                pq.push(make_pair(i,points[i][0]*points[i][0]+points[i][1]*points[i][1]));
            }
            for(i=0;i<K;i++)
            {
                ret_vvi.push_back(points[pq.top ().first]);
                pq.pop();
            }
            return ret_vvi;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :316 ms, 在所有 cpp 提交中击败了74.78% 的用户
内存消耗 :45 MB, 在所有 cpp 提交中击败了45.59%的用户
*/