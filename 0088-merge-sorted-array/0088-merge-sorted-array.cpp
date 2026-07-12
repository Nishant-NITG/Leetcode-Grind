class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Three pointers:
        // p1: last element of nums1's actual data
        // p2: last element of nums2
        // p: last position in nums1 (where we'll place elements)
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        // Merge from the back, comparing the largest remaining elements
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                // nums1's current element is larger, place it at the end
                nums1[p] = nums1[p1];
                p1--;
            } else {
                // nums2's current element is larger or equal, place it
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        // If nums2 still has elements, they all go to the front
        // nums1's remaining elements are already in the correct position
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};