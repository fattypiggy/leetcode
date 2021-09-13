/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (auto &p: points) {
            unordered_map<int, int> cnt;
            for (auto &q: points) {
                int distance = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                ++cnt[distance];
            }
            // c++17结构化绑定
            for (auto &[k, v]: cnt)
            {
                res += v * (v-1);
            }
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<vector<int>> points{{0,0},{1,0},{2,0}};
    cout << s.numberOfBoomerangs(points) << endl;
    return 0;
}
