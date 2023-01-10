#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios:: sync_with_stdio(false); cin.tie(0);
    int K; 
    cin >> K; 

    stack<int> s; 
    
    for(int i=0; i<K; i++){
        int a; 
        cin >> a; 
        if(s.empty() && a==0) s.push(a);
        else if(!s.empty() && a==0) s.pop(); 
        else s.push(a);
    }

    int sum =0; 
    while(1){
        if(s.empty()) break; 
        sum += s.top(); 
        s.pop();
    }

    cout << sum ; 
    return 0; 
}