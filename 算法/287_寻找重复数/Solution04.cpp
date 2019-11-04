class Solution
{
    /* java ---> C++,todo*/
    public int findDuplicate(int[] nums)
    {
        /**
            快慢指针思想, fast 和 slow 是指针, nums[slow] 表示取指针对应的元素
            注意 nums 数组中的数字都是在 1 到 n 之间的(在数组中进行游走不会越界),
            因为有重复数字的出现, 所以这个游走必然是成环的, 环的入口就是重复的元素, 
            即按照寻找链表环入口的思路来做
        **/
        int fast = 0;
        int slow = 0;
        while(true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast)
            {
                fast = 0;
                while(nums[slow] != nums[fast])
                {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return nums[slow];
            }
        }
    }
}
/*
执行结果：
通过
显示详情
执行用时 :1156 ms, 在所有 c 提交中击败了5.10% 的用户
内存消耗 :8.2 MB, 在所有 c 提交中击败了9.86%的用户
种子取得不好的时候还会:
超出时间限制
*/

