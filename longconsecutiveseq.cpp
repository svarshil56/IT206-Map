#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxCount = 0;

        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int currentNum = num;
                int count = 1;

                while (numSet.find(currentNum + 1) != numSet.end())
                {
                    currentNum++;
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = sol.longestConsecutive(nums);
    cout << ans;
    return 0;
}

// int longseq(vector<int> &nums)
// {
//     map<int, int> seq;
//     for (int i : nums)
//     {
//         seq[i] = true;
//     }
//     int maxCount = 0;
//     for (auto it = seq.begin(); it != seq.end(); it++)
//     {
//         int num = it->first;

//         if (seq.find(num - 1) == seq.end())
//         {
//             int currentNum = num;
//             int count = 1;

//             while (seq.find(currentNum + 1) != seq.end())
//             {
//                 currentNum++;
//                 count++;
//             }

//             // Update maxCount
//             maxCount = max(maxCount, count);
//         }
//     }
//     return maxCount;
// }