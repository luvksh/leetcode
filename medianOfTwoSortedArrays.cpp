//https://leetcode.com/problems/median-of-two-sorted-arrays/
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size();
		int l2 = nums2.size();
		if (((l1 + l2) & 0x1) == 0)
		{
			double a = findKthElementSortedArray(nums1, 0, l1-1, nums2, 0, l2-1, (l1 + l2 + 1) / 2);
			double b = findKthElementSortedArray(nums1, 0, l1-1, nums2, 0, l2-1, (l1 + l2 + 2) / 2);
			return (a + b) / 2;
		}
		else
		{
			return findKthElementSortedArray(nums1, 0, l1-1, nums2, 0, l2-1, (l1 + l2 + 1) / 2);
		}

	}

	int findKthElementSortedArray(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k)
	{
		if (s1 > e1 )
			return nums2[s2+k - 1];
		if (s2 > e2)
			return nums1[s1+k - 1];
		if (k == 1)
		{
			return min(nums1[s1], nums2[s2]);
		}

		int i = min(e1-s1+1, k / 2);
		int j = min(e2-s2+1, k / 2);
		if (nums1[i - 1 + s1] < nums2[j - 1 + s2])
		{
			return findKthElementSortedArray(nums1, s1 + i, e1, nums2, s2, e2, k - i);
		}
		else
		{
			return findKthElementSortedArray(nums1, s1, e1, nums2, s2 + j, e2, k - j);
		}
	}
};