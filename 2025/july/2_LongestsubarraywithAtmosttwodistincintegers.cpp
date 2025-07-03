// ? Problem: Longest Subarray with At Most Two Distinct Integers
// ?? Date: 2-July-2025
// ?? Approach: Sliding Window + Hash Map (or Frequency Map)
// ?? Idea: Expand right, and when distinct elements > 2, shrink from left
// ?? Time Complexity: O(N), where N is the length of the array
// ?? Space Complexity: O(K), where K is the number of distinct elements (max 2)
// ?? Tags: Sliding Window, Hashing, Two Pointers, Arrays
// ?? Companies: Asked in interviews by Amazon, Flipkart, Paytm, and Ola
// ?? Question Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-atmost-two-distinct-elements/1

/*
Given an array arr[] consisting of positive integers,
 your task is to find the length of the longest subarray
  that contains at most two distinct integers.

Examples:

Input: arr[] = [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most 
two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.


Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.
*/

//solution

class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;

        while (j < n) {
            mp[arr[j]]++;

            while (mp.size() > 2) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }

            int len = j - i + 1;
            if (len > maxLen) {
                maxLen = len;
            }

            j++;
        }

        return maxLen;
    }
};

