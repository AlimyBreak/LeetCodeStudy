class Solution
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            vector<int> ret_val;
            int left    =   1               ;
            int right   =   numbers.size()  ;
            int mid     =   0               ;
            while(left < right)
            {
                if(numbers[left-1] + numbers[right-1] == target)
                {
                    ret_val.push_back(left);
                    ret_val.push_back(right);
                    break;
                }
                else if(numbers[left-1] + numbers[right-1] < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了97.11% 的用户
内存消耗 :9.4 MB, 在所有 cpp 提交中击败了79.15%的用户
*/