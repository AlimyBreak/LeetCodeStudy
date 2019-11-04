class Solution
{
    public:
        int findDuplicate(vector<int>& nums)
        {
            int temp1   = 0x00          ;
            int temp2   = 0x00          ;
            int temp3   = 0x00          ;

            int i       = 0             ;
            int n       = nums.size()   ;
            
            for(i = 1; i <= n ; i ++)
            {
                temp1 ^= i;
            }
            
            for(i = 0; i < n ; i++)
            {
                temp2 ^= nums[i];
                temp3  = temp3 + nums[i] -(i + 1); 
            }
            
            /*
            X 是多的
            Y 是少的
            temp1 = X^Y;
            temp3 = X-Y;
            
            可惜异或并不满足分配率,无法继续进行下去
            若temp3 > 0:
                X = Y+temp3
                temp1 = Y^(Y+temp3);
                temp1 = Y^temp3
                Y = temp1^temp3
            
            
            */
        }
};