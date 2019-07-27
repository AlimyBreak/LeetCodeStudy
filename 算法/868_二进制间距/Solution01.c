int binaryGap(int N)
{
    int arr[32] =
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
    int index1      =   -1  ;
    int index2      =   -1  ;
    int i           =   0   ;
    int max_marge   =   0   ;
    int temp_marge  =   0   ;
    while(i<=31)
    {
        if(N&arr[i])
        {
            index1 = index2;
            index2 = i;
        }
        
        if(  (index1!=-1)
           &&(index2!=-1)
        )
        {
            temp_marge = index2 - index1;
            if(temp_marge>max_marge)
            {
                max_marge = temp_marge;
            }
        }
        i++;
    }
    return max_marge;
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了30.19%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了88.00%的用户
*/

