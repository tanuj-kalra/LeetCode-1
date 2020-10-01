class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
		int Median1 = 0, Median2 = 0;
		int leftOffset = 0;
		//int swapNums = 0;
		bool Is2Median1 = false, Is2Median2 = false;
		if (size1 == 0){
			if ((size2 - 1) % 2 == 0)
				return nums2[(size2 - 1) / 2];
			return ((double)nums2[(size2 - 1) / 2] + nums2[(size2 - 1) / 2 + 1]) / 2;
		}
		if (size2 == 0) {
			if ((size1 - 1) % 2 == 0)
				return nums1[(size1 - 1) / 2];
			return ((double)nums1[(size1 - 1) / 2] + nums1[(size1 - 1) / 2 + 1]) / 2;
		}

		auto *pNums1 = &nums1;
		auto *pNums2 = &nums2;
		if (size1 < size2){
			pNums1 = &nums2;
			pNums2 = &nums1;
			size1 = (*pNums1).size();
			size2 = (*pNums2).size();
		}
		if (size1 == 1)
			return ((double)nums1[0] + nums2[0]) / 2;
		while (size2 > 2){
			Median1 = (size1 - 1) / 2 - leftOffset;
			Median2 = (size2 - 1) / 2 + leftOffset;
			size1 += Median2 - leftOffset;
			size2 -= Median2 - leftOffset;	//数组2长度变短
			if ((*pNums1)[Median1] >= (*pNums2)[Median2]){
				leftOffset = Median2;//leftOffset += Median2 - leftOffset;	//数组2左边的数列放到数组1的左边，数组1长度增长
			}
		}
		Median1 = (size1 - 1) / 2 - leftOffset;
 		Median2 = (size2 - 1) / 2 + leftOffset;
