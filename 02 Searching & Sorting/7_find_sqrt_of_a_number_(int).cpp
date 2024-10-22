// 69. Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;        // e = x/2 , TestCase: x=1 wale me fas jayega
        int ans=-1;

        while(s<=e){
            long mid = s+(e-s)/2;

            if(mid*mid == x) return mid;
            else if(mid*mid < x){
                ans = mid;              // catch -> 8.32... wala case
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return ans;
    }
};