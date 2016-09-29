public class Solution {
    public String largestNumber(int[] nums) {
        if (nums == null || nums.length < 1){
            return "0";
        }
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = Integer.toString(nums[i]);
        }        
        Arrays.sort(strs, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return (o2 + o1).compareTo(o1 + o2); 
            }
        });
        StringBuilder sb = new StringBuilder();
        for (String i : strs){
            sb.append((i));
        }
        String result = sb.toString();
        int index = 0;
        while (index < result.length() && result.charAt(index) == '0') {
            index++;
        }
        if (index == result.length()) {
            return "0";
        }
        return result.substring(index);
    }
}
