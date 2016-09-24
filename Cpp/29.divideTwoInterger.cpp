#include <iostream>
#include <string>
#include <map>

using namespace std;

int divide(int dividend, int divisor) {
    //edge case
    if(dividend == 0) return 0;
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }
    if(divisor == 1){
        return dividend;
    }

    int sign = 1;
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
        sign = -1;
    }

    long ldividend = (long)dividend;
    long ldivisor = (long)divisor;

    ldividend = ldividend < 0 ? -ldividend : ldividend;
    ldivisor = ldivisor < 0 ? -ldivisor : ldivisor;
    
    //assume dividend and divisor are all +
    map<long, long> m;
    long sum = ldivisor;
    long count = 1;
    long res = 0;
    
    while(ldividend >= sum){
        if(m.find(sum) == m.end())
            m[sum] = count;
        
        //try double 
        if(ldividend - sum < sum)
            break;

        sum += sum;
        count += count;
    }
    
    long remain = ldividend;

    for(auto i = m.rbegin(); i != m.rend(); ){
        if(remain - i->first < 0){
            i++;
        }else{
            remain -= i->first;
            res += i->second;
        }
    }

    return sign > 0 ? res : -res;
}

int main(){
    cout<<divide(-255, 5)<<endl;
    cout<<divide(-2147483648, 2)<<endl;
    return 0;
}   