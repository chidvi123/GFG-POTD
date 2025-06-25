// ? Problem: Check if Frequencies Can Be Equal
// ?? https://www.geeksforgeeks.org/problems/check-if-frequencies-can-be-equal/1
// ?? Date: 25-June-2025
// ?? Approach: Use two maps — one for character frequency, another for frequency count;
//              check if either one frequency occurs once and is 1 or one can be reduced to match the other
// ?? Tags: Hashing, Frequency Count, Map, Strings
// ?? Companies: Amazon, Microsoft, D-E-Shaw

//question:
/*Given a string s consisting only lowercase alphabetic characters, 
  check whether it is possible to remove at most one character such that
  the  frequency of each distinct character in the string becomes same.
  Return true if it is possible; otherwise, return false.*/
  
  
class Solution {
  public:
    bool sameFreq(string& s) {
        int freq[26] = {0};

        for (char ch : s)
            freq[ch - 'a']++;

        unordered_map<int, int> countFreq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                countFreq[freq[i]]++;
            }
        }

        int f1 = 0, c1 = 0, f2 = 0, c2 = 0;

        for (auto it : countFreq) {
            int f = it.first, c = it.second;

            if (f1 == 0) {
                f1 = f;
                c1 = c;
            } else if (f2 == 0) {
                f2 = f;
                c2 = c;
            } else {
                return false; // More than 2 freqs
            }
        }

        if (countFreq.size() == 1) return true;
        if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return true;
        if (abs(f1 - f2) == 1) {
            if ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)) return true;
        }

        return false;
    }
};

