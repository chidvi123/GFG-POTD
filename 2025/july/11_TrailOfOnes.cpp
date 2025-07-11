// Question: Trails of 1
//
// Idea: Total binary strings of length n = 2^n.
// Subtract the number of strings with no consecutive 1's (use Fibonacci relation).
// Let valid(n) = count of binary strings of length n with no consecutive 1's.
// valid(n) = valid(n - 1) + valid(n - 2), with valid(1) = 2, valid(2) = 3.
// Answer = total - valid(n)
// Time Complexity: O(n)
// Space Complexity: O(n)
// Tags: DP, Fibonacci, Binary Strings, Bit Manipulation
// Companies: Amazon, Google, Microsoft


/*
Given an integer n, the task is to count the number of binary strings of length n that contains at least one pair of consecutive 1's.
Note: A binary string is a sequence made up of only 0's and 1's.

Examples:

Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111. The strings with consecutive 1's are 011, 110 and 111.
Input: n = 5
Output: 19
Explanation: There are 19 strings having at least one pair of consecutive 1's.
*/


//solution

class Solution {
  public:
    int countConsec(int n) {
        if (n == 1) return 0;

        int fib[n + 2];
        fib[1] = 2;
        fib[2] = 3;

        for (int i = 3; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        int total = 1 << n;
        int valid = fib[n];
        return total - valid;
    }
};

