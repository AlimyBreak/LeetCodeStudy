/*

    1 <= heights.length <= 100
    1 <= heights[i] <= 100
*/
class Solution
{
    public:
        int heightChecker(vector<int>& heights)
        {
            int arr[101] = {0,}     ;
            int ret_val  = 0        ;
            int i                   ;
            
            for(i = 0 ; i < heights.size() ; i++)
            {
                arr[heights[i]]++;
            }
            
            for(i = 1 ; i < 101 ; i++)
            {
                arr[i] = arr[i] + arr[i-1];
            }
            
            for(i = 0; i < heights.size(); i++)
            {
                /* 
                    i+1必须在( arr[heights[i]-1],arr[heights[i]]  ] 之间才合法 ,左开右闭区
                    在此区间外就是错误的高度.
                    @xiaxia153
                    不需要排序算法，统计下每个高度有多少人，计算该高度的人应该位于哪个区间，不在这个区间的都是站错的;
                */
                if(   ( i+1 <= arr[heights[i] - 1])
                    ||( i+1 > arr[heights[i]] )
                )
                {
                    ret_val++;
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了86.49% 的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/