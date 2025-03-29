// 29. Divide Two Integers

class Solution {
public:
    int BS(long long dividend, long long divisor){
        long long result = 0;
        long long s = 0;
        long long e = abs(dividend);

        while(s <= e){
            long long mid = s+(e-s)/2;
            if(abs(dividend) >= abs(divisor*mid)){
                result = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return result;
    }

    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;

        long long result = BS((long long)dividend, (long long)divisor);

        if(dividend < 0 == divisor < 0) return result;
        return -result;
    }
};