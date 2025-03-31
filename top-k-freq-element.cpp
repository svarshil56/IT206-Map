#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqmp;

        for (int num : nums)
        {
            freqmp[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto &pair : freqmp)
        {
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; i--)
        {
            for (int num : bucket[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> vec = {1, 1, 1, 2, 2, 3, 4, 4, 4};
    int k;
    cin >> k;

    vector<int> ans = sol.topKFrequent(vec, k);

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}