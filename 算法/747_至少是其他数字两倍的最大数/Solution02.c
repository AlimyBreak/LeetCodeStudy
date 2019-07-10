/*
在一个给定的数组nums中，总是存在一个最大元素 。
查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
如果是，则返回最大元素的索引，否则返回-1。
示例 1
输入 nums = [3, 6, 1, 0]
输出 1
解释 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.

示例 2
输入 nums = [1, 2, 3, 4]
输出 -1
解释 4没有超过3的两倍大, 所以我们返回 -1.
提示
    nums 的长度范围在[1, 50].
    每个 nums[i] 的整数范围在 [0, 99].
*/


/*
方法2:将原始数据heapify为大顶堆,取堆顶元素(最大的元素)和孩子节点中较大的值(第二大的元素)做比较,若比较符合条件,再通过最大值去查询索引.
显然,也可以使用索引堆降低查询索引的时间,此处未实现。
*/
void __shift_down(  int*    data    ,
                    int     size    ,
                    int     ind
                 )
{
    int moreBiggerIndex =   0;
    int temp            =   0;
    while(2*ind<=size) /* 有左孩子就是有孩子*/
    {
        moreBiggerIndex = 2*ind;
        if(  ( moreBiggerIndex+1        <=  size                    )
           &&( data[moreBiggerIndex+1]  >   data[moreBiggerIndex]   )
        )
        {
            moreBiggerIndex += 1; /* 更新到右孩子的索引*/    
        }
        
        if(data[ind]<data[moreBiggerIndex])
        {
            /*交换元素以使堆的性质得到满足*/
            temp                    =   data[ind];
            data[ind]               =   data[moreBiggerIndex];
            data[moreBiggerIndex]   =   temp;
            ind                     =   moreBiggerIndex;
        }
        else
        {
            break;
        }

    }
}

/*大顶堆Heapify*/
void maxHeapify(int* nums , int size)
{
    int i = 0;
    for(i=size/2;i>=1;i--)
    {
        __shift_down(nums,size,i);
    }
}



int dominantIndex(int* nums, int numsSize)
{
    int     ret_val         = -1;
    int*    nums_buf        = NULL;
    int     i               = 0;
    int     secondMaxInd    = 0;
    int     finded          = 0;
    do
    {
        if(numsSize == 1)
        {
            ret_val = 0;
            break;
        }
        
        nums_buf =  (int*)malloc(sizeof(int)*(numsSize+1));
        if(nums_buf==NULL)
        {
            break;
        }
        nums_buf[0] = 0;
        for(i=1;i<=numsSize;i++)
        {
            nums_buf[i] = nums[i-1];
        }
        maxHeapify(nums_buf,numsSize);
        secondMaxInd = 2;/*根节点的孩子节点编号只能是2或者3*/
        if(   ((secondMaxInd+1)<=numsSize)
            &&(nums_buf[secondMaxInd+1]>nums_buf[secondMaxInd])
        )
        {
            secondMaxInd++;/* 更新到右孩子的索引*/
        }
        
        if(nums_buf[1] >= 2*nums_buf[secondMaxInd])
        {
            ret_val = nums_buf[1];
            finded = 1;
        }
    }while(0);
    
    if(nums_buf!=NULL)
    {
        free(nums_buf);
        nums_buf = NULL;
    }
    
    if(finded!=0)
    {
        /*查询索引*/
        for(i=0;i<numsSize;i++)
        {
            if(nums[i]==ret_val)
            {
                ret_val = i;
                break;
            }
        }
    }
    
    return ret_val;
}


/*
执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了92.65% 的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了80.77%的用户
*/