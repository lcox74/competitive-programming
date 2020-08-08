#include <vector>

// Helper function to get the next lowest value of two sorted arrays
int nextLowestValue(std::vector<int>& nums1, int* pos1, std::vector<int>& nums2, int* pos2) {
    if ((*pos1) < nums1.size() && (*pos2) < nums2.size()) {
        return (nums1[*pos1] < nums2[*pos2]) ? nums1[(*pos1)++] : nums2[(*pos2)++];
    } else if (nums1.size() == 0 || (*pos1) >= nums1.size()) {
        return nums2[(*pos2)++];
    }
    return nums1[(*pos1)++];
}

/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 */
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	if (nums1.size() == 1 && nums2.size() == 0) return nums1[0];
	if (nums1.size() == 0 && nums2.size() == 1) return nums2[0];

	const size_t total = nums1.size() + nums2.size();
	const int mid_abs = (int)(total / 2.0);

	int i = 0, x = 0, y = 0, prev;
	while (i <= mid_abs) {
	    if (i == mid_abs) {
		if (1 - (total & 1))   return (prev + nextLowestValue(nums1, &x, nums2, &y)) / 2.0;
		else if (i == mid_abs) return nextLowestValue(nums1, &x, nums2, &y);
	    }
	    prev = nextLowestValue(nums1, &x, nums2, &y);
	    i++;
	}
	return 0.0;
}