// 		int sortArray[7] = { 0 };
// 		int _num1 = 0;
// 		if (size1 % 2 == 1) {
// 			if (Median1 + 1 < (*pNums1).size() && Median1 - 1 >= 0){
// 				_num1 = 3;
// 				Median1--;
// 			}
// 			else
// 				_num1 = 1;
// 		}
// 		else {
// 			if (Median1 + 2 < (*pNums1).size() && Median1 - 1 >= 0){
// 				_num1 = 4;
// 				Median1--;
// 			}
// 			else
// 				_num1 = 2;
// 		}
// 		for (int i = 0, j = 0, k = 0; k<_num1 + size2;)
// 		{
// 			if ((*pNums1)[Median1 + i] <= (*pNums2)[Median2 + j])
// 				sortArray[k++] = (*pNums1)[Median1 + i++];
// 			else
// 				sortArray[k++] = (*pNums2)[Median2 + j++];
// 			if (i >= _num1)
// 				while (j<size2) sortArray[k++] = (*pNums2)[Median2 + j++];
// 			else if (j >= size2)
// 				while (i<_num1) sortArray[k++] = (*pNums1)[Median1 + i++];
// 		}
// 		if ((_num1 + size2) % 2 == 1)
// 			return sortArray[(_num1 + size2) / 2];
// 		else
// 			return ((double)sortArray[(_num1 + size2) / 2] + sortArray[(_num1 + size2) / 2 - 1]) / 2;
		//*
		if (size2 == 2){//2个中值
			if (size1 % 2 == 0){//两个中值
				double sum = 0.0;
				if ((*pNums1)[Median1] >= (*pNums2)[Median2 + 1]){
					if (Median1 - 1 >= 0)
						sum = (*pNums1)[Median1 - 1] >= (*pNums2)[Median2 + 1] ? (*pNums1)[Median1 - 1] : (*pNums2)[Median2 + 1];
					else
						sum = (*pNums2)[Median2 + 1];
					return (sum + (*pNums1)[Median1]) / 2;
				}
				else if ((*pNums1)[Median1+1] < (*pNums2)[Median2]){
					if (Median1 + 2 < (*pNums1).size())
						sum = (*pNums1)[Median1 + 2] <= (*pNums2)[Median2] ? (*pNums1)[Median1 + 2] : (*pNums2)[Median2];
					else
						sum = (*pNums2)[Median2];
					return (sum + (*pNums1)[Median1+1]) / 2;
				}
				else if ((*pNums1)[Median1] >= (*pNums2)[Median2]){
					sum = (*pNums1)[Median1 + 1] <= (*pNums2)[Median2 + 1] ? (*pNums1)[Median1 + 1] : (*pNums2)[Median2 + 1];
					return (sum + (*pNums1)[Median1]) / 2;
				}
				else if ((*pNums1)[Median1] < (*pNums2)[Median2]){
					sum = (*pNums1)[Median1 + 1] <= (*pNums2)[Median2 + 1] ? (*pNums1)[Median1 + 1] : (*pNums2)[Median2 + 1];
					return (sum + (*pNums2)[Median2]) / 2;
				}
			}
			else if (size1 % 2 == 1){//一个中值
				if ((*pNums1)[Median1] >= (*pNums2)[Median2]){
					if ((*pNums1)[Median1] >= (*pNums2)[Median2+1]){
						return (*pNums1)[Median1 - 1] >= (*pNums2)[Median2+1] ? (*pNums1)[Median1 - 1] : (*pNums2)[Median2+1];
					}else{
						return (*pNums1)[Median1];
					}
				}else{
					if ((*pNums1)[Median1 + 1] >= (*pNums2)[Median2 + 1]){
						return (*pNums2)[Median2];
					}
					else{
						return (*pNums1)[Median1 + 1] < (*pNums2)[Median2] ? (*pNums1)[Median1 + 1] : (*pNums2)[Median2];
					}
				}
			}
		}
		else if (size2 == 1){//1个中值
			if (size1 % 2 == 0){//两个中值
				if ((*pNums1)[Median1] < (*pNums2)[Median2]){
					return (*pNums1)[Median1 + 1] <= (*pNums2)[Median2] ? (*pNums1)[Median1+1] : (*pNums2)[Median2];
				}else{
					return (*pNums1)[Median1];
				}
			}
			else if (size1 % 2 == 1){//一个中值
				double sum = 0.0;
				if ((*pNums1)[Median1] >= (*pNums2)[Median2]){
					sum = (*pNums1)[Median1 - 1] >= (*pNums2)[Median2] ? (*pNums1)[Median1-1] : (*pNums2)[Median2];
				}else{
					sum = (*pNums1)[Median1 + 1] <= (*pNums2)[Median2] ? (*pNums1)[Median1+1] : (*pNums2)[Median2];
				}
				return (sum + (*pNums1)[Median1]) / 2;
			}
		}//*/
    }
};

// I want to contribute a Binary Search Short Code (Alternative).
Kindly Acknowledge
double Solution::findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        
        int low = 0;
        int high = m;
        double ans;
        while(low<=high){
            int partitionX = (low+high)/2;
            int partitionY = (m+n+1)/2 - partitionX;
            
            int maxLeftX =  partitionX==0?INT_MIN:nums1[partitionX-1];
            int minRightX = partitionX==m?INT_MAX:nums1[partitionX];
            
            int maxLeftY =  partitionY==0?INT_MIN:nums2[partitionY-1];
            int minRightY = partitionY==n?INT_MAX:nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((m+n)%2==0)
                {
                   double temp1 = max(maxLeftX,maxLeftY);
                   double temp2 = min(minRightX,minRightY);
                   ans = (temp1+temp2)/(2*1.0);
                   break;
                }
                else{
                    ans = max(maxLeftX,maxLeftY)*1.0;
                    break;
                }
            }
            else if(maxLeftX>minRightY){
                high = partitionX-1;
            }
            else low = partitionX+1;
        }
        return ans;
}
