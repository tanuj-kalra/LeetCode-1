class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        register uint32_t sum = 0;
    	/*for (int i = 0; i <= 15; i++){
    		//sum += ((n >> i)& 1) << (31 - i);
    		//sum += ((n << i)&(1<<31)) >> (31 - i);
    		sum |= ((n << 31 - i) >> 31) << (31 - i);
    		sum |= ((n >> 31 - i) << 31) >> (31 - i);
    	}//*/
    	for (register uint32_t i = 1,j=1<<31; i >0; i = i << 1,j = j>>1){
    		if (n & i)
    			sum |= j;
    	}//*/
    	return sum;
    }
};
