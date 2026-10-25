class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        if n==0:
            return

        k%=n

        nums[:]=nums[::-1]
        nums[:k]=nums[:k][::-1]
        nums[k:]=nums[k:][::-1]