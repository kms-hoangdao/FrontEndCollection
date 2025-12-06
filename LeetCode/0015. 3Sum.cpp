class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        nSum(nums, res, path, 0, 0, 3);
        return res;
    }

    void nSum(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int start, int target, int n) {
        if(n == 2) {
            int l = start;
            int r = nums.size() - 1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    vector<int> comb = path;
                    comb.push_back(nums[l]);
                    comb.push_back(nums[r]);
                    res.push_back(comb);
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if(sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            nSum(nums, res, path, i + 1, target - nums[i], n - 1);
            path.pop_back();
        }
    }
};
