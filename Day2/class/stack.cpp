#include <iostream>
#include <stack>

using namespace std; 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    stack<int> s ; 

    s.push(3) ; 
    s.push(4) ; 
    s.push(5) ; 

    //s.empty : 비어 있으면 1을 반환. 
    while (!s.empty()) { 
        int k = s.front(); 
        cout << k << '\n';
        s.pop();
    }

    return 0; 
}