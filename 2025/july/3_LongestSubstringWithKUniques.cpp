// ? Problem: Longest Substring with Exactly K Distinct Characters
// ?? Date: 3-July-2025
// ?? Approach: Sliding Window + Hash Map
// ?? Idea: Use two pointers to maintain a window with exactly k unique characters
// ?? Time Complexity: O(N), where N = length of string
// ?? Space Complexity: O(K), for storing frequency of at most K characters
// ?? Tags: Strings, Sliding Window, Hashing, Two Pointers
// ?? Companies: Asked in Amazon, Microsoft, Adobe, Flipkart
// ?? Question Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


/*
You are given a string s consisting only lowercase alphabets and an integer k.
 Your task is to find the length of the longest substring that contains exactly
 \ k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters
 is "cbebebe", which includes 'c', 'b', and 'e'.

Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.

Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b',
 making it the longest valid substring.
*/

//solution

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        if (n == 0 || k == 0) return -1;

        unordered_map<char, int> freq;
        int maxLen = -1;
        int left = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            if (freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};

