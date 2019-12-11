class Solution
{
    public:
    
        vector<int> searchRange(    vector<int>&    nums    ,
                                    int             target
                               )
        {
            vector<int> vi(2,-1);
            int length = nums.size();
            if(length<1)
            {
                return vi;
            }

            int left    =   0           ;
            int right   =   0           ;
            int mid     =   0           ;
            
            /*找最左边界*/
            left    =   0           ;
            right   =   length - 1  ;
            while(left<right)
            {
                mid =   left + ( right - left ) / 2; /*求均值时要求向下取整*/
                if(nums[mid]>=target)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            /*若不存在*/
            if(nums[left]!=target)
            {
                return vi;
            }
            
            vi[0] = left;
            /*找最右边界*/
            right = length-1;
            while(left<right)
            {
                mid = left + (right-left)/2 + 1;    /*求均值时要求向上取整*/
                if(nums[mid]<=target)
                {
                    left = mid;
                }
                else
                {
                    right = mid-1;
                }
            }
            vi[1]=left;
            return vi;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了90.42% 的用户
内存消耗 :10.2 MB, 在所有 cpp 提交中击败了92.16%的用户
*/