import sys

class Solution:
    def decodeString(self, s: str) -> str:
        if '[' not in s:
            return s
        repeat_num = []
        left_quote_index = []
        num_index = -1
        ans = ''
        for i in range(len(s)):
            if num_index == -1 and s[i].isdigit():
                num_index = i
            elif s[i].isdigit():
                pass
            elif s[i] == '[':
                left_quote_index.append(i)
                repeat_num.append(int(s[num_index:i]))
                num_index = -1
            elif s[i] == ']' and len(left_quote_index) == 1:
                repeat_str = self.decodeString(s[left_quote_index[0] + 1: i])
                for i in range(repeat_num[0]):
                    ans += repeat_str
                left_quote_index.pop()
                repeat_num.pop()
            elif s[i] == ']':
                left_quote_index.pop()
                repeat_num.pop()
            elif len(left_quote_index) == 0:
                ans += s[i]
            # print(left_quote_index, repeat_num)
        return ans
    
ss = Solution()
print(ss.decodeString(sys.argv[1]))