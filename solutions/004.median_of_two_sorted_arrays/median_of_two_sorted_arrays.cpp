class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((n + m)&1)
            return findKthSortedArrays(nums1.begin(), m, nums2.begin(), n, (n + m) / 2 + 1);
        else
            return (findKthSortedArrays(nums1.begin(), m, nums2.begin(), n, (n + m) / 2 + 1) +
                    findKthSortedArrays(nums1.begin(), m, nums2.begin(), n, (n + m) / 2)) / 2.0;
    }

    double findKthSortedArrays(vector<int>::iterator nums1_begin, int m, vector<int>::iterator nums2_begin, int n, int k) {
        if (m < n) {
            swap(m, n);
            swap(nums1_begin, nums2_begin);
        }
        if (n == 0)
            return *(nums1_begin + k - 1);
        if (k == 1)
            return min(*nums1_begin, *nums2_begin);

        int pb = min(k / 2, n), pa = k - pb;
        if (*(nums1_begin + pa - 1) > *(nums2_begin + pb - 1))
            return findKthSortedArrays(nums1_begin, m, nums2_begin + pb, n - pb, k - pb);
        else if (*(nums1_begin + pa - 1) < *(nums2_begin + pb - 1))
            return findKthSortedArrays(nums1_begin + pa, m - pa, nums2_begin, n, k - pa);
        else
            return *(nums1_begin + pa - 1);
    }
};
