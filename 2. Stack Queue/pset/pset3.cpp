//10866 번. 

#include <iostream> 
#include <string> 
#include <deque>
using namespace std; 

int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N; 
    deque<int> s; 


    for(int i=0; i<N; i++){
        string str; 
        cin >> str;

        if(str == "push_front"){ 
            int num=0; 
            cin >> num;
            s.push_front(num); 

        }
        else if(str == "push_back"){
            int num=0; 
            cin >> num;
            s.push_back(num); 
        }
        else if(str == "pop_front"){
                    if(s.empty()) cout << -1 << endl; 
                    else{
                        cout << s.front() << endl; 
                        s.pop_front();
                    }
        }
        else if(str == "pop_back"){
                    if(s.empty()) cout << -1 << endl; 
                    else{
                        cout << s.back() << endl; 
                        s.pop_back();
                    }
        }
        else if(str == "size")
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

