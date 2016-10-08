public class Solution {
    public int maxProduct(int[] nums) {
        int curmax, curmin, cur;
        curmax = curmin = cur = nums[0];
        for (int i = 1; i < nums.length; ++i){
            int tmp = curmax;
            curmax = Math.max(Math.max(curmax * nums[i], curmin * nums[i]), nums[i]);
            curmin = Math.min(Math.min(tmp * nums[i], curmin * nums[i]), nums[i]);
            cur = Math.max(curmax, cur);
        }
        return cur;
    }
}
