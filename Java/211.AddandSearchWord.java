public class WordDictionary {

    TierTree root = new TierTree();

    // Adds a word into the data structure.
    public void addWord(String word) {
        TierTree current = root;
        for (Character s : word.toCharArray()){
            if (current.nodes.containsKey(s)){
                current = current.nodes.get(s);
            }
            else{
                TierTree tmp = new TierTree();
                tmp.context = s;
                current.nodes.put(s, tmp);
                current = current.nodes.get(s);
            }
        }
        current.isLeaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        Queue<TierTree> preSet = new LinkedList<TierTree>();
        preSet.add(root);
        for(Character s : word.toCharArray()){
            Queue<TierTree> postSet = new LinkedList<TierTree>();
            for(TierTree d : preSet){
                if (s == '.'){
                    postSet.addAll(d.nodes.values());
                }
                else{
                    if (d.nodes.containsKey(s)){
                        postSet.add(d.nodes.get(s));
                    }
                }
            }
            preSet = postSet;
        }
        for ( TierTree d : preSet){
            if (d.isLeaf){
                return true;
            }
        }
        return false;
    }
    
    static class TierTree{
        public boolean isLeaf;
        public char context;
        public HashMap<Character, TierTree> nodes;
        public TierTree(){
            context = ' ';
            isLeaf = false;
            nodes = new HashMap<Character, TierTree>();
        }
    }
}



// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
