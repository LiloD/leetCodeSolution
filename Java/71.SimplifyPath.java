public class Solution {
    public String simplifyPath(String path) {
        Deque<String> finalPath = new LinkedList<String>();
        if (path == null || path.length() < 1){
            return "/";
        }
        String [] inp = path.split("/");
        for (String s : inp){
            if (s.length() == 0){
                continue;
            }
            if (s.equals(".")){
                continue;
            }
            if (s.equals("..")){
                finalPath.pollFirst();
                continue;
            }
            finalPath.push(s);
        }
        StringBuilder sb = new StringBuilder();
        sb.append('/');
        while(finalPath.peekLast() != null){
            sb.append(finalPath.pollLast());
            sb.append("/");
        }
        if (sb.length() > 1){
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb.toString();
    }
}
