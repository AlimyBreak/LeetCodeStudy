class Solution
{
    public:
        bool uniqueOccurrences(vector<int>& arr)
        {
            map<int,int> mii            ;
            set<int>     si             ;
            int          i      = 0     ;
            
            
            for(i=0;i<arr.size();i++)
            {
                if(mii.count(arr[i]))
                {
                    mii[arr[i]]++;
                }
                else
                {
                    mii[arr[i]] = 1;
                }
            }
            
            /*迭代器遍历*/
            map<int,int>::iterator iter;
            iter = mii.begin();
            while(iter != mii.end())
            {
                si.insert(iter->second);
                iter++;
            }
            return ( mii.size() == si.size() );
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了88.86%的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了100.00%的用户
*/