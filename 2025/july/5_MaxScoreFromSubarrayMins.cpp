// ? Problem: Max Score from Subarray Mins
// ?? Date: 4-July-2025
// ?? Approach: Monotonic Stack
// ?? Idea: For every element, try to find previous and next smaller elements
// ? In each valid subarray, the smallest and second smallest will be adjacent in sorted subarray
// ?? Time Complexity: O(N log N), for sorting pairs or iterating windows
// ?? Space Complexity: O(N), for storing stacks and indexes
// ??? Tags: Arrays, Stack, Subarrays, Combinations
// ?? Companies: Amazon, Google

/*
You are given an array arr[] of integers. Your task is to find the maximum sum of the smallest
 and second smallest elements across all subarrays (of size >= 2)of the given array.
 
 
 Examples :

Input: arr[] = [4, 3, 5, 1]
Output: 8
Explanation: All subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] ? 3 + 4 = 7
[4, 3, 5] ? 3 + 4 = 7
[4, 3, 5, 1] ? 1 + 3 = 4
[3, 5] ? 3 + 5 = 8
[3, 5, 1] ? 1 + 3 = 4
[5, 1] ? 1 + 5 = 6
Maximum Score is 8.
Input: arr[] = [1, 2, 3]
Output: 5
Explanation: All subarray with at least 2 elements and find the two smallest numbers in each:
[1, 2] ? 1 + 2 = 3
[1, 2, 3] ? 1 + 2 = 3
[2, 3] ? 2 + 3 = 5
Maximum Score is 5
*/


//solution

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxScore = 0;

        for (int i = 0; i < n - 1; ++i) {
            int a = arr[i];
            int b = arr[i + 1];
            int sum = a + b;
            if (sum > maxScore) {
                maxScore = sum;
            }
        }

        return maxScore;
    }
};

