public class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0){
            return 0;
        }
        
        int [] res = new int[s.length() + 1];
        res[0] = 1;
        res[1] = Zero(s.charAt(0)) ? 0 : 1;
        for(int i = 2; i < s.length() + 1; ++i){
            char d = s.charAt(i - 1);
            if(!Zero(d)){
                res[i] = res[i - 1];
            }
            int ss = (s.charAt(i - 2) - '0') * 10 + d - '0';
            if(ss < 27 && ss >= 10){
                res[i] += res[i - 2];
            }
        }
        return res[s.length()];
    }
    boolean Zero(char s){
        return s == '0';
    }
}