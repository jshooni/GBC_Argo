#include <iostream>
#include <queue> 
#include <vector>
#include <algorithm>
using namespace std; 

int N;

int MAX;
int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
// N개의 카드 묶음.
// 몇번의 비교가 필요한지 짜면됨.  


    cin >> N; 
    priority_queue<int> pq; 

    for(int i=0; i<N; i++){
        int k; 
        cin >> k; 
        pq.push(-k); 
    }
    
    while(!pq.empty() || pq.size()>2){
        
        int a =pq.top();
        // cout << " a : " << a <<endl; 
        pq.pop(); 
        if(pq.empty()) break;
        int b = pq.top();
        // cout << " b : " << b <<endl; 
        pq.pop(); 
        int temp_max = (-a) + (-b);
        // cout << " temp_max : " << temp_max <<endl; 
        MAX += temp_max; 
        pq.push(-temp_max);
        // cout << " MAX : " << MAX<< endl; 
    }
    cout << MAX ;
    // int arr[N];

    // for(int i=0,a; i<N; i++){
    //     cin >> a; 
    //     arr[i] = a; 
    // }
    // int n = sizeof(arr) / sizeof(arr[0]);

    // sort(arr, arr+n); 

    // for(int i=0; i<N; i++){
    //     cout << arr[i] << ' ' ; 
    // }

    // for(int i=0; i<N-1; i++){
    //     arr[i+1] += arr[i]; 
    //     MAX+= arr[i+1];
    // }

    // cout << MAX;

    return 0; 
}