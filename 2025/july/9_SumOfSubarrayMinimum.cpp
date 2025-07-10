// ? Problem: Sum of Subarray Minimums
// ?? Date: 9-July-2025
// ?? Approach: Monotonic Stack + Contribution Count
// ?? Idea: For each element, find how many subarrays it is the minimum of using NSL and NSR
// ?? Time Complexity: O(N), where N is the size of the array
// ?? Space Complexity: O(N), for stacks and auxiliary arrays
// ??? Tags: Stack, Arrays, Monotonic Stack, Prefix Contribution
// ?? Companies: Amazon, Google, Microsoft


/*Given an array arr[] of positive integers, find the 
total sum of the minimum elements of every possible subarrays.

Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

Examples:

Input: arr[] = [3, 1, 2, 4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
Input: arr[] = [71, 55, 82, 55]
Output: 593
Explanation: The sum of the minimum of all the subarrays is 593.
Constraints:
1 = arr.size() = 3*104
1 = arr[i] = 103
*/

//solution

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        long long res = 0;
        int mod = 1e9 + 7;

        stack<int> st;
        vector<int> prev(n), next(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res = (res + arr[i] * left % mod * right % mod) % mod;
        }

        return res;
    }
};


