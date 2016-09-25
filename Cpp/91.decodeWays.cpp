#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s) {
    int l = s.size();
    if(l < 1) return 0;
    if(s[0] == '0') return 0;
    if(l < 2) return 1;
    
    vector<int> m(l+1, 0);
    m[0] = 1;
    m[1] = 1;

    for(int i = 2; i <= l; ++i){
        int p = i-1;
        char c = s[p];
        char prevc = s[p-1];
        bool flag1 = true;
        bool flag2 = true;
        
        //try 1
        if(c != '0'){
            m[i] += m[i-1];  
        }else{
            flag1 = false;
        }

        //try 2
        if((prevc == '1')||(prevc == '2' && c >= 0 && c <= '6')) {
            m[i] += m[i-2];
        }else{
            flag2 = false;
        }

        if(!flag1 && !flag2){
            m[i] = 0;
            break;
        }
    }
    return m[l];
}

int main() {

    cout<<numDecodings("12")<<endl;
    cout<<numDecodings("10")<<endl;
    cout<<numDecodings("31")<<endl;
    cout<<numDecodings("233")<<endl;
    cout<<numDecodings("203")<<endl;
    cout<<numDecodings("200")<<endl;
    cout<<numDecodings("010")<<endl;
    cout<<numDecodings("223")<<endl;
    return 0;
}