#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> index;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int secint = target - nums.at(i);
            if (map.find(secint) != map.end())
            {
                index.push_back(i);
                index.push_back(map.find(secint)->second);
                break;
            }
            else
            {
                map[nums.at(i)] = i;
            }
        }
        return index;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target;
    cin >> target;
    vector<int> ans = sol.twoSum(nums, target);
    for (auto i : ans)
    {
        cout << ans[i] << " ";
    }

    return 0;
}