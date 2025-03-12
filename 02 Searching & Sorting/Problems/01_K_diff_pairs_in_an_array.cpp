// 532. K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        set<pair<int,int>> st;
        int i=0, j=1;

        while(j<n){
            int diff = abs(nums[i] - nums[j]);
            if(diff == k){
                st.insert({nums[i], nums[j]});
                j++;
                i++;    //  catch
            }
            else if(diff > k){
                i++;
            }
            else{
                j++;
            }

            if(i==j) j++;       // yaha glti kri thi       
        }

        return st.size();
    }
};