// ? Problem: Next Greater Element in Circular Array
// ?? Date: 7-July-2025
// ?? Approach: Monotonic Stack with 2-pass simulation
// ?? Idea: Traverse twice to simulate circular behavior, use stack to track decreasing sequence
// ?? Time Complexity: O(N), since each element is pushed and popped at most once
// ?? Space Complexity: O(N), for stack and result array
// ??? Tags: Stack, Arrays, Circular Array, Monotonic Stack
// ?? Companies: Flipkart, Amazon, Microsoft


/*
Given a circular integer array arr[], the task is to determine
 the next greater element (NGE) for each element in the array.
The next greater element of an element arr[i] is the first element
that is greater than arr[i] when traversing circularly. If no such element exists,
 return -1 for that position.Circular Property: Since the array is circular, after reaching the last element,
  the search continues from the beginning until we have looked at all elements once.

Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
*/


class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % n]) st.pop();
            if (i < n && !st.empty()) res[i] = st.top();
            st.push(arr[i % n]);
        }
        return res;
    }
};

