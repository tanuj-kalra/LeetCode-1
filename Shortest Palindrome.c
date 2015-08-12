char* shortestPalindrome(char* s) {
    int maxOut = strlen(s) - 1;
	int i = 0;
	int j = 0, maxIn = 0;
	int minLeft = 0;
	for (; i < maxOut; i++){
		for (j = 0, maxIn = maxOut - i; j < maxIn - j; j++){
			if (s[j] != s[maxIn - j])  break;
		}
		if (j >= maxIn - j)
			break;
	}
	minLeft = i;
// 	if (minLeft == 0)
// 		return s;
// 	for (j = maxOut; j >= 0; j--)
// 		s[j + minLeft] = s[j];
// 	maxOut += minLeft;
// 	for (; minLeft >= 0; minLeft--)
// 		s[minLeft] = s[maxOut - minLeft];
// 	return s;
	if (minLeft == 0)
		return s;
	char *strRet = (char *)malloc(minLeft + maxOut +1);
	strcpy(strRet + minLeft,s);
	for (; minLeft >= 0; minLeft--)
		strRet[minLeft] = s[maxOut - minLeft];
	return strRet;
}
