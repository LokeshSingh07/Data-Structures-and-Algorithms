// 69. Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long mid = s+(e-s)/2;
        long mult, ans=-1;

        while(s<=e){
            mult = mid*mid;
            if(mult == x) return mid;
            else if(mult < x){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
            mid = s+(e-s)/2;

        }
        return ans;
    }
};