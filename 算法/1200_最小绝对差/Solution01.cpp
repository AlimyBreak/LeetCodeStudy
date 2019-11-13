class Solution
{
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr)
        {
            
            
            vector<vector<int>>     vvi                             ;
            int                     min_abs_diff    =   2147483647  ;
            int                     i               =   0           ;            

            sort(arr.begin(),arr.end());
            for( i = 1; i < arr.size() ; i++)
            {
                if(arr[i]-arr[i-1] < min_abs_diff)
                {
                    min_abs_diff = abs(arr[i]-arr[i-1]);
                }
            }
            
            for( i = 1 ; i < arr.size() ; i++)
            {
                if(arr[i]-arr[i-1] == min_abs_diff)
                {
                    vector<int> vi;
                    vi.push_back(arr[i-1]);
                    vi.push_back(arr[i]);
                    vvi.push_back(vi);
                }   
            }
            
            return vvi;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :172 ms, 在所有 cpp 提交中击败了19.70% 的用户
内存消耗 :17.9 MB, 在所有 cpp 提交中击败了100.00%的用户
*/