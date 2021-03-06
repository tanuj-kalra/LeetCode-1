double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size1 = 0, size2 = 0;
	int Median1 = 0, Median2 = 0;
	int leftOffset = 0;
	if (nums1Size == 0){
		if ((nums2Size - 1) % 2 == 0)
			return nums2[(nums2Size - 1) / 2];
		return ((double)nums2[(nums2Size - 1) / 2] + nums2[(nums2Size - 1) / 2 + 1]) / 2;
	}
	if (nums2Size == 0) {
		if ((nums1Size - 1) % 2 == 0)
			return nums1[(nums1Size - 1) / 2];
		return ((double)nums1[(nums1Size - 1) / 2] + nums1[(nums1Size - 1) / 2 + 1]) / 2;
	}//*/

	int *pNums1 = NULL;
	int *pNums2 = NULL;
	if (nums1Size < nums2Size){
		pNums1 = nums2;
		pNums2 = nums1;
		size1 = nums2Size;
		size2 = nums1Size;
		nums1Size = size1;
	}
	else
	{
		pNums1 = nums1;
		pNums2 = nums2;
		size1 = nums1Size;
		size2 = nums2Size;
	}
	/*if (size1 == 1)
		return ((double)nums1[0] + nums2[0]) / 2;*/
	while (size2 > 2){
		Median1 = (size1 - 1) / 2 - leftOffset;
		Median2 = (size2 - 1) / 2 + leftOffset;
		size1 += Median2 - leftOffset;
		size2 -= Median2 - leftOffset;	//数组2长度变短
		if (pNums1[Median1] >= pNums2[Median2]){
			leftOffset = Median2;//leftOffset += Median2 - leftOffset;	//数组2左边的数列放到数组1的左边，数组1长度增长
		}
	}
	Median1 = (size1 - 1) / 2 - leftOffset;
	Median2 = (size2 - 1) / 2 + leftOffset;
	int sortArray[7] = { 0 };
	int _num1 = 0;
	if (size1 % 2 == 1) {
		if (Median1 + 1 < nums1Size && Median1 - 1 >= 0){
			_num1 = 3;
			Median1--;
		}
		else
			_num1 = 1;
	}
	else {
		if (Median1 + 2 < nums1Size && Median1 - 1 >= 0){
			_num1 = 4;
			Median1--;
		}
		else
			_num1 = 2;
	}
	for (int i = 0, j = 0, k = 0; k<_num1 + size2;)
	{
		if (pNums1[Median1 + i] <= pNums2[Median2 + j])
			sortArray[k++] = pNums1[Median1 + i++];
		else
			sortArray[k++] = pNums2[Median2 + j++];
		if (i >= _num1)
			while (j<size2) sortArray[k++] = pNums2[Median2 + j++];
		else if (j >= size2)
			while (i<_num1) sortArray[k++] = pNums1[Median1 + i++];
	}
	if ((_num1 + size2) % 2 == 1)
		return sortArray[(_num1 + size2)/2];
	else
		return ((double)sortArray[(_num1 + size2) / 2] + sortArray[(_num1 + size2) / 2 -1])/2;
	/*if (size2 == 2){//2个中值
		if (size1 % 2 == 0){//两个中值
			double sum = 0.0;
			if (pNums1[Median1] >= pNums2[Median2 + 1]){
				if (Median1 - 1 >= 0)
					sum = pNums1[Median1 - 1] >= pNums2[Median2 + 1] ? pNums1[Median1 - 1] : pNums2[Median2 + 1];
				else
					sum = pNums2[Median2 + 1];
				return (sum + pNums1[Median1]) / 2;
			}
			else if (pNums1[Median1 + 1] < pNums2[Median2]){
				if (Median1 + 2 < nums1Size)
					sum = pNums1[Median1 + 2] <= pNums2[Median2] ? pNums1[Median1 + 2] : pNums2[Median2];
				else
					sum = pNums2[Median2];
				return (sum + pNums1[Median1 + 1]) / 2;
			}
			else if (pNums1[Median1] >= pNums2[Median2]){
				sum = pNums1[Median1 + 1] <= pNums2[Median2 + 1] ? pNums1[Median1 + 1] : pNums2[Median2 + 1];
				return (sum + pNums1[Median1]) / 2;
			}
			else if (pNums1[Median1] < pNums2[Median2]){
				sum = pNums1[Median1 + 1] <= pNums2[Median2 + 1] ? pNums1[Median1 + 1] : pNums2[Median2 + 1];
				return (sum + pNums2[Median2]) / 2;
			}
		}
		else if (size1 % 2 == 1){//一个中值
			if (pNums1[Median1] >= pNums2[Median2]){
				if (pNums1[Median1] >= pNums2[Median2 + 1]){
					return pNums1[Median1 - 1] >= pNums2[Median2 + 1] ? pNums1[Median1 - 1] : pNums2[Median2 + 1];
				}
				else{
					return pNums1[Median1];
				}
			}
			else{
				if (pNums1[Median1 + 1] >= pNums2[Median2 + 1]){
					return pNums2[Median2];
				}
				else{
					return pNums1[Median1 + 1] < pNums2[Median2] ? pNums1[Median1 + 1] : pNums2[Median2];
				}
			}
		}
	}
	else if (size2 == 1){//1个中值
		if (size1 % 2 == 0){//两个中值
			if (pNums1[Median1] < pNums2[Median2]){
				return pNums1[Median1 + 1] <= pNums2[Median2] ? pNums1[Median1 + 1] : pNums2[Median2];
			}
			else{
				return pNums1[Median1];
			}
		}
		else if (size1 % 2 == 1){//一个中值
			double sum = 0.0;
			if (pNums1[Median1] >= pNums2[Median2]){
				sum = pNums1[Median1 - 1] >= pNums2[Median2] ? pNums1[Median1 - 1] : pNums2[Median2];
			}
			else{
				sum = pNums1[Median1 + 1] <= pNums2[Median2] ? pNums1[Median1 + 1] : pNums2[Median2];
			}
			return (sum + pNums1[Median1]) / 2;
		}
	}//*/
}
