class Solution
{
    public:
        vector<int> arraysIntersection( vector<int>& arr1,
                                        vector<int>& arr2,
                                        vector<int>& arr3
                                      )
        {
            
            vector<int> ret_val         ;
            int         i       =   0   ;
            map<int,int> mii2;
            map<int,int> mii3;
            
            for( i = 0 ; i < arr2.size();i++)
            {
                mii2[arr2[i]] = 1;
            }
            for( i = 0 ; i < arr3.size();i++)
            {
                mii3[arr3[i]] = 1;
            }
            
            for(i = 0 ; i < arr1.size(); i++)
            {
                if(   ( mii2.count(arr1[i]) > 0 )
                   && ( mii3.count(arr1[i]) > 0 )
                )
                {
                    ret_val.push_back(arr1[i]);
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :11.8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/