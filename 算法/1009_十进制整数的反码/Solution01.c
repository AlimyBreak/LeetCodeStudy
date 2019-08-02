int bitwiseComplement(int num)
{
    const unsigned int arr[32] =
    {
        0x00000001,0x00000002,0x00000004,0x00000008,
        0x00000010,0x00000020,0x00000040,0x00000080, 
        0x00000100,0x00000200,0x00000400,0x00000800, 
        0x00001000,0x00002000,0x00004000,0x00008000, 
        0x00010000,0x00020000,0x00040000,0x00080000,
        0x00100000,0x00200000,0x00400000,0x00800000, 
        0x01000000,0x02000000,0x04000000,0x08000000, 
        0x10000000,0x20000000,0x40000000,0x80000000       
    };
    int ret_val = 0;
    int i       = 0;
    int mask    = -1;
    do
    {
        if(num<0)
        {
            break;
        }
        if(num==0)
        {
            ret_val = 1;
            break;
        }
        
        for(i = 31; i >= 0;i--)
        {
            if(num&arr[i])
            {
                break;
            }
            else
            {
                mask ^= arr[i];
            }
        }
        ret_val = num^mask;
    }while(0);
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了77.22%的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了5.88%的用户
*/