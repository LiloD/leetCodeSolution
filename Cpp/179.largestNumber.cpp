class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int i, int j)->bool{
            string stri = to_string(i);
            string strj = to_string(j);
            return strj+stri < stri+strj;
        });
        string result = "";
        int i = 0;
        while(nums[i] == 0){
            i++;
        }
        for(; i < nums.size(); ++i){
            result += to_string(nums[i]);
        }
        
        if(result==""){
            return "0";
        }
        
        return result;
    }
};