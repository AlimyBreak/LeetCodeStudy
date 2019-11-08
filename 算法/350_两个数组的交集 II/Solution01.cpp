class Solution
{
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
        {
            map<int,int>    mii1            ;
            map<int,int>    mii2            ;
            vector<int>     ret_val         ;
            int             i       =   0   ;
            int             j       =   0   ;
            int             temp    =   0   ;


            for(i = 0 ; i < nums1.size() ; i++)
            {
                if(mii1.count(nums1[i]))
                {
                    mii1[nums1[i]] ++;
                    
                }
                else
                {
                    mii1[nums1[i]] = 1;
                }
            }
            
            
            for(i = 0 ; i < nums2.size() ; i++)
            {
                if(mii2.count(nums2[i]))
                {
                    mii2[nums2[i]] ++;
                    
                }
                else
                {
                    mii2[nums2[i]] = 1;
                }
            }
            
            
            map<int,int>::iterator iter = mii1.begin();
            while(iter!=mii1.end())
            {
                temp = iter->first;
                if(mii2.count(temp))
                {
                    j = min(mii1[temp],mii2[temp]);
                    while(j--)
                    {
                        ret_val.push_back(temp);
                    }
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
执行用时 :20 ms, 在所有 cpp 提交中击败了20.76% 的用户
内存消耗 :9.8 MB, 在所有 cpp 提交中击败了5.03%的用户
*/