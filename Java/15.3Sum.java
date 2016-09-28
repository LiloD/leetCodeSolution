
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (nums == null || nums.length < 2){
            return res;
        }
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i ++){
            if (i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int start = i + 1;
            int end = nums.length - 1;

            while( start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if ((sum) == 0){
                    List<Integer> tmp = new ArrayList<Integer>();
                    tmp.add(nums[i]);
                    tmp.add(nums[start]);
                    tmp.add(nums[end]);
                    res.add(tmp);
                    start ++;
                    end --;
                    //jump away from dumplicate nums
                    while( start < end  && nums[start] == nums[start - 1]){
                        start++;
                    }
                    while(end > start && nums[end] == nums[end + 1]){
                        end --;
                    }
                }                
                else if (sum > 0){
                    end --;
                }else{
                    start++;
                }
            }
        }
        return res;
    }
}
