void sortColors(int* nums, int numsSize) {
    int count[3] = { 0 }, offset[3] = { 0 };
	for (int i = 0; i < numsSize; i++) count[nums[i]]++;
	for (int i = 1; i < 3; i++){
		count[i] += count[i - 1];
		offset[i] = count[i - 1];
	}
	for (int times = 0; times < 3; times++){
		//int *currentOffset = &offset[times];
		while (offset[times] < count[times]){
			int *nextOffset = &offset[nums[offset[times]]];
			if (nums[offset[times]] == times) offset[times]++;
			else{
				while (nums[offset[times]] == nums[*nextOffset]) (*nextOffset)++;
				//swap(nums[offset[times]], nums[*nextOffset]);
				{
					int tmp = nums[*nextOffset];
					nums[*nextOffset] = nums[offset[times]];
					nums[offset[times]] = tmp;
				}
				(*nextOffset)++;
			}
		}
	}
}
