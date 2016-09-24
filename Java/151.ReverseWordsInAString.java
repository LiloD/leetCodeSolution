public class Solution {
  boolean isSpace(char c){
  	return c == ' ' || c == '\t';
  }
  
  char[] emitSpace(char [] imp){
    
    int tail = 0;
    boolean emit = false;
    for (int i = 0; i < imp.length; ++i){
      if(!isSpace(imp[i])){
        imp[tail] = imp[i];
        tail ++;
        emit = false;
      }
      else {
        if (!emit){
          imp[tail] = ' ';
          tail ++;
          emit = true;
        }
      } 
    }
    return Arrays.copyOf(imp, tail);
  }
    public String reverseWords(String s) {
        s = s.trim();
        if (s == null || s.length() < 2){
            return s;
        }
        char [] reversed = new StringBuilder(s).reverse().toString().toCharArray();
		reversed = emitSpace(reversed);
        int start = 0;
        boolean processed = false;
        int end = 0;
        for( int i = 0; i < reversed.length; ++i){
            
            if(!isSpace(reversed[i])){
                if(processed){
                    end = i;
                }
                else{
                    processed = true;
                    start = i;
                    end = i;
                }
            }
            else{
              processed = false;
              reverse(reversed, start, end);
            }
        }
      reverse(reversed, start, end);
        return new String(reversed);
    }
    
    void reverse(char [] array, int start, int end){
        for(int j = start; j <= (start + end)/ 2; ++j){
        char t = array[j];

        array[j] = array[end + start - j];
        array[end + start - j] = t;
      }
    }
}