// 29. Divide Two Integers

// Using Binary Search --> // TODO: Handling edge cases
class Solution {
public:
    int binarySearch(int dividend, int divisor){
        int s=0;
        int e=dividend;
        int ans = -1;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(divisor*mid == dividend) 
                return mid;
            if(divisor*mid < dividend){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return ans;
    }

    int divide(int dividend, int divisor) {
        int absDividend = abs(dividend);
        int absDivisor = abs(divisor);
        int ans = binarySearch(absDividend, absDivisor);

        // TODO: Handling edge cases

        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)){
            return ans;
        }
        else{
            ans = 0 - ans;
            return ans;
        }
    }
};



// Using Bit manipulation
