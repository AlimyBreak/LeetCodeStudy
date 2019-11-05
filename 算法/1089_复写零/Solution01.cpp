class Solution
{
    
    /*  [left,right] */
    private:
        void move(vector<int>& arr , int left,int right)
        {
            int i = 0;
            for(i=right; i > left ;i--)
            {
                arr[i] = arr[i-1];
            }
        }
    public:
        void duplicateZeros(vector<int>& arr)
        {
            int size = arr.size();
            for(int i = 0 ; i < size;)
            {
                if(arr[i] == 0)
                {
                    if(i+1 < size)
                    {
                        move(arr, i+1, size-1);
                        arr[i+1] = 0;
                    }
                    i += 2;
                }
                else
                {
                    i += 1;
                }
            }
            return ;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :76 ms, 在所有 cpp 提交中击败了25.08% 的用户
内存消耗 :9.2 MB, 在所有 cpp 提交中击败了100.00%的用户
*/