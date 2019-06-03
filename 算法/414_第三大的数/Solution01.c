/*
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
示例 1
输入 [3, 2, 1]
输出 1
解释 第三大的数是 1.
示例 2
输入 [1, 2]
输出 2
解释 第三大的数不存在, 所以返回最大的数 2 .
示例 3
输入 [2, 2, 3, 1]
输出 1
解释 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。
*/

#include <stdio.h>

int     count = 0;
int*    arr   = NULL;


void _swap(int* a, int*b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}


void shift_up( int ind )
{
    while(  (arr[ind/2] < arr[ind])   /*大根堆:父节点的值小于新加入的孩子节点,且 ind/2 至少为1 均满足时才交换*/
          &&(ind > 1)
         )
    {
        _swap(&arr[ind/2],&arr[ind]);   /* 交换 */
         ind /= 2;                      /* 待比较对象迁移到父节点*/
    };
}

void shift_down( int ind )
{
    int moreBiggerIndex = 0;
    while(2*ind <=count) /* 有左孩子就是有孩子*/
    {
        moreBiggerIndex = 2*ind;
        if(  (moreBiggerIndex+1<=count)
           &&(arr[moreBiggerIndex+1]>arr[moreBiggerIndex])
        )
        {
            moreBiggerIndex += 1; /* 更新到右孩子*/    
        }
        if(arr[ind]<arr[moreBiggerIndex])
        {
            _swap(&arr[ind],&arr[moreBiggerIndex]);
            ind = moreBiggerIndex;
        }
        else
        {
            break;
        }
    };
}


int search_ele(int num)
{
    int ret_val = 0;
    
    for(int i = 1; i <= count ; i++)
    {
        if(arr[i] == num)
        {
            ret_val = 1;
            break;
        }
    }    
    return ret_val ;
}

void insert_ele(int num)
{
    if(search_ele(num) == 1)
    {
        return;
    }
    else
    {
        arr[count+1] = num;
        count ++;
        shift_up(count);        
    }
}

int getMax(int* ret_val) 
{
    int item;
    if(count < 1)
    {
        return -1;
    }
    /* 获得根节点 */
    item = arr[1];
    _swap(&arr[1],&arr[count]); /*把最后一个和第一个进行交换*/
    count--;                    /* 进行计数调整*/
    shift_down(1);              /*把交换上来的数进行shift_down操作,以使堆继续满足大根堆的性质*/
    *ret_val = item;
    return 0;
}

int thirdMax(int* nums, int numsSize)
{
    int ret_val = 0;
    arr = (int*)malloc(sizeof(int)*(numsSize+1));
    if(arr == NULL)
    {
        return 0;
    }
    else
    {
        memset(arr,0,sizeof(int)*(numsSize+1));
    }
    
    for(int i = 0 ; i < numsSize ; i++)
    {
        insert_ele(nums[i]);
    }

    if (count < 3)
    {
        getMax(&ret_val);
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (getMax(&ret_val) == -1)
            {
                break;
            }
        }
    }
    free(arr);
    arr = NULL;
    count = 0;
    return ret_val;
}

int main()
{
    int a[4] ={ 2, 2, 3, 1 };
    int x = thirdMax(a, 4);
    printf(x);

    return 0;
}

/*
执行用时 : 148 ms, 在Third Maximum Number的C提交中击败了9.00% 的用户
内存消耗 : 7.6 MB, 在Third Maximum Number的C提交中击败了6.67% 的用户
*/