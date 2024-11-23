# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         a=sorted(nums)
#         res=[]
#         for i in range(len(nums)-2):
#             for j in range(i+1,len(nums)-1):
#                 for k in range(j+1,len(nums)):
#                     b=[]
#                     if(nums[i]+nums[j]+nums[k]==0):
#                         b.append(nums[i])
#                         b.append(nums[j])
#                         b.append(nums[k])
#                         res.append(b)
#         ary=[]
#         for i in res:
#             ary.append(sorted(i))

#         unique_elements = set()
#         result = []
    
#         for inner_list in ary:
#             inner_tuple = tuple(inner_list)
#             if inner_tuple not in unique_elements:
#                 unique_elements.add(inner_tuple)
#                 result.append(inner_list)
#         return result

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)
        
        for i in range(n - 2):
            # Skip duplicates for i
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            left = i + 1
            right = n - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    # Skip duplicates for left and right pointers
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    right -= 1
        
        return res

         

