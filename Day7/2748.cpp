#include <iostream>
using namespace std;
typedef long long ll; 

long long fiboData[100];

ll fibo(ll n){
    fiboData[0] = 0;
    fiboData[1] = 1;

    for(int i=2; i<=n; i++)
        fiboData[i] = fiboData[i-1] + fiboData[i-2];

    return fiboData[n];
}

int main(void){
    
    // 0 1 1 2 3 5 8 13 ```
    
    ll N; 
    cin >> N;
    cout << fibo(N) << endl;

    
    return 0; 
}   