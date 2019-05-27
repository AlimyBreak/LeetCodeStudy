/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的原地算法。
*/


/*
    reverse [left,right] in nums;
*/
void reverse(int* nums , int left , int right)
{
    int swap_times = (right - left + 1) / 2;
    int i          = 0;
    for(i = 0; i < swap_times ; i++)
    {
        //if((left+i)<(right-i)) /*主要是规避自己与自己交换等于时的异或陷阱,但swap_times已经可以确保,屏蔽此处减少判断*/
        //{
            nums[left+i]  = nums[left+i] ^ nums[right-i];
            nums[right-i] = nums[left+i] ^ nums[right-i];
            nums[left+i]  = nums[left+i] ^ nums[right-i];
        //}
        //else
        //{
        //    continue;
        //}
    }
}

void rotate(int* nums, int numsSize, int k)
{
    int temp = 0;
    int j = 0;
    k = k % numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
}


#include <stdio.h>
int main(void)
{
	int nums1[7] = {1,2,3,4,5,6,7};
	rotate(nums1,7,3);
	for(int i = 0; i < 7 ; i++)
	{
        printf("%d\n",nums1[i]);
	}
	return 0;
}

/*
执行用时 : 24 ms, 在Rotate Array的C提交中击败了83.84% 的用户
内存消耗 : 9 MB, 在Rotate Array的C提交中击败了5.24% 的用户
34 / 34 个通过测试用例
状态：通过
执行用时：32 ms
提交时间：1 分钟之前
*/