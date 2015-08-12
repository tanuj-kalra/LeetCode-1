char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
	int lenMin = strlen(strs[0]);
	if (lenMin == 0) return "";
	for (int i = 1; i < strsSize; i++){
		int tmp = strlen(strs[i]);
		if (tmp < lenMin) lenMin = tmp;
	}
	for (int i = 1; i < strsSize; i++){
		if (strncmp(strs[i - 1], strs[i], lenMin) != 0){
			lenMin--;
			i--;
		}
	}
	if (lenMin == 0) return "";
	strs[0][lenMin] = 0;
	return strs[0];
}
