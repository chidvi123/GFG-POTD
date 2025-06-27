// ?? Day 5 - GFG Daily Challenge  
// ?? Problem: Mobile Keypad Sequence Count  
// ?? Link: https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1  
// ?? Date: 27-June-2025  

// ? Approach: Dynamic Programming (Bottom-Up)  
// ?? Time Complexity: O(n * 10)  
// ?? Space Complexity: O(10)  
// ?? Idea: At each step, spread counts to valid neighbors (up, down, left, right, stay)  
// ?? Tags: DP, Strings, Combinatorics  
// ?? Asked In: Amazon, Google, Microsoft  



 There is a standard numeric keypad on a mobile phone.
 You can press the current button or any button that 
 is directly above, below, to the left, or to the right 
 of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. 
 However, diagonal movements and 
 pressing the bottom row corner buttons (* and #) are not allowed.


class Solution {
  public:
    int getCount(int n) {
        if (n == 1) return 10;

        // Define moves using 2D array
        int moves[10][5] = {
            {0, 8},           // 0
            {1, 2, 4},        // 1
            {2, 1, 3, 5},     // 2
            {3, 2, 6},        // 3
            {4, 1, 5, 7},     // 4
            {5, 2, 4, 6, 8},  // 5
            {6, 3, 5, 9},     // 6
            {7, 4, 8},        // 7
            {8, 5, 7, 9, 0},  // 8
            {9, 6, 8}         // 9
        };

        // Count how many moves each digit has
        int moveCount[10] = {2, 3, 4, 3, 4, 5, 4, 3, 5, 3};

        long long curr[10];
        for (int i = 0; i < 10; i++) curr[i] = 1;

        for (int step = 2; step <= n; step++) {
            long long next[10] = {0};

            for (int d = 0; d < 10; d++) {
                for (int i = 0; i < moveCount[d]; i++) {
                    int nextDigit = moves[d][i];
                    next[d] += curr[nextDigit];
                }
            }

            for (int i = 0; i < 10; i++) {
                curr[i] = next[i];
            }
        }

        long long total = 0;
        for (int i = 0; i < 10; i++) total += curr[i];

        return (int)total;
    }
};

