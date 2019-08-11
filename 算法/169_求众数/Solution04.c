void swap(int*a , int* b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void __quicksort3(int* arr,int l,int r)
{
    
	int v   =   arr[l]  ;
	int lt  =   l       ;
	int gt  =   r+1     ;
	int i   =   l+1     ;
    
	if(l>=r)
    {
        return ;
	}

	while(i<gt)
	{
		if(arr[i]<v)
		{
            swap(&arr[i],&arr[lt+1]);
            lt++;
            i++;
        }
		else if(arr[i]>v)
		{
            swap(&arr[i],&arr[gt-1]);
            gt--;
		}
		else
		{
            i++;
        }
    }
    
	swap(&arr[l],&arr[lt]);
	 __quicksort3(arr,l,lt-1);
	 __quicksort3(arr,gt,r);
	
	
}
 
 

int majorityElement(int* nums, int numsSize)
{
    

    int ret_val = 0;

    __quicksort3(nums,0,numsSize-1);
    
    ret_val = nums[numsSize/2];
    
    return ret_val;
}


/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 C 提交中击败了85.92% 的用户
内存消耗 :9 MB, 在所有 C 提交中击败了26.37%的用户
*/