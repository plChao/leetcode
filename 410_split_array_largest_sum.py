# import math
# def divide_conqur(n, m):
#     if n == m:
#         return 1
#     if m == 1:
#         return 1
#     stepsum = 0
#     for i in range(1, n-m+1):
#         stepsum += divide_conqur(n-i, m-1)
#     return stepsum

# n = 10
# m = 5
# for n in range(10, 100, 10):
#     print('case', n)
#     print(divide_conqur(n, m))
#     print(math.comb(n-1, m-1))
