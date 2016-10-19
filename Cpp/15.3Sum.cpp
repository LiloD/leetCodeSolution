class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){
            return {};
        }
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> resultSet;
        int length = nums.size();
        
        for(int i = 0; i < length-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int left = i+1;
            int right = length-1;
            int target = 0 - nums[i];
            while(left < right){
                int leftNum = nums[left];
                int rightNum = nums[right];
                if(leftNum + rightNum > target){
                    while(right-1 == right){
                        right--;
                    }
                    right--;
                    
                }else if(leftNum + rightNum < target){
                    while(left+1 == left){
                        left++;
                    }
                    left++;
                }else{
                    resultSet.insert({nums[i], leftNum, rightNum});
                    while(right-1 == right){
                        right--;
                    }
                    right--;
                    while(left+1 == left){
                        left++;
                    }
                    left++;
                }
            }
        }
        
        vector<vector<int>> result(resultSet.begin(), resultSet.end());
        
        return result;
    }
};