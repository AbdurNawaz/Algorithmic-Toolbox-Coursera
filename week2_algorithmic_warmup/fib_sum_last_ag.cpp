#include<bits/stdc++.h>

using namespace std;

long long huge_fib_again(long long m, long long n);
long long pisano_period(long long m, long long n);
int solve(long long n, long long m);

int main(){

    long long n, m;
    cin>>m>>n;
    cout<<huge_fib_again(m, n)<<endl;
    return 0;
}


long long pisano_period(long long m){

    long long a = 0, b = 1, c = a+b;
    for(int i=0;i<m*m;i++){
        c = (a+b)%m;
        a = b;
        b = c;
        if(a==0 && b==1) return i+1;
    }

}


int solve(long long n, long long m){
    long long remainder = n%pisano_period(m);
    long long f1=0, f2=1, f = remainder;

    for(int i=1;i<remainder;i++){
        f = (f1+f2)%m;
        f1 = f2;
        f2 = f;
    }
    return f%m;
}


long long huge_fib_again(long long m, long long n){

    int last_dig_np2 = solve(n+2, 10);
    int last_dig_mp1 = solve(m+1, 10);

    if(last_dig_np2>=last_dig_mp1)
        return (last_dig_np2 - last_dig_mp1);

    else
        return(10+last_dig_np2 - last_dig_mp1);

}