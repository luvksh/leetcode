//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int a = _findRankSortedArrays(nums1, nums2, 0, 0, (nums1.size() + nums2.size()+1) / 2);
		int b = a;
		if ((nums1.size() + nums2.size()) % 2 == 0)
			b = _findRankSortedArrays(nums1, nums2, 0, 0, (nums1.size() + nums2.size()+2) / 2 );
		return (a + b) / 2.0;
	}
	int _findRankSortedArrays(vector<int>& nums1, vector<int>& nums2, int i, int j, int rank) {
		int s1 = nums1.size() - i;
		int s2 = nums2.size() - j;
		if (s1 == 0)
			return nums2[j + rank - 1];
		if (s2 == 0)
			return nums1[i + rank - 1];
		if (rank == 1)
			return min(nums1[i], nums2[j]);
		int x = min(rank / 2, s1);
		int y = min(rank / 2, s2);
		int a = nums1[i + x - 1];
		int b = nums2[j + y - 1];
		if (b > a)
			return _findRankSortedArrays(nums1, nums2, i+x, j, rank-x);
		else
			return _findRankSortedArrays(nums1, nums2, i , j+y, rank-y);
	}
};