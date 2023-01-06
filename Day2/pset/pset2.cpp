/*

*/

#include <iostream> 
#include <string> 
#include <queue>
using namespace std; 

int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);

    int N; 
    cin >> N; 
    queue<int> s; 
    cin.ignore();

    for(int i=0; i<N; i++){
        string str; 
        getline(cin, str);
        string menu = str.substr(0,4);

        if(menu == "push"){
            int num = stoi(str.substr(5));
            s.push(num); 
        }
        else if(menu == "pop"){
                    if(s.empty()) cout << -1 << endl; 
                    else{
                        cout << s.front() << endl; 
                        s.pop();
                    }
        }
        else if(menu == "size")
            cout << s.size() << endl ; 

        else if(str == "empty"){

            if(s.empty()) cout << 1 << endl; 
            else cout << 0 << endl; 
        }
        else if(str == "front"){
            if(s.empty()) cout << -1 << endl; 
            else cout << s.front() << endl; 
        }
        else if(str == "back"){
            if(s.empty()) cout << -1 << endl; 
            else cout << s.back() << endl; 
        }
    }
    
    
    return 0; 
}