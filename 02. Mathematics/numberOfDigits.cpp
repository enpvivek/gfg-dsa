#include <iostream>
using namespace std;
int countDigit(int n){
    int digits = 0;
    while(n>0){
        n = n/10;
        digits++;
    }
    return digits;
}

int main() {
     int n;
     cin>>n;
     cout<<countDigit(n);
    return 0;
}