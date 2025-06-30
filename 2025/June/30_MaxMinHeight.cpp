// ? Problem: Maximize Minimum Height After K Increments
// ?? Date: 30-June-2025
// ?? Approach: Binary Search + Prefix Sum (Greedy Simulation)
// ?? Idea: Use binary search on the answer, simulate using range increment via difference array
// ?? Time Complexity: O(N * log(K)) where N = size of array
// ??? Tags: Binary Search, Greedy, Prefix Sum, Range Updates
// ?? Companies: Amazon, Google, Flipkart, Samsung
//link to the question:https://www.geeksforgeeks.org/problems/max-min-height--170647/1


/*
Given a garden with n flowers planted in a row, that is represented by an array arr[],
 where arr[i] denotes the height of the ith flower.You will water them for k days.
  In one day you can water w continuous flowers. Whenever you water a flower its height increases by 1 unit.
 You have to maximize the minimum height of all flowers after  k days of watering.
 
 Examples:

Input: arr[] = [2, 3, 4, 5, 1], k = 2, w = 2
Output: 2
Explanation: The minimum height after watering is 2.
Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]
Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]


Input: arr[] = [5, 8], k = 5, w = 1
Output: 9
Explanation: The minimum height after watering is 9.
Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]
Day 5: Water the second flower -> arr becomes [9, 9]
*/

//approach 1- binarysearch


class Solution {
public:
    bool canAchieveHeight(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> added(n + 1, 0);  // Difference array
        long long curr_add = 0;
        int used = 0;

        for (int i = 0; i < n; i++) {
            curr_add += added[i];
            int curr = arr[i] + curr_add;

            if (curr < target) {
                int delta = target - curr;
                used += delta;
                if (used > k) return false;

                curr_add += delta;
                if (i + w < n)
                    added[i + w] -= delta;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = arr[0], high = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < low) low = arr[i];
            if (arr[i] > high) high = arr[i];
        }

        high += k;
        int ans = low;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAchieveHeight(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};


//approach two
//brute force 

 int Mini(vector<int> arr, int n)
    {
        int temp = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < temp)
            {
                temp = arr[i];
            }
        }
        return temp;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();

        int i = 0;

        while (i++ < k)
        {
            int minNum = Mini(arr, n);
            int index = -1;

            for (int j = 0; j < n; j++)
            {
                if (arr[j] == minNum)
                {
                    if (j + w <= n)
                        index = j;
                    else if (j - w + 1 >= 0)
                        index = j - w + 1;
                    break;
                }
            }

            if (index != -1)
            {
                for (int j = index; j < index + w; j++)
                {
                    arr[j]++;
                }
            }
        }

        int ans = Mini(arr, n);
        return ans;
    }
    
    
