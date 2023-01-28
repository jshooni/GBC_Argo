#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// "연속된 수" 를 선택해서 구할 수 있는 가장 큰 합이다. 
int N, MAX;
int arr[100001];

void func(int k){
    if(k >= N) return ;

    for(int i=0; i<N; i++){
        int temp=0; 
        for(int j=i; j<k; j++){
            temp += arr[j];
        }
        MAX = max(MAX,temp);
    }

    func(++k);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N; 
    // vector가 좋을 지.. 흠. .

    for(int i=0; i<N; i++){
        cin >> arr[i]; 
    }
    
    func(1);
    cout << MAX; 


    // for(int i=0 ; i<N ;i++){
    //     int x = Q.top();
    //     Q.pop(); 
    //     int y = Q.top();
    //     MAX = max(MAX, x+y);
    // }

    // MAX = max(MAX, Q.top());

    // cout << MAX ;
    




    return 0; 
}