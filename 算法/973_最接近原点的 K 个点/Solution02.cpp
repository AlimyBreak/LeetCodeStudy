class Solution
{
    private:
        struct cmp
        {
            template<typename T, typename U>
            bool operator()(T const& left, U const &right)
            {
                /*大顶堆*/
                if (left.second < right.second)
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
            unsigned long           square_sum  =   0       ;

            for(i=0;i<points.size();i++)
            {
                square_sum = points[i][0]*points[i][0]+points[i][1]*points[i][1];
                if(pq.size() < K )
                {
                    pq.push(make_pair(i,square_sum));
                }
                else
                {
                    if(square_sum < pq.top().second)
                    {
                        pq.pop();
                        pq.push(make_pair(i,square_sum));
                    }
                }
            }


            for(i=0;i<K;i++)
            {
                ret_vvi.push_back(points[pq.top ().first]);
                pq.pop();
            }
            
            
            reverse(ret_vvi.begin(),ret_vvi.end());

            
            return ret_vvi;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :260 ms, 在所有 cpp 提交中击败了95.03% 的用户
内存消耗 :42.1 MB, 在所有 cpp 提交中击败了63.61%的用户
*/