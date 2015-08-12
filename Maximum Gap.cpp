#define RADIX 8


class Solution {
public:
void baseSort(int *data, int lenth, int radix){
	int count[RADIX] = { 0 }, offset[RADIX] = { 0 };
	for (int i = 0; i < lenth; i++){
		count[(data[i] / radix) % RADIX]++;
	}
	for (int i = 1; i < RADIX; i++){
		count[i] += count[i - 1];
		offset[i] = count[i - 1];
	}
	for (int times = 0; times < RADIX; times++){
		int key = times;
		while (offset[times] < count[times]){
			int nextKey = (data[offset[key]] / radix) % RADIX;
			if (nextKey == key){
				offset[key]++;
			}
			else{
				while (nextKey == (data[offset[nextKey]] / radix) % RADIX){
					offset[nextKey]++;
				}
				nextKey = (data[offset[key]] / radix) % RADIX;				
				//swap(data[offset[key]], data[offset[nextKey]]);
				{
				    int temp = data[offset[key]];
				    data[offset[key]] = data[offset[nextKey]];
				    data[offset[nextKey]] = temp;
				}
				offset[nextKey]++;
			}
		}
		if (times == 0 && count[0]>1 && radix >= RADIX)
			baseSort(data, count[0], radix / RADIX);
		else if (times != 0 && count[times] - count[times - 1]>1 && radix >= RADIX)
			baseSort(&data[count[times - 1]], count[times] - count[times - 1], radix / RADIX);
	}
}
void myRadixSort(int *data, int lenth){
	int maxRadix = RADIX;
	for (int i = 0; i < lenth; i++){
		while (data[i]>=maxRadix)
			maxRadix *= RADIX;
	}
	maxRadix /= RADIX;
	baseSort(data, lenth, maxRadix);
}
    int maximumGap(vector<int>& nums) {
        int maxGap = 0;
        if(nums.size() <=1)   return 0;
    	myRadixSort((int *)nums[0], nums.size());
    	for (int i = 1; i < nums.size(); i++){
    		int temp = nums[i] - nums[i-1];
    		maxGap = maxGap > temp ? maxGap : temp;
    	}
    	return maxGap;
    }
};
