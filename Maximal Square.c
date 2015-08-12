int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
//     for (int i = 0; i<matrixRowSize; i++){
// 		for (int j = 0; j<matrixColSize; j++){
// 			if (matrix[i][j] == '1')
// 				matrix[i][j] = 1;
// 			else
// 				matrix[i][j] = 0;
// 		}
// 	}
// 	for (int i = 1; i<matrixRowSize; i++){
// 		for (int j = 0; j<matrixColSize; j++){
// 			if (matrix[i][j])
// 				matrix[i][j] = matrix[i - 1][j] +1;
// 		}
// 	}
    for (int j = 0; j < matrixColSize; j++){
		matrix[0][j] -= '0';
	}
	for (int i = 1; i<matrixRowSize; i++){
		for (int j = 0; j<matrixColSize; j++){
			if (matrix[i][j] == '1')
				matrix[i][j] = matrix[i - 1][j] + 1;
			else
				matrix[i][j] = 0;
		}
	}
	int maxMtrAll = 0;
	for (int i = 0; i<matrixRowSize; i++){
		int biggerCount = 0;
		for (int j = 0; j<matrixColSize; j++){
			if (matrix[i][j] > maxMtrAll){
				biggerCount++;
				if (biggerCount > maxMtrAll)
				{
					maxMtrAll++;
					j -= maxMtrAll;
					biggerCount = 0;
				}
			}
			else{
				biggerCount = 0;
			}
		}
	}
	/*for (int i = 0; i<matrixRowSize; i++){
		for (int j = 0; j<matrixColSize; j++){
			if (matrix[i][j])
				matrix[i][j] = '1';
			else
				matrix[i][j] = '0';
		}
	}//*/
	return maxMtrAll*maxMtrAll;
}
