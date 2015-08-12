int reverse(int x) {
    long long tmp = 0;
	while (x){
		tmp *= 10;
		tmp += x % 10;
		x /= 10;
	}
	if (tmp > INT32_MAX || tmp < INT32_MIN)
		return 0;
	return (int)tmp;
}
