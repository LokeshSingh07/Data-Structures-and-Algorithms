// Aggressive Cows

class Solution {
  public:
    bool isPossible(vector<int> &nums, int k, int mid){
        int cow = 1;
        int prevPost = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - prevPost >= mid){
                cow++;
                prevPost = nums[i];
            }
            if(cow==k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(begin(stalls), end(stalls));
        
        int s = 0;
        int e = stalls[n-1] - stalls[0];
        int result = -1;
        
        while(s <= e){
            int mid = s+(e-s)/2;
            if(isPossible(stalls, k, mid)){
                result = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return result;
    }
};