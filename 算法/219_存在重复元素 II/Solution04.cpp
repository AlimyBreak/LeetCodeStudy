/*
参考了某个题解, 但我忘记了具体是哪个题解.
class Solution
{
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; i++) {
            if(set.contains(nums[i])) {
                return true;
            }
            set.add(nums[i]);
            if(set.size() > k) {
                set.remove(nums[i - k]);
            }
        }
        return false;
    }
}
*/

class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k)
        {
            set<int> s;
            for(int i = 0 ; i < nums.size();i++)
            {
                if(s.count(nums[i]))
                {
                    return true;

                }
                s.insert(nums[i]);
                if(s.size()>k)
                {
                    s.erase(nums[i-k]);
                }
            }
            return false;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :48 ms, 在所有 cpp 提交中击败了52.62% 的用户
内存消耗 :15.3 MB, 在所有 cpp 提交中击败了38.48%的用户
*/