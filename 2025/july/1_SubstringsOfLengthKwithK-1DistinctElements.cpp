// ? Problem: Count Substrings of Length K with K-1 Distinct Characters
// ?? Date: 1-July-2025
// ?? Approach: Brute Force + Frequency Array
// ?? Idea: Slide over all substrings of length K, count distinct characters using fixed-size array
// ?? Time Complexity: O(N * K) where N = length of string, K = substring length
// ??? Tags: Strings, Frequency Count, Sliding Window (can optimize)
// ?? Companies: Asked in string-based coding rounds (Amazon, Infosys, TCS, Wipro)
// question link:https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1


/// i didnt use sliding window approach  as mentioned in question 
//because i didnt knew it ,but 1120 test cases passed with my own 
// brute force approach 

/*Given a string s consisting only lowercase alphabets and an integer k.
 Find the count of all substrings of length k which have exactly k-1 
 distinct characters.
 
 Examples:

Input: s = "abcc", k = 2
Output: 1
Explaination: Possible substring of length k = 2 are,
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct characters
Only one valid substring so, count is equal to 1.


Input: "aabab", k = 3
Output: 3
Explaination: Possible substring of length k = 3 are, 
aab : 2 distinct charcters
aba : 2 distinct characters
bab : 2 distinct characters
All these substring are valid so, the total count is equal to 3.
 
 */
 
 class Solution {
  public:
    int substrCount(string &s, int k) {
        int n=s.length();
        int finalcount=0;
        for(int i=0;i<=n-k;i++)
        {
            int count=0;
            string s1=s.substr(i,k);
            int freq[26]={0};
            for(int i=0;i<s1.length();i++)
            {
               freq[s1[i]-'a']++;
            }
            for(int j=0;j<26;j++)
            {
                if(freq[j]>0)
                {
                    count++;
                }
            }
            if(count==k-1)
            {
                finalcount++;
            }
        }
        return finalcount;
    }
};
