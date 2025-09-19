// 75. Sort Colors

// Method 1 : counting 0s 1s 2s 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        // count 0s 1s 2s
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) zeros++;
            else if(nums[i]==1) ones++;
            else twos++; 
        }

        // place it 
        int idx=0;
        while(zeros--){
            nums[idx++] = 0;
        }
        while(ones--){
            nums[idx++] = 1;
        }
        while(twos--){
            nums[idx++] = 2;
        }
    }
};


// Method 2 : two pointer
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int i = 0;

        while(i <= e){
            if(nums[i] == 0) swap(nums[s++], nums[i++]);
            else if(nums[i] == 1) i++;
            else swap(nums[i], nums[e--]);
        }
    }
};