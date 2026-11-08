class Solution:
    def reversePairs(self, nums: list[int]) -> int:

        def mergeSort(left, right):
            if left >= right:
                return 0

            mid = (left + right) // 2

            count = mergeSort(left, mid)
            count += mergeSort(mid + 1, right)

            # Count reverse pairs
            j = mid + 1

            for i in range(left, mid + 1):
                while j <= right and nums[i] > 2 * nums[j]:
                    j += 1

                count += j - (mid + 1)

            # Merge two sorted halves
            temp = []
            i = left
            j = mid + 1

            while i <= mid and j <= right:
                if nums[i] <= nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    temp.append(nums[j])
                    j += 1

            while i <= mid:
                temp.append(nums[i])
                i += 1

            while j <= right:
                temp.append(nums[j])
                j += 1

            nums[left:right + 1] = temp

            return count

        return mergeSort(0, len(nums) - 1)