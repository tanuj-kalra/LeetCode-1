class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
		int lenMin = strs[0].size();
		if (lenMin == 0) return strs[0];
		for (int i = 1; i < strs.size(); i++){
			int tmp = strs[0].size();
			if (tmp < lenMin) lenMin = tmp;
		}
		for (int i = 1; i < strs.size(); i++){
			if (strs[i].compare(0, lenMin, strs[i - 1],0, lenMin) != 0){
				lenMin--;
				i--;
			}
		}
		if (lenMin == 0) return "";
		strs[0].resize(lenMin);
		return strs[0];
    }
};
