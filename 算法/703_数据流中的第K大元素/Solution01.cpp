
class KthLargest
{
    private:
        int*    arr         ;  /*存储k个值的空间*/
        int     capacity    ;  /*k最小堆容量*/
        int     count       ;  /*记录目前小顶堆中数据的个数*/
        
    void shift_up(int ind)
    {
        while(  (arr[ind/2] > arr[ind])   
              &&(ind > 1)
        )
        {
            swap(arr[ind/2],arr[ind]);      /* 交换 */
            ind /= 2;                       /* 待比较对象迁移到父节点*/
        };
    }
    
    void shift_down( int ind )
    {
        int moreSmallerIndex = 0;
        while(2*ind <=count) /* 有左孩子就是有孩子*/
        {
            moreSmallerIndex = 2*ind;
            if(  (moreSmallerIndex+1<=count)
            &&(arr[moreSmallerIndex+1]<arr[moreSmallerIndex])
            )
            {
                moreSmallerIndex += 1; /* 更新到右孩子*/    
            }
            if(arr[ind]>arr[moreSmallerIndex])
            {
                swap(arr[ind],arr[moreSmallerIndex]);
                ind = moreSmallerIndex;
            }
            else
            {
                break;
            }
        };
     }
    
    
public:
    KthLargest(int k, vector<int>& nums)
    {
        capacity    = k+1;
        count       = 0;
        arr         = new int[k+1+1];
        for(int i = 0; i < nums.size();i++)
        {
            insert(nums[i]);
        }
    }
    
    int add(int val)
    {
        insert(val);
        if(count+1==capacity)
        {
            return arr[1];
        }
        else
        {
            return -1;
        }
    }
    
    void insert(int val)
    {
        arr[count+1] = val;
        count++;
        shift_up(count);
        /*保证插入之后的堆顶是k个元素中最小的,所以在流中必然是第k大,因为排名靠后的都会被移除该小顶堆*/
        if(count>=capacity)
        {
            RemoveMin();   
        }
    }
    
    void RemoveMin()
    {

        if(count <1)
        {
            return ;
        }
        else
        {
            swap(arr[1],arr[count]);
            count--;
            shift_down(1);
            return;
        }
    }
    
    ~KthLargest()
    {
        delete[] arr;
    }
    
};


/*
执行结果：通过
显示详情
执行用时 :60 ms, 在所有 C++ 提交中击败了96.76%的用户
内存消耗 :19.1 MB, 在所有 C++ 提交中击败了100.00%的用户
*/