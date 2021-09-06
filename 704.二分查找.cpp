/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] < target)
            {
                left = middle + 1;
                continue;
            } else if (nums[middle] > target)
            {
                right = middle - 1;
                continue;
            }
            else
                return middle;
        }
        return -1;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> nums{-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(nums, target) << endl;
}
