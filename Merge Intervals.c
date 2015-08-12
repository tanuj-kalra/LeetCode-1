/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
 void quickSort(struct Interval *arrs, int left, int right){
	int oldLeft = left;
	int oldRight = right;
	bool flag = true;
	struct Interval baseArr = arrs[oldLeft];
	while (left < right){
		while (left < right && arrs[right].start >= baseArr.start){
			right--;
			flag = false;
		}
		arrs[left] = arrs[right];
		while (left < right && arrs[left].start <= baseArr.start){
			left++;
			flag = false;
		}
		arrs[right] = arrs[left];
	}
	arrs[left] = baseArr;
	if (!flag){
		quickSort(arrs, oldLeft, left - 1);
		quickSort(arrs, left + 1, oldRight);
	}
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if(intervalsSize<=0) {
        *returnSize=0;
        return intervals;
    }
    quickSort(intervals, 0, intervalsSize - 1);
	int *data = (int *)intervals;
	int *current = data;
	for (int i = 0; i < intervalsSize*2; i += 2){
		if (current[1] >= data[i]){
			if (current[1] < data[i + 1])
				current[1] = data[i + 1];
		}
		else{
			current += 2;
			current[0] = data[i];
			current[1] = data[i + 1];
		}
	}
	*returnSize = (current - data)/2 + 1;
	return intervals;
}
