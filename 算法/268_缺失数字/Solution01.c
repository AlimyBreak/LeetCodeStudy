
/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例 1:
输入: [3,0,1]
输出: 2
示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
*/


int missingNumber(int* nums, int numsSize)
{
    int ret_val = 0;
    for(int i = 0; i < numsSize ; i++)
    {
        ret_val ^= nums[i];
        ret_val ^= i;
    }
    
    ret_val ^= numsSize;    
    return ret_val;
}
/*
122 / 122 个通过测试用例
	状态：通过
执行用时：20 ms
提交时间：0 分钟之前
执行用时 : 20 ms, 在Missing Number的C提交中击败了62.69% 的用户
内存消耗 : 7.9 MB, 在Missing Number的C提交中击败了8.37% 的用户
*/

int missingNumber(int* nums, int numsSize){
    
    unsigned long int sum = numsSize*(numsSize+1)/2;
    for(int i = 0; i < numsSize ; i++)
    {
        sum -= nums[i];
    }
    return sum;   
}

/*
122 / 122 个通过测试用例
	状态：通过
执行用时：32 ms
提交时间：0 分钟之前
执行用时 : 32 ms, 在Missing Number的C提交中击败了33.55% 的用户
内存消耗 : 7.6 MB, 在Missing Number的C提交中击败了33.02% 的用户
*/



