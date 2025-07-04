// ? Problem: Count Subarrays with At Most K Distinct Integers
// ?? Date: 4-July-2025
// ?? Approach: Sliding Window + Frequency Map
// ?? Idea: Use two pointers to form a window that keeps at most K distinct elements.
// ? When the number of unique elements exceeds K, shrink the window from the left.
// ?? Time Complexity: O(N), where N = length of the array
// ?? Space Complexity: O(K), for storing frequency of K elements
// ??? Tags: Arrays, Hashing, Sliding Window, Two Pointers
// ?? Companies: Asked in Amazon, Google, Facebook
// ?? Question Link: https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-elements/1

/*
You are given an array arr[] of positive integers and an integer k,
 find the number of subarrays in arr[] where the count of distinct integers is at most k.
 
 Examples:

Input: arr[] = [1, 2, 2, 3], k = 2
Output: 9
Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].

Input: arr[] = [1, 1, 1], k = 1
Output: 6
Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].

Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
Output: 24
Explanation: There are 24 subarrays with at most 2 distinct elements.
 
*/

//solution

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int, int> freq;

        for (r = 0; r < n; r++) {
            freq[arr[r]]++;

            while (freq.size() > k) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) {
                    freq.erase(arr[l]);
                }
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
    

};


//brute force 
    int countAtMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<int, int> freq;
        for (int j = i; j < n; j++) {
            freq[arr[j]]++;
            if (freq.size() <= k) {
                ans++;
            } else {
                break;
            }
        }
    }

    return ans;
}

