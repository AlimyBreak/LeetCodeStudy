class Solution
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            vector<int>     ret_val             ;
            map<int,int>    mii                 ;
            int             i           =   0   ;
            
            for(i = 0 ; i < numbers.size() ; i++)
            {
                if(mii.count(numbers[i]))
                {
                    ret_val.push_back(mii[numbers[i]]+1);
                    ret_val.push_back(i+1);
                    break;
                }
                else
                {
                    mii[target-numbers[i]] = i;
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
内存消耗 :9.6 MB, 在所有 cpp 提交中击败了12.46%的用户
*/
