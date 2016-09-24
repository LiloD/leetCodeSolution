#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s);
void reverseBetween(string &s, int start, int end);
void removeAdditionSpace(string &s);

void reverseWords(string &s) {
    reverseBetween(s, 0, s.size());
    removeAdditionSpace(s);
    for(int i = 0; i < s.size();){
        char c = s[i];
        if(c != ' '){
            int j = i+1;
            
            for(;j < s.size() && s[j] != ' ';j++) ;

            reverseBetween(s, i, j);
            i = j+1;
        }else{
            i++;
        }
    }
}

void removeAdditionSpace(string &s) {
    int i = 0, j = 0;
    for(; i < s.size();){
        if((i == 0 && s[i] == ' ') || (i > 0 && s[i] == ' ' && s[i-1] == ' ') ){
            i++;   
        }else{
            s[j] = s[i];
            i++;
            j++;
        }
    }
    
    while(s[j-1] == ' '){
        j--;
    }
    
    s.resize(j);
}

void reverseBetween(string &s, int start, int end) {
    if(end-start < 2){
        return;
    }

    for(int i = 0; i != (end - start)/2; ++i){
        //swap
        char tmp = s[start + i];
        s[start + i] = s[end - i - 1];
        s[end - i - 1] = tmp;
    }
}


int main(){
    return 0;
}