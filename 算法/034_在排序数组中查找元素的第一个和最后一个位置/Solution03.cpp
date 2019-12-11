class Solution
{
    
    private:
    
        int SearchLeft( vector<int>&    nums    ,
                        int             target  ,
                        int             left    ,
                        int             right
        )
        {
            bool flag = false;
            int  mid  = 0;
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(nums[mid]==target)
                {
                    flag = true;
                    break;
                }
                else if(nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            
            if(flag)
            {
                return SearchLeft(nums,target,0,mid-1);
                
            }
            else
            {
                return right+1;
            }
            
        }
        
        int SearchRight(    vector<int>&    nums    ,
                            int             target  ,
                            int             left    ,
                            int             right   
        )
        {
            bool flag = false;
            int  mid  = 0;
            int  rright = right;
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(nums[mid]==target)
                {
                    flag = true;
                    break;
                }
                else if(nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            
            if(flag)
            {
                return SearchRight(nums,target,mid+1,rright);
                
            }
            else
            {
                return left-1;
            }
        }

    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            vector<int> vi(2,-1);
            int  left    =   0               ; 
            int  right   =   nums.size()-1   ;
            int  mid     =   0               ;
            bool flag    =   false           ;
            
            /*看是否有*/
            while(right >= left)
            {
                mid = left + (right - left)/2;
                if(nums[mid] == target)
                {
                    flag = true;
                    break;
                }
                else if(nums[mid] < target)
                {
                    left  = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            
            if(flag)
            {
                vi[0] = SearchLeft(nums,target,0,mid-1);
                vi[1] = SearchRight(nums,target,mid+1,nums.size()-1);
            }
            
            
            return vi;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了90.42% 的用户
内存消耗 :10.2 MB, 在所有 cpp 提交中击败了89.08%的用户
*/

