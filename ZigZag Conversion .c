char* convert(char* s, int numRows) {
    int lenth = strlen(s);
	if (lenth <= 2 || numRows == 1) return s;
	char *p = (char *)malloc(lenth);
	int n = 0 , m = 0;//n：行号；m：列号,第几列。
	int cycle = numRows + numRows - 2;
	int numCols = lenth / cycle + 1;//总列数
	for (int i = 0; i < lenth; ){
		if (n == 0 || n == numRows-1){//短行
			int index = m*cycle + n;
			if (index >= lenth){
				n++;
				m = 0;
				continue;
			}
			p[i++] = s[index];// [m*cycle + n];
		}
		else{//长行
			int index = m*cycle + n;
			if (index >= lenth){
				n++;
				m = 0;
				continue;
			}
			p[i++] = s[index];// [m*cycle + n];
			index = m*cycle + numRows-1 + numRows-1-n;
			if (index >= lenth){
				n++;
				m = 0;
				continue;
			}
			p[i++] = s[index];
		}

		if (++m >= numCols){
			m = 0;
			n++;
		}
	}
	for (int i = 0; i < lenth; i++){
		s[i] = p[i];
	}
	free(p);
	return s;
}
