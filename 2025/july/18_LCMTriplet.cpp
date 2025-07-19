Given a number n, find the maximum possible LCM that can
 be obtained by selecting three numbers less than or equal to n.
Note : LCM stands for Lowest Common Multiple.


Input: n = 9
Output: 504
Explanation: 504 is the maximum LCM that can be attained by any triplet of numbers less 
than or equal 9. The triplet which has this LCM is {7, 8, 9}.
Input: n = 7
Output: 210
Explanation: 210 is the maximum LCM that can be attained by any triplet of numbers less 
than or equal 7. The triplet which has this LCM is {5, 6, 7}.

//code


class Solution {
  public:
    int factorise(int y)
    {
        bool run=true;
    while(run)
    {
       if(y%2==0)
        {
            y/=2;
        }
        else{
            run=false;
        }
    }
    return y;
        
    }
    int lcmTriplets(int n) {
        
        if(n<=2) return n;
        int x=n;
        int n1,n2,n3=0;
        n1=n;
        n2=n-1;
        
        if(n%2==1)
        {
            n3=n-2;
        }
        else
        {
            if(n%3!=0)
            {
                n3=n-3;
            }
            else
            {
                n1=n-1;
                n2=n-2;
                n3=n-3;
            }
        }
        
       
        return n1*n2*n3;
    }
};
