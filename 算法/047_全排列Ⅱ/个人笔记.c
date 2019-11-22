/*

假设用例排序后:1  1  2 

第一层递归:
    i = 0
        visited[0] == 0;
        cur = [ 1 ];
        visited[0] = 1;
        第二层递归:
            cur = [ 1 ];
            visited = [ 1 , 0 , 0 ]
            
            i = 0
                visited[0] == 1,coutinue 了
                
            i = 1
            
                visited[1] == 0
                i > 0 满足
                num[1] == nums[0] 满足
                !visited[0] 不满足,进入第三层递归
                
                cur = [ 1,1]
                visited = [1,1,0]
                第三层递归:
                    
                    i = 0
                        continue
                    i = 1
                        continue
                    i = 2
                        cur = [1 1 2 ]
                        visited = [1,1,1]
                        进入第四层递归
                        把cur 压入结果.[1 1 2 ]
                        退出第四层递归
                        visited = [1,1,0];
                        cur = [1,1]
                循环结束,退出第三重循环
                
            i==1的Helper执行完毕,visited[1]=0
            -->
            visited = [1,0,0]
            cur = [ 1 ];
            
            i = 2
                
                visited[2] == 0;
                
                visited = [1,0,1];
                cur = [1,2];
                进入第三层递归:
                    
                    i = 0
                        continue
                        
                    i = 1
                        
                        cur = [1,2,1]
                        visited = [ 1 ,1,1]
                        进入第四层递归
                        把cur 压入结果.[1 2 1 ]
                        退出第四层递归
                        cur = [1,2]
                        visited = [1,0,1]
                    
                    i = 2
                        continue
                        
                
                
                cur = [1];
                visited = [1,0,0]

    cur = []
    visited = [0,0,0]
    
第一层递归:
    i = 1
        
        cur = [1];
        visited = [0,1,0]
        
        i = 0
            
            cur = [1,1];
            visited = [1,1,0]
            进入第三重循环
                i = 0
                    continue
                i = 1
                    continue
                
                i = 2
                    cur = [1,1,2]
                    visited = [1,1,1]
                    进入第四层递归
                    压入 cur = [1,1,2] 但是这个已经在本文档的第36行压入了...没去重啊
                    ...
                    
   

        
        i = 1
        
        i = 2
        
    
    
第一层递归:  
    i = 2
    
    
解答:第一层递归: i == 1时,直接由于第二个条件就不会choose.
    
*/