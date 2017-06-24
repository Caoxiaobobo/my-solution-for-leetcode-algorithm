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

/*
 * �����ϵĸ��Ӷ�ΪO(log(m+n)),�����ڲ���ʱû����һ�ֽⷨ�죬Ӧ��������Ǹ��ݹ鴦������
 * �����鰴��������������
 * ��ĿҪ���ҵ�median�������һ��m+n���ȵ����飬����median�϶���(m+n)/2��,������k=(m+n)/2���Ҷ��ڳ���Ϊm��n����������(m<n)Ϊa,b,����a��b�зֱ�ȡi=min(m,k/2)��j=k-min(m,k/2),
 * ���ڸ�λ�ô��������������1��a��b�ڸ�λ�ô���ȣ���϶�Ϊmedian;��2��a�ڸ�λ��С��b������Խ�a�дӿ�ʼ����λ�õ�ֵ��ȥ����Ϊ�ϲ���ô��϶�����Ϊmedian���������൱�ڽ�i�����ƶ���j�����ƶ����ұ������
 * ΪK����3��ͬ��a�ڸ�λ�ô���bʱ������Խ�b�е�k/2������ȥ��
 * ������ƹ㵽����Ѱ��median,�������k�����԰����ַ�����⣬ֻ�ǳ�ʼֵ��ͬ����
class Solution {
public:
    //get the kth number of two sorted array
    double findkth(vector<int>::iterator a,int m,
                vector<int>::iterator b,int n,
                int k)
    {
        if(m >  n)
            return findkth(b,n,a,m,k);
        if(m == 0)
            return b[k-1];
        if(k == 1)
            return min(*a,*b);

        int pa = min(k/2,m),pb = k - pa;
        if(*(a + pa - 1) < *(b + pb -1))
            return findkth(a+pa,m-pa,b,n,k-pa);
        else if(*(a + pa -1) > *(b + pb -1))
            return findkth(a,m,b+pb,n-pb,k-pb);
        else
            return *(a+pa-1);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator a = nums1.begin();
        vector<int>::iterator b = nums2.begin();
        int total = nums1.size() + nums2.size();

        // judge the total num of two arrays is odd or even
        if(total & 0x1)
            return findkth(a,nums1.size(),
                           b,nums2.size(),
                           total/2+1);
        else
            return (findkth(a,nums1.size(),
                           b,nums2.size(),
                           total/2) +
                    findkth(a,nums1.size(),
                            b,nums2.size(),
                            total/2 + 1))/2;
    }
};
 */
