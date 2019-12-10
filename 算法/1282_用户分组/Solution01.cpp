class Solution
{
    public:
        vector<vector<int>> groupThePeople(vector<int>& groupSizes)
        {
            vector<vector<int>> vvi                     ;
            int                 n   = groupSizes.size() ;

            if(n < 1)
            {
                return vvi;
            }
            
            vector<int>         vi_capacity             ;
            vector<int>         vi_count                ;
            int                 i           =   0       ;
            int                 j           =   0       ;
            int                 flag        =   0       ;
            

            
            for(i = 0 ; i < n ; i++)
            {
                flag = -1; /*需要重新建立一个temp*/
                for(j=vi_capacity.size()-1;j>=0;j--)
                {
                    if(    ( vi_capacity[j] == groupSizes[i] )
                        && ( vi_count[j] < vi_capacity[j]    )
                    )
                    {
                        flag = j;
                        break;
                    }
                }
                
                if(flag == -1) /*需要新建一个来存放 i */
                {
                    vector<int> vi_temp(groupSizes[i],0);
                    vi_temp[0] = i;
                    vi_capacity.push_back(groupSizes[i]);
                    vi_count.push_back(1);
                    vvi.push_back(vi_temp);

                }
                else /*在flag对应vvi位置存放i */
                {
                    vvi[j][vi_count[j]] =   i                   ;
                    vi_count[j]         =   vi_count[j] + 1     ;
                }

            }
            
            return vvi;
            
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :44 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :12 MB, 在所有 cpp 提交中击败了100.00%的用户
*/