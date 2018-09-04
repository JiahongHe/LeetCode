class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);
        int left = 0;
        int right = nums1.size();
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            int partitionX = mid;
            int partitionY = (len1 + len2 + 1) / 2 - mid;
            int maxLeftX = partitionX == 0? INT_MIN : nums1[partitionX - 1];
            int minRightX = partitionX >= len1? INT_MAX : nums1[partitionX];
            int maxLeftY = partitionY == 0? INT_MIN : nums2[partitionY - 1];
            int minRightY = partitionY >= len2? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && minRightX >= maxLeftY) {
                if ((len1 + len2) % 2 != 0) return (double)max(maxLeftX, maxLeftY);
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / (double)2;
            }
            if (maxLeftX > minRightY) right = mid - 1;
            if (maxLeftX < minRightY) left = mid + 1;
        }
        return 0;
    }
};