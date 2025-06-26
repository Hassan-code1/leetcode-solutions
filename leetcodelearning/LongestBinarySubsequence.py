class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        counter = 0
        longestString = ""
        currentNum = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '0':
                longestString = longestString + s[i]
            else:
                if counter < 32 and currentNum + ( 1 << counter) <= k:
                    currentNum += (1 << counter) 
                    longestString = longestString + s[i]
            counter += 1
        return len(longestString)