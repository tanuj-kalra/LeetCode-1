class Solution {
public:
    int prihtf2String(int count){
		vector<string> tmp;
		//string strTmp("[");
		for (int i = 0; i < chessboardCurrent.size(); i++){
			string strTmp(chessboardCurrent.size(), '.');
			int k = 0;
			while (chessboardCurrent[i] >> k > 1) k++;
			strTmp[k] = 'Q';
			tmp.push_back(strTmp);
		}
		solveQueens.push_back(tmp);
		return 1;
	}
	int probeNQueens(const int size, int nRow, long long colMark, long long lMark, long long rMark) {
		/*x&(~x+1)取出最低位为1的bit*/
		for (long long mark, available = ~(colMark | lMark | rMark);\
		    mark = available & -available; available &= ~mark)
		{
			chessboardCurrent[nRow] = mark;
			nRow < size - 1 ? probeNQueens(size, nRow + 1, colMark | mark, \
			  (lMark | mark) >> 1 & ~(1 << size - 1), (rMark | mark) << 1 | 1 << size) : prihtf2String(++nums);
		}
		return nums;
	}
	
    vector<vector<string> > solveNQueens(int n) {
        nums = 0;
		chessboardCurrent.resize(n);
		solveQueens.resize(0);
		 probeNQueens(n, 0, ULLONG_MAX << n, ULLONG_MAX << n, ULLONG_MAX << n);
		 return solveQueens;
    }
    private:
	int nums = 0;
	vector<int> chessboardCurrent;
	vector<vector<string> > solveQueens;
};
