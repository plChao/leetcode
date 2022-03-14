class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        ans = []
        for i in range(len(digits)-1, -1, -1):
            ans.append((digits[i] + carry) % 10)
            carry = (digits[i] + carry) // 10
        if carry == 0:
            ans.reverse()
            return ans
        else:
            ans.append(carry)
            ans.reverse()
            return ans