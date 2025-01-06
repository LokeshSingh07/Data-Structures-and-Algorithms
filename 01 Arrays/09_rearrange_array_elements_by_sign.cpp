// 2149. Rearrange Array Elements by Sign

// Method 1 : Using two vectors
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1, v2;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int ele = nums[i];
            if(ele > 0) v1.push_back(ele);
            else v2.push_back(ele);
        }

        vector<int> ans;
        for(int i=0; i<v1.size(); i++){
            ans.push_back(v1[i]);
            ans.push_back(v2[i]);
        }

        return ans;
    }
};


// Method 2 : Using two pointers technique
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0;
        int neg = 1;

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};