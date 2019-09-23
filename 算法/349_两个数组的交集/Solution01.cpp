class Solution
{
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
        {
            vector<int>     ret_val     ;
            map<int,int>    mii1        ;
            map<int,int>    mii2        ;
            map<int,int>::iterator   iter;
            int             i           ;
            for(i = 0; i < nums1.size();i++)
            {
                mii1[nums1[i]] = 1;
            }
            for(i = 0; i < nums2.size();i++)
            {
                mii2[nums2[i]] = 1;
            }
            
            iter = mii2.begin();
            while(iter!=mii2.end())
            {
                if(mii1.count(iter->first)==1)
                {
                    ret_val.push_back(iter->first);
                }
                iter++;
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 C++ 提交中击败了80.21% 的用户
内存消耗 :9.8 MB, 在所有 C++ 提交中击败了6.36%的用户
*/