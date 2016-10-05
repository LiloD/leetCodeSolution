public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> ss = new HashMap<Character, Integer>();
        int length = 0;
        int end = 0;
        if (s == null || s.length() < 1){
            return 0;
        }
        for (int i = 1; i < s.length() + 1; ++i){
            char cur = s.charAt(i - 1);
            if (ss.containsKey(cur)){
                int pp = ss.get(cur);
                end = Math.max(end, pp);
            }
            else{
                end = Math.max(0, end);
            }
            length = Math.max(length, i - end);
            ss.put(cur, i);
        }
        return length;
    }
}
