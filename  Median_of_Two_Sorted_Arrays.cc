/*
 * question:
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3],nums2 = [2]
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2],nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */

/*
 * first solution: ��Ϊ���������Ѿ�������ֻ�����һ�μ��ɽ���鲢������ɣ�����ҵ�median
 *
 *problems: ʱ�临�Ӷ�ΪO(M+N),��δ�ﵽ�涨��O(log(m+n))
 *

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int size1 = nums1.size();
    	int size2 = nums2.size();
    	if(size2 == 0)
    		return size1%2?nums1[size1/2]:(double(nums1[(size1-1)/2])+nums1[size1/2])/2;
    	if(size1 == 0)
    		return size2%2?nums2[size2/2]:(double(nums2[(size2-1)/2])+nums2[(size2)/2])/2;
    	vector<double> result;
    	int j = 0, i = 0;
    	while(i < size1 && j < size2){
    		if(nums1[i] < nums2[j])
    			result.push_back(nums1[i++]);
    		else
    			result.push_back(nums2[j++]);
    	}
    	while(i<size1)
    		result.push_back(nums1[i++]);

    	while(j<size2)
    		result.push_back(nums2[j++]);

    	return (size1+size2)%2?result[(size1+size2)/2]:(result[(size1+size2-1)/2]+result[(size1+size2)/2])/2;
    }
};
*/
