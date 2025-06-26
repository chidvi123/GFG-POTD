// ? Problem: Game With String
// ?? https://www.geeksforgeeks.org/problems/game-with-string/0
// ?? Date: 26-June-2025
// ?? Approach 1: Using heaps // TIME VOMPLEXITY O(26*26) // WORKS FINE FOR K IS LARGE 
// ?? Approach 2: NO HEAP JUST USING ARRAYS //TIME COMPLEXITY =O(26*K) // IF K IS LARGER IT MAY TAKE MORE TIME 
// ??? Tags: Heap, Greedy, Strings, Frequency
// ?? Companies: Amazon

//Approach 1
//using heaps // TIME VOMPLEXITY O(26*26)
//WORKS FINE FOR K IS LARGE 


//question :
/*
Given a string s consisting of lowercase alphabets and an integer k, 
your task is to find the minimum possible value of the string after 
removing exactly k characters.
The value of the string is defined as the sum of the squares
 of the frequencies of each distinct character present in the string.
 
 Examples :

Input: s = "abbccc", k = 2
Output: 6
Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or 
We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.

Input: s = "aaab", k = 2
Output: 2
Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
*/
class Solution {
  public:
  int minValue(string &s, int k) {
      
      int freq[26]={0};
      
     for(char ch : s)
     {
         freq[ch-'a']++;
     }
     
     priority_queue<int> pq;
     
     for(int i=0;i<26;i++)
     {
         if(freq[i]>0)
         {
             pq.push(freq[i]);
         }
     }
     
     while(k-- && !pq.empty())
     {
         int maxFreq=pq.top();
         pq.pop();
         maxFreq--;
         if(maxFreq>0)
         {
             pq.push(maxFreq);
         }
         
     }
     
     int result =0;
     while(!pq.empty())
     {
         int x=pq.top();
         pq.pop();
         result+=x*x;
     }
     return result;
      
      
  }
    
};



//Approach 2
//NO HEAP JUST USING ARRAYS //TIME COMPLEXITY =O(26*K)
// IS K IS LARGER IT MAY TAKE MORE TIME 

int minValue(string &s, int k) {
    int freq[26]={0};
    
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]-'a']++;
    }
    
    while(k>0)
    {
        int maxIndex=0;
        
        for(int i=1;i<26;i++)
        {
            if(freq[i]>freq[maxIndex])
            {
                maxIndex=i;           
            }
        }
        
        if(freq[maxIndex]>0)
        {
            freq[maxIndex]--;
        }
        
        k--;
    }
    
    int result=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]>0) result+=freq[i]*freq[i];
    }
    
    return result;
}
