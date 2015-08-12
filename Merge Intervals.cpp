/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    void quickSort(Interval * arrs, int left, int right){
    	int oldLeft = left;
    	int oldRight = right;
    	bool flag = true;
    	Interval baseArr = arrs[oldLeft];
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
    vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size()<=0) return intervals;
        //sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
		quickSort(&intervals[0], 0, intervals.size()-1);
		auto current = intervals.begin();
		for_each(intervals.begin(), intervals.end(), [&current, &intervals](Interval data){
			if (current->end >= data.start){
				if (current->end < data.end)
					current->end = data.end;
			}
			else{
				current++;
				current->start = data.start;
				current->end = data.end;
			}
		});
		intervals.resize(current - intervals.begin()+1);//*/
// 		int *data = (int *)&intervals[0];
// 		int *current = data;
// 		for (int i = 0; i < intervals.size() * 2; i += 2){
// 			if (current[1] >= data[i]){
// 				if (current[1] < data[i + 1])
// 					current[1] = data[i + 1];
// 			}
// 			else{
// 				current += 2;
// 				current[0] = data[i];
// 				current[1] = data[i + 1];
// 			}
// 		}
// 		intervals.resize((current - data)/2 + 1);
		return intervals;
    }
};
