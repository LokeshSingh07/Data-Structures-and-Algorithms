// 658. Find K Closest Elements

// Method 1: diff arr + sort
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>> diff;

        for(int num: arr){
            diff.push_back({abs(num-x), num});
        }

        sort(begin(diff), end(diff));

        vector<int> ans(k);
        for(int i=0; i<k; i++){
            ans[i] = diff[i].second;
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};


// Method 2: 
