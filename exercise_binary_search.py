from multiprocessing.spawn import _main
from tkinter.tix import MAIN
from pip import main


def upper_bound_asc(nums, target):
    # return the lowerest index that nums[index] > target
    l = 0
    r = len(nums) - 1
    # target will in [nums[l], nums[r]] 
    # it means nums[l] <= target <= nums[r]
    while l <= r:
        mid = (l+r) // 2
        if nums[mid] > target:
            r = mid - 1
        else:
            l = mid + 1
    return l

def lower_bound_asc(nums, target):
    # return the lowerest index that nums[index] >= target
    l = 0
    r = len(nums) - 1
    # target will in [nums[l], nums[r]] 
    # it means nums[l] <= target <= nums[r]
    while l <= r:
        mid = (l+r) // 2
        if nums[mid] >= target:
            r = mid - 1
        else:
            l = mid + 1
    return l

def upper_bound_dsc(nums, target):
    # return the highest index that nums[index] > target
    # I think is lower bound asc change
    # find the lowest index that nums[index] >= target and return index - 1
    l = 0
    r = len(nums) - 1
    # target will in [nums[l], nums[r]] 
    # it means nums[l] >= target >= nums[r]
    while l <= r:
        mid = (l+r) // 2
        if nums[mid] <= target:
            r = mid - 1
        else:
            l = mid + 1
    return l - 1

def lower_bound_dsc(nums, target):
    # return the highest index that nums[index] >= target
    # I think is upper bound asc change
    # find the lowest index that nums[index] > target and return index - 1
    l = 0
    r = len(nums) - 1
    # target will in [nums[l], nums[r]] 
    # it means nums[l] >= target >= nums[r]
    while l <= r:
        mid = (l+r) // 2
        if nums[mid] < target:
            r = mid - 1
        else:
            l = mid + 1
    return l - 1

if __name__ == '__main__':
    testa = [10, 10, 20, 20, 30, 30]
    assert upper_bound_asc(testa, 20) == 4, 'asc test a'
    assert lower_bound_asc(testa, 20) == 2, 'asc test a'
    testb = [10, 15, 30, 40]
    assert upper_bound_asc(testb, 20) == 2, 'asc test b'
    assert lower_bound_asc(testb, 20) == 2, 'asc test b'
    testc = [10, 20, 30]
    assert upper_bound_asc(testc, 5) == 0, 'asc test c'
    assert lower_bound_asc(testc, 5) == 0, 'asc test c'
    assert upper_bound_asc(testc, 40) == 3, 'asc test c'
    assert lower_bound_asc(testc, 40) == 3, 'asc test c'
    # dsc
    testa = [30, 30, 20, 20, 10, 10]
    assert upper_bound_dsc(testa, 20) == 1, 'dsc test a'
    assert lower_bound_dsc(testa, 20) == 3, 'dsc test a'
    testb = [40, 30, 15, 10]
    assert upper_bound_dsc(testb, 20) == 1, 'dsc test b'
    assert lower_bound_dsc(testb, 20) == 1, 'dsc test b'
    testc = [30, 20, 10]
    assert upper_bound_dsc(testc, 5) == 2, 'dsc test c'
    assert lower_bound_dsc(testc, 5) == 2, 'dsc test c'
    assert upper_bound_dsc(testc, 40) == -1, 'dsc test c'
    assert lower_bound_dsc(testc, 40) == -1, 'dsc test c'
