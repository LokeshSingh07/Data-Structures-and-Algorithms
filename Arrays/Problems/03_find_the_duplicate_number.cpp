// 287. Find the Duplicate Number

// Method 1 : Nngative Marking
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            int idx = abs(nums[i]);

            if(nums[idx] < 0){  // already visited
                return idx;
            }

            nums[idx] *= -1;
        }

        return -1;        
    }
};


// Method 2 : Posting method
class Solution {
public:
    // positioning method
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        while(1){
            int idx = nums[0];

            if(nums[idx] == nums[0]) return idx;
            swap(nums[0], nums[idx]);
        }
        
        return -1;
    }
};

// same as above but in function
int placeToCorrectPostion(vector<int> &nums){
    while(nums[0] != nums[nums[0]]){
        swap(nums[0], nums[nums[0]]);
    }

    return nums[0];
}