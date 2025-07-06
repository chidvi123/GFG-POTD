// ? Problem: Top K Sum Combinations from Two Arrays
// ?? Date: 6-July-2025
// ?? Approach: Max Heap + Set for Index Tracking
// ?? Idea: Use max heap to always pick the next largest sum, starting from a[0]+b[0]
// ? From every (i, j), push next two: (i+1, j) and (i, j+1) if not visited
// ?? Time Complexity: O(K log K), where K is the number of combinations needed
// ?? Space Complexity: O(K), for heap and set of visited index pairs
// ??? Tags: Heap, Greedy, Arrays, Priority Queue, Combinations
// ?? Companies: Amazon, Google, Microsoft


/*
You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by
 adding one element from a[] and one from b[], using each index pair (i, j) at most once.
 Return the top k maximum sum combinations, sorted in non-increasing order.
 
 Examples:

Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
Constraints:
1 = a.size() = b.size() = 105
1 = k = a.size()
1 = a[i], b[i] = 104


*/


//solution   1100/1100 

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        vector<int> result;

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> visited;

        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !pq.empty()) {
            auto top = pq.top(); pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            result.push_back(sum);

            if (i + 1 < n1 && !visited.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n2 && !visited.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};


// 1010/1100 testcases 

vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n1=a.size();
        int n2=b.size();
        vector<int> solarray;
        
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        
        priority_queue<int> pq;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
              pq.push(a[i]+b[j]);  
            }
        }
        
        for(int z=0;z<k;z++)
        {
            solarray.push_back(pq.top());
            pq.pop();
        }
        return solarray;



