#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b);

int main(){

    long long a, b;
    cin>>a>>b;
    cout<<(a*b)/gcd(a, b)<<endl;
    return 0;

}

long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}