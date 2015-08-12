int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int *newDigits = digits;
    for (int i = digitsSize -1; i >= 0; i--){
		digits[i]++;
		if (digits[i] >= 10){
			digits[i] = 0;
			if (i == 0){
			    newDigits = malloc((digitsSize+1)*sizeof(int));
				do{ newDigits[digitsSize] = digits[digitsSize - 1]; } while (--digitsSize);
				newDigits[0] = 1;
				(*returnSize)++;
	            return newDigits;
			}
		}
		else break;
	}
	return digits;
}
