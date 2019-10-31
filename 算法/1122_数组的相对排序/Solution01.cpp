class Solution
{
    private:    
        void sort1(map<int,int>& mii ,vector<int>& vi , int left , int right)
        {
            int minIdx = 0;
            int i = 0;
            int j = 0;
            
            for(i=left;i<=right;i++)
            {
                minIdx = i;
                for(j=i+1;j<=right;j++)
                {
                    if(mii[vi[j]] < mii[vi[minIdx]])
                    {
                        swap(vi[j],vi[minIdx]);
                    }
                }
            }
            
        }
        
        void sort2(vector<int>& vi , int left , int right)
        {
            int minIdx      = 0;
            int i           = 0;
            int j           = 0;
            
            for(i=left;i<=right;i++)
            {
                minIdx = i;
                for(j=i+1;j<=right;j++)
                {
                    if(vi[j] < vi[minIdx])
                    {
                        swap(vi[j],vi[minIdx]);
                    }
                }
            }
        }
    
    
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
        {
            map<int,int>    mii;
            vector<int>     ret_val(arr1.size(),0);
            int i           =   0;
            int count1      =   0;
            int count2      =   0;
            
            for(i = 0 ; i < arr2.size() ; i++)
            {
                mii[arr2[i]] = count1++;
            }
            
            count1 = 0                  ;
            count2 = arr1.size() - 1    ;
            
            for(i = 0 ; i < arr1.size() ; i++)
            {
                if(mii.count(arr1[i]))
                {
                    ret_val[count1++] = arr1[i];
                }
                else
                {
                    ret_val[count2--] = arr1[i];
                }
            }
            
            sort1(mii,ret_val,0,count1-1);
            sort2(ret_val,count2+1,arr1.size()-1);

            return ret_val;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :44 ms, 在所有 cpp 提交中击败了5.03% 的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了100.00%的用户
*/