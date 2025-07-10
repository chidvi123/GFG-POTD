// ? Problem: Next Element with Greater Frequency
// ?? Date: 8-July-2025
// ?? Approach: Stack + Frequency Map
// ?? Idea: Traverse from right, use stack to track candidates with higher frequency
// ?? Time Complexity: O(N), each element is pushed and popped once
// ?? Space Complexity: O(N), for stack and frequency map
// ??? Tags: Stack, Frequency, Arrays, Monotonic Stack
// ?? Companies: Amazon, Flipkart


/*Given an array arr[] of integers, for each element, find the closest (distance wise)
 to its right that has a higher frequency than the current element.
If no such element exists, return -1 for that position.

Examples:

Input: arr[] = [2, 1, 1, 3, 2, 1]
Output: [1, -1, -1, 2, 1, -1]
Explanation: Frequencies: 1 ? 3 times, 2 ? 2 times, 3 ? 1 time.
For arr[0] = 2, the next element 1 has a higher frequency ? 1.
For arr[1] and arr[2], no element to the right has a higher frequency ? -1.
For arr[3] = 3, the next element 2 has a higher frequency ? 2.
For arr[4] = 2, the next element 1 has a higher frequency ? 1.
For arr[5] = 1, no elements to the right ? -1.
Input: arr[] = [5, 1, 5, 6, 6]
Output: [-1, 5, -1, -1, -1]
Explanation: Frequencies: 1 ? 1 time, 5 ? 2 times, 6 ? 2 times.
For arr[0] and arr[2], no element to the right has a higher frequency ? -1.
For arr[1] = 1, the next element 5 has a higher frequency ? 5.
For arr[3] and arr[4], no element to the right has a higher frequency ? -1
*/


//perfect solution

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        stack<int> sp;
        vector<int> sol(n, -1);

        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        sp.push(0);
        for(int i = 1; i < n; i++) {
            while(!sp.empty() && freq[arr[i]] > freq[arr[sp.top()]]) {
                sol[sp.top()] = arr[i];
                sp.pop();
            }
            sp.push(i);
        }

        return sol;
    }
};



//10 cases failed 
//solution
/*class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> sol(n, -1);  // initialize result with -1

        // Count frequencies
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (freq[arr[j]] > freq[arr[i]]) {
                    sol[i] = arr[j];
                    break;
                }
            }
        }

        return sol;
    }
};*/




