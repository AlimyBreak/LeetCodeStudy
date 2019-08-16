
int totalHammingDistance(int* nums, int numsSize)
{
    int             ret_val             =   0       ;
    int             bit1_nums           =   0       ;
    int             i                   =   0       ;
    int             j                   =   0       ;
    unsigned int    temp                =   0x01    ;

    for(i = 0; i < 32 ; i++)
    {
        bit1_nums  = 0;
        
        for(j=0;j<numsSize;j++)
        {
            if(temp&nums[j])
            {
               bit1_nums++; 
            }
        }
        temp <<= 1;
        ret_val += bit1_nums*(numsSize-bit1_nums);
    }
    return ret_val;
}
/*
执行结果：
通过
显示详情
执行用时 :92 ms, 在所有 C 提交中击败了24.14% 的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了80.00%的用户
*/

