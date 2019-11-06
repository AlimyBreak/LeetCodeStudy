class Solution
{
    bool check_point_valid(int R, int C,int x, int y)
    {
        return ( (x>=0) && (x<R) && (y>=0) && ( y < C) );
        
    }
    
    
    public:
        vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
        {
            vector<vector<int>> vvi_ret                             ;
            vector<int>         vi                                  ;
            int                 edge_distance[4]        =   {0,}    ;   // l_t_to_point,r_t_to_point,l_b_to_point,r_b_to_point
            int                 max_distance            =   0       ;
            int                 i                       =   0       ;
            int                 j                       =   0       ;
            int                 x                       =   0       ;
            int                 y                       =   0       ;
            
            /*计算最长距离*/
            edge_distance[0]    =   abs(0-r0)   +   abs(0-c0); 
            edge_distance[1]    =   abs(0-r0)   +   abs(C-1-c0);
            edge_distance[2]    =   abs(R-1-r0) +   abs(0-c0);
            edge_distance[3]    =   abs(R-1-r0) +   abs(C-1-c0);
            
            max_distance = edge_distance[0];
            for(i = 1;i < 4;i++)
            {
                if(max_distance < edge_distance[i])
                {
                    max_distance = edge_distance[i];
                }
            }
            
            
            /*按距离从小到大遍历(菱形)*/
            vi.push_back(r0);
            vi.push_back(c0);
            vvi_ret.push_back(vi);
            vi.clear();
            for(i=1;i<=max_distance;i++)
            {
                /*
                Left-->Bottom:(r0,c0-i) ---> (r0+i,c0),不到buttom点
                */
                for(j=0;j<i;j++)
                {
                    x = r0 + j;     //这里的x表示行下标 , y表示列下表
                    y = c0 - i + j;
                    if(check_point_valid(R,C,x,y))
                    {
                        vi.push_back(x);
                        vi.push_back(y);
                        vvi_ret.push_back(vi);
                        vi.clear();
                    }
                }
                
                /*
                Bottom-->Right:(r0+i,c0) --->(r0,c0+i),不到right点
                */
                for(j=0;j<i;j++)
                {
                    x = r0 + i - j;
                    y = c0 + j;
                    if(check_point_valid(R,C,x,y))
                    {
                        vi.push_back(x);
                        vi.push_back(y);
                        vvi_ret.push_back(vi);
                        vi.clear();
                    }
                }
                
                /*
                Right-->Top:(r0,c0+i) --->(r0-i,c0),不到top点
                */
                for(j=0;j<i;j++)
                {
                    x = r0 - j;
                    y = c0 + i - j ;
                    if(check_point_valid(R,C,x,y))
                    {
                        vi.push_back(x);
                        vi.push_back(y);
                        vvi_ret.push_back(vi);
                        vi.clear();
                    }
                }
                
                /*
                Top-->Left:(r0-i,c0) --->(r0,c0-i) ,不到top点
                */
                for(j=0;j<i;j++)
                {
                    x = r0 - i + j;
                    y = c0 - j ;
                    if(check_point_valid(R,C,x,y))
                    {
                        vi.push_back(x);
                        vi.push_back(y);
                        vvi_ret.push_back(vi);
                        vi.clear();
                    }
                } 
            }
            return vvi_ret;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :124 ms, 在所有 cpp 提交中击败了98.05% 的用户
内存消耗 :17.3 MB, 在所有 cpp 提交中击败了100.00%的用户
*/