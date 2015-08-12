class Solution {
public:
    int findMin(vector<int>& nums) {
        //if (nums.size() == 1)
		//	return nums[0];
		int left = 0, right = nums.size()-1, pivot = right / 2;
		while (right-left > 1){
			if (nums[pivot] > nums[left]){
				if (nums[right] >= nums[pivot])
					return nums[left];
				left = pivot;
				pivot = (left + right) / 2;
			}
			else if (nums[pivot] == nums[left]){
				while (++left < pivot && nums[left] == nums[pivot]);
				if (left<pivot)
					return nums[left]<nums[pivot] ? nums[left] : nums[pivot];
					/*if(nums[left]<nums[pivot]) return nums[left];
					else return nums[pivot];*/
			/*	while (++left < pivot){
				    if(nums[left] == nums[pivot]) continue;
				    else if(nums[left] < nums[pivot]) return nums[left];
				    else return nums[pivot];
				}*/
				left = pivot;
				pivot = (left + right) / 2;
			}
			else{
				right = pivot;
				pivot = (left + right) / 2;
			}
		}
		//pivot = nums[pivot] <= nums[left] ? pivot : left;
		//return nums[pivot] <= nums[right] ? nums[pivot] : nums[right];
		if(nums[pivot] <= nums[left]){
		    if(nums[pivot] <= nums[right])
		        return nums[pivot];
		    else
		        return nums[right];
		}
		else{
		    if(nums[left] <= nums[right])
		        return nums[left];
		    else
		        return nums[right];
		}
    }
};
