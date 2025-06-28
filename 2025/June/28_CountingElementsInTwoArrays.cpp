// ? Day 6 - GFG Daily Challenge  
// ?? Problem: Counting elements in two arrays (A[i] = B[j])  
// ?? Link: https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1  
// ?? Date: 27-June-2025  

/*You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements.
 For each element in a[], your task is to count how many elements in b[] are less than or 
 equal to that element.*/

// ??? Tags: Binary Search, Arrays, Sorting  
// ?? Asked In: Amazon,





//APPROACH 1
//using brute force
/* 
passes 1010/1111 testcases passed...

vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n1=a.size();
        int n2=b.size();
        vector<int> op(n1,0);
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(a[i]>=b[j])
                {    
                    op[i]++;
                }
            }
        }
        
        return op;
    }*/
    
    
/*
same 1010/1111 test cases 
vector<int> countLessEq(vector<int>& a, vector<int>& b) {
       int n1=a.size();
        int n2=b.size();
        vector<int> op;
        for(int i=0;i<n1;i++)
        {
            int count=0;
            for(int j=0;j<n2;j++)
            {
                if(a[i]>=b[j])
                {    
                    count++;
                }
            }
            op.push_back(count);
        }
      return op;
  }
   */
   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
   
   //APPROACH - 2 
  
  1110/1111 test cases passed....
  vector<int> countLessEq(vector<int>& a, vector<int>& b) {
    int n1=a.size();
    int n2=b.size();
    vector<int> op(n1,0);
    sort(b.begin(),b.end());
    for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(a[i]>=b[j])
                {    
                    op[i]++;
                }
            }
        }
        
        return op;
  }
  
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  //APPROACH-3
  
// ?? Approach: Binary Search on Sorted Array  
// ?? Time Complexity: O(N log M)  
// ?? Space Complexity: O(1)  
// ?? Idea: For each a[i], count how many elements in b[] are = a[i]  
// ?? Step 1: Sort b[]  
// ?? Step 2: Use binary search to find last index where b[j] = a[i]  
// ? Count = index + 1  

//1111/1111 test cases passed....

class Solution {
  public:
   vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();
        vector<int> op(n1,0);
        sort(b.begin(),b.end());
        for(int i=0;i<n1;i++)
        {
            int num = a[i];
            int start=0;
            int end=n2-1;
            int ans=-1;
            
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(b[mid]<=num)
                {
                    ans=mid;
                    start=mid+1; 
                }
                else{
                    end=mid-1;
                }
                
            }
            op[i]=ans+1;
        }
        return op;
       
       
   }
   
  
};


