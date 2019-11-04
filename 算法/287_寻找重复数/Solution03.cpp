/*
收录一个Joke代码
@湛蓝水晶 https://leetcode-cn.com/problems/find-the-duplicate-number/comments/39533
蒙特卡罗方法
*/
int findDuplicate(int* nums, int numsSize)
{
    srand(time(0));
    int a, b;
    while(true)
    {
        a = rand()%numsSize;
        b = rand()%numsSize;
        if(a == b)
        {
            continue;
        }
        if(nums[a]==nums[b])
        {
            return nums[a];
        }
    }
    return -1;

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

