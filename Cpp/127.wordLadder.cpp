#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList);
int bfs(string beginWord, string endWord, unordered_set<string>& wordList);

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    if(beginWord.size() == 0 || endWord.size() == 0 || beginWord == endWord || beginWord.size() != endWord.size()){
        return 0;
    }

    int s = beginWord.size();

    for(auto w : wordList){
        if(w.size() != s){
            return 0;
        }
    }

    int res = bfs(beginWord, endWord, wordList);

    return res;
}

int bfs(string beginWord, string endWord, unordered_set<string>& wordList){
    unordered_set<string> marked;
    vector<string> cur, next;
    cur.push_back(beginWord);
    int res = 1;
    marked.insert(beginWord);
    
    while(!cur.empty()){
       for(auto s : cur){
            for(int i = 0; i < s.size(); ++i){
                char c = s[i];
                for(char j = 'a'; j <= 'z'; ++j){
                    if(c == j){
                        continue;
                    }
    
                    s[i] = j;
    
                    //check
                    if(s == endWord){
                        return res+1;
                    }
    
                    if(marked.find(s) == marked.end() && wordList.find(s) != wordList.end()){
                        marked.insert(s);
                        next.push_back(s);
                    }
                }
                s[i] = c;
            }
        }
        
        if(next.empty()){
            return 0;
        }
        
        res++;
        cur.clear();
        cur.swap(next);
    }
    
    return res+1;
}

int main(){
    return 0;
}

    