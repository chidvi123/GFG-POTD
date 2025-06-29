// ? Problem: Split Array Largest Sum
// ?? Date: 29-June-2025
// ?? Approach 1: Binary Search on Answer + Greedy Partitioning
// ?? Time Complexity: O(N * log(Sum)) where Sum is total sum of array
// ?? Approach 2: Brute-force Partitioning (not feasible for large N)
// ?? Insight: Use binary search to find the smallest "maximum subarray sum" possible for k subarrays
// ??? Tags: Binary Search, Greedy, Partition DP, Arrays
// ?? Companies: Google, Facebook, Amazon



/* 
Given an array arr[] and an integer k, divide the array 
into k contiguous subarrays such that the maximum sum 
among these subarrays is minimized. Find this minimum 
possible maximum sum.
*/


//binary search approach

class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int maxSum) {
        int count = 1, sum = 0;
        for (int num : arr) {
            if (num > maxSum) return false;
            if (sum + num > maxSum) {
                count++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int low = 0, high = 0;
        for (int num : arr) {
            low = max(low, num);  
            high += num;          
        }

        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

