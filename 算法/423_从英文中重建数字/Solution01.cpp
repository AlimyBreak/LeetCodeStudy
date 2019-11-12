class Solution
{
    public:
        string originalDigits(string s)
        {
            
            " f v i e f u r o "
            
            /*
            a b c d  [e] [f] [g] [h] [i] j k l m [n] [o] p q [r] [s] [t] [u] [v] [w] [x] y [z]
            
            */
            /*
            zero        e:1                        o:1  r:1                                    z:1  
            one         e:1                   n:1  o:1                
            two                                    o:1             t:1              w:1
            three       e:2         h:1                 r:1        t:1           
            four             f:1                   o:1                  u:1         
            five        e:1  f:1          i:1                                v:1 
            six                           i:1                 s:1                         x:1
            seven       e:2                    n:1            s:1            v:1 
            eight       e:1     g:1 h:1   i:1                      t:1
            nine        e:1               i:1  n:2 
            */

            string          charBuf("efghinorstuvwxz")  ;
            int             numCount[10]    =   {0,}    ;
            int             i               =   0       ;
            int             temp            =   0       ;
            map<char,int>   mci                         ;
            string          ret_val                     ;

            
            for(i = 0 ; i < charBuf.size() ; i++)
            {
                mci[charBuf[i]]=0;
            }
            
            /*统计资源数量*/
            for(i = 0;i < s.size();i++)
            {
                mci[s[i]]++;
            }
            
            // 1.根据'z'的数量算zero的数量,e:1 o:1  r:1
            temp        =   mci['z']    ;
            numCount[0] =   temp        ;
            mci['z']    =   0           ;
            mci['e']   -=   temp        ;
            mci['o']   -=   temp        ;
            mci['r']   -=   temp        ;
            
            // 2.根据'w'的数量算two的数量, o:1 t:1 
            temp        =   mci['w']    ;
            numCount[2] =   temp        ;
            mci['w']    =   0           ;
            mci['o']   -=   temp        ;
            mci['t']   -=   temp        ;

            // 3.根据'u'的数量算four的数量, f:1 o:1
            temp        =   mci['u']    ;
            numCount[4] =   temp        ;
            mci['u']    =   0           ;
            mci['f']   -=   temp        ;
            mci['o']   -=   temp        ;            
            
            // 4.根据'x'的数量算six的数量,i:1 s:1
            temp        =   mci['x']    ;
            numCount[6] =   temp        ;
            mci['x']    =   0           ;
            mci['i']   -=   temp        ;
            mci['s']   -=   temp        ;             
        
            // 5.根据'r'的数量算three的数量,e:2 h:1 t:1  
            temp        =   mci['r']    ;
            numCount[3] =   temp        ;
            mci['r']    =   0           ;
            mci['e']   -=   2*temp      ;
            mci['h']   -=   temp        ;  
            mci['t']   -=   temp        ;     
            
            // 6.根据'o'的数量算one的数量,e:1 n:1
            temp        =   mci['o']    ;
            numCount[1] =   temp        ;
            mci['o']    =   0           ;
            mci['e']   -=   temp        ;  
            mci['n']   -=   temp        ;                 
  
            // 7.根据's'的数量算seven的数量, e:2 n:1 v:1
            temp        =   mci['s']    ;
            numCount[7] =   temp        ;
            mci['s']    =   0           ;
            mci['e']   -=   2*temp      ;  
            mci['n']   -=   temp        ; 
            mci['v']   -=   temp        ;             
            
                           
            // 8.根据'v'的数量算five的数量,e:1 f:1 i:1  
            temp        =   mci['v']    ;
            numCount[5] =   temp        ;
            mci['v']    =   0           ;
            mci['e']   -=   temp        ;  
            mci['f']   -=   temp        ; 
            mci['i']   -=   temp        ;  
                        
            // 9.根据't'的数量算eight的数量, e:1 g:1 h:1 i:1    
            temp        =   mci['t']    ;
            numCount[8] =   temp        ;
            mci['t']    =   0           ;
            mci['e']   -=   temp        ;  
            mci['g']   -=   temp        ; 
            mci['h']   -=   temp        ;  
            mci['i']   -=   temp        ;              
            
                        
            // 10.根据'e'的数量算nine的数量, i:1  n:2   
            numCount[9] = mci['e']      ;
            
            for(i = 0 ; i < 10; i++)
            {
                // s(num,c)
                if(numCount[i])
                {
                    ret_val += string(numCount[i],to_string(i));
                }
            }
            
            return ret_val;
        
        }
};


/*
提交报错,原因不明.
执行出错信息： terminate called after throwing an instance of 'std::length_error'
最后执行的输入： "fviefuro"
*/





