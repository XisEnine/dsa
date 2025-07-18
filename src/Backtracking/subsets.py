from typing import List

def subsets(nums: List[int]):
    result = []
    
    def dfs(index, subset):
        # Always add the current subset
        result.append(subset[:])
        
        for i in range(index, len(nums)):
            # include nums[i]
            subset.append(nums[i])
            # recurse with next index
            dfs(i + 1, subset)
            # backtrack
            subset.pop()
    
    dfs(0, [])
    return result

# Test
nums = [1, 2, 3]
result = subsets(nums)
print(result)
