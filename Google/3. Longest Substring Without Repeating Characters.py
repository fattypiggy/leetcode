# link: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dict = {}
        max = 0
        left_boundary = 0
        for i in range(len(s)):
            if s[i] in dict and dict[s[i]] >= left_boundary: # and 后面的条件容易忽视
                left_boundary = dict[s[i]] + 1
            dict[s[i]] = i
            max = i+1 - left_boundary if i+1 - left_boundary > max else max
        return max

# test cases
test_cases = ["abba", "abcabcbb","", "bbbb", "pwwkew"]
test_answers = [2, 3, 0, 1, 3]
s = Solution()
for i in range(len(test_cases)):
    print(s.lengthOfLongestSubstring(test_cases[i]) == test_answers[i])