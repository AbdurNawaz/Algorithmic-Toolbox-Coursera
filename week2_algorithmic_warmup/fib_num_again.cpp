#include<bits/stdc++.h>

using namespace std;

int fib_num_again(long long n, long long m);
long long get_pisano_period_length(long long m);

int main(){

    long long n, m;
    cin>>n>>m;
    cout<<fib_num_again(n, m)<<endl;
    return 0;
}

long long get_pisano_period_length(long long m){
    long long F1 = 0, F2 = 1, F = F1 + F2;
    for (int i = 0; i < m * m; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1) return i + 1;
    }
}

int fib_num_again(long long n, long long m){
    long long remainder = n % get_pisano_period_length(m);
    int F1 = 0, F2 = 1, F = remainder; 

    for(int i=1;i<remainder;i++){
        F = (F1 + F2)%m;
        F1 = F2;
        F2 = F;
    }

    return F%m;

}