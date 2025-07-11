// Idea: Use a set or trie to check whether all prefixes of each word exist in the list.
// Sort the words by length and lexicographically to prioritize longer and smaller-lex words.
// For each word, verify all its prefixes exist; update the answer if it satisfies the condition.
// Time Complexity: O(N * L^2), where N = number of words, L = max word length
// Space Complexity: O(N * L), for storing all words in a set or trie
// Tags: Strings, HashSet, Prefix Matching, Sorting
// Companies: Google, Microsoft, Amazon

/*
Given an array of strings words[]. Find the longest string in words[]
 such that every prefix of it is also present in the array words[]. 

Note: If multiple strings have the same maximum length, return the lexicographically smallest one.

Examples:

Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: pros
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array words[].
Input: words[] = ["ab", "a", "abc", "abd"]
Output: abc
Explanation: Both "abc" and "abd" has all the prefixes in words[]. Since, "abc" is lexicographically smaller than "abd", so the output is "abc".
*/


//solution

// code i tried failed 30 cases
class Solution {
  public:
    string longestString(vector<string> &words) {
        unordered_set<string> st(words.begin(), words.end());
        sort(words.begin(), words.end());  // ensures lexicographically smallest comes first

        string ans = "";
        for (string w : words) {
            bool allPrefix = true;
            for (int i = 1; i < w.length(); i++) {
                if (st.find(w.substr(0, i)) == st.end()) {
                    allPrefix = false;
                    break;
                }
            }
            if (allPrefix) {
                if (w.length() > ans.length()) ans = w;
            }
        }
        return ans;
    }
};



//chatgpt code

class Solution {
  struct TrieNode {
    bool isWord = false;
    unordered_map<char, TrieNode*> children;
  };

  void insert(TrieNode* root, const string &word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->children[c])
        node->children[c] = new TrieNode();
      node = node->children[c];
    }
    node->isWord = true;
  }

  void dfs(TrieNode* node, string &path, string &best) {
    if (!node->isWord && !path.empty()) return;

    if (path.length() > best.length() || 
        (path.length() == best.length() && path < best)) {
      best = path;
    }

    for (auto &p : node->children) {
      path.push_back(p.first);
      dfs(p.second, path, best);
      path.pop_back();
    }
  }

public:
  string longestString(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (string &word : words) insert(root, word);

    string path = "", best = "";
    dfs(root, path, best);
    return best;
  }
};

