#Stack Queue

##Stack
    #include <iostream>
    #include <stack>

    using namespace std; 

    int main(void) {
        ios::sync_with_stdio(false); cin.tie(0);

        stack<int> s ; 

        s.push(3) ; 
        s.push(4) ; 
        s.push(5) ; 

        //s.empty : 비어 있으면 1을 출력. 
        while (!s.empty()) { 
            int k = s.top(); 
            cout << k << '\n';
            s.pop(); 
        }

        return 0; 
    }

stack : Vname.top(); 
queue : Vname.front(); 