class Solution
{
    public:
        int singleNonDuplicate(vector<int>& nums)
        {
            int left    =   0               ;
            int right   =   nums.size()-1   ;
            int mid     =   0               ;
            
            
            while(left <= right)
            {
                mid = left + (right - left ) / 2;
                
                /*最右边*/
                if(   (mid == nums.size()-1) 
                   || (mid == 0)
                )
                {
                    break;
                }
                else
                {
                    /*mid 是奇数*/
                    if(mid & 0x01)
                    {
                        if(nums[mid] == nums[mid-1])
                        {
                            left = mid + 1;
                        }
                        // nums[mid] != nums[mid-1]
                        else
                        {
                            if(nums[mid]!=nums[mid+1])
                            {
                                //找到了
                                break;
                            }
                            else
                            {
                                right = mid - 1;
                            }
                        }
                    }
                    /*mid是偶数*/
                    else
                    {
                        if(nums[mid] == nums[mid + 1])
                        {
                            left = mid + 1;
                        }
                        else 
                        {
                            if(nums[mid] == nums[mid-1])
                            {
                                right = mid - 1;
                            }
                            else
                            {
                                // 找到了
                                break;
                            }
                        }
                        
                    }
                }
            }
            
            return nums[mid];


        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了97.08% 的用户
内存消耗 :9.6 MB, 在所有 cpp 提交中击败了5.31%的用户
*/