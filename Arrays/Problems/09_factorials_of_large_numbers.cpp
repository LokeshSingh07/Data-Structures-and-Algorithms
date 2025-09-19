// Factorials of large numbers

class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> ans(1,1);
        long carry=0;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<ans.size(); j++){
                long mul =  ans[j]*i + carry;
                int digit = mul%10;
                carry = mul/10;
                
                ans[j] = digit; // cacth
            }
            
            while(carry){
                int digit = carry%10;
                carry /= 10;
                ans.push_back(digit);
            }
            carry=0;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};