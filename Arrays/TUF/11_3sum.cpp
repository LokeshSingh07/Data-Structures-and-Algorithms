// 15. 3Sum

// Method 1:  Brute force --> TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    vector<int> temp;
                    if(nums[i] + nums[j] + nums[k] == 0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it: st){
            ans.push_back(it);
        }

        return ans;
    }
};


// Method 2: sorting + two pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;

        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        for(auto &it: st){
            ans.push_back(it);
        }

        return ans;
    }
};