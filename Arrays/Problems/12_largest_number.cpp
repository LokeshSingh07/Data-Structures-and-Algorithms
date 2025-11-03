// 179. Largest Number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums), end(nums), [](const int &a, const int &b){
            string x = to_string(a);
            string y = to_string(b);
            return x+y > y+x;
        });

        if(nums[0] == 0) return "0";            // edge case

        string result = "";
        for(auto num: nums){
            result += to_string(num);
        }

        return result;
    }
};