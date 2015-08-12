class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = { 0 }, offset[3] = { 0 };
    	for (int i = 0; i < nums.size(); i++) count[nums[i]]++;
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
    				swap(nums[offset[times]], nums[*nextOffset]);
    				(*nextOffset)++;
    			}
    		}
    	}
    }
};
