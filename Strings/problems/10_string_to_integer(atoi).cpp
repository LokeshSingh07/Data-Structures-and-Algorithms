// 8. String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long result=0, i=0, sign=1;

        // leaadaing space
        while(s[i] == ' ') i++;

        // sign
        if(i<n && (s[i] == '-' || s[i]=='+')){
            sign = s[i]=='-' ? -1 : 1;
            i++;
        }

        while(i<n && isdigit(s[i])){
            result = result*10 + (s[i]-'0');

            if(sign * result >= INT_MAX) return INT_MAX;
            if(sign * result <= INT_MIN) return INT_MIN;
            
            i++;
        }
    
        return sign * result;
    }
};