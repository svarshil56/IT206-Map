#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> ump;
        for (int i = 0; i < s.size(); i++)
        {
            ump[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (ump[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<int> freq(26, 0);
//         for (char c : s) {
//             freq[c - 'a']++;
//         }

//         for (int i = 0; i < s.size(); i++) {
//             if (freq[s[i] - 'a'] == 1) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

int main()
{
    Solution sol;
    string str = "leetcode";
    int ans = sol.firstUniqChar(str);
    cout << ans;
    return 0;
}