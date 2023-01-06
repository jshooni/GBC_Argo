#include <iostream>
#include <vector> 
// 동적으로 배열을 다룰 수 있는 것 : vector 

using namespace std;

int main() {
    cout << "Hello fucking Happy new Year" << endl; 

    ios:: sync_with_stdio(false);
    cin.tie(0);

    vector<int> V; // 벡터 선언 
    
    cout << "SIZE: " << V.size() << '\n'; // size : 0
    V.push_back(1);
    V.push_back(2);
    V.push_back(0);

    for(int i=0; i<V.size(); i++){
        cout << V[i] << ' '; 
    }
    cout << '\n'; 

    V.pop_back(); // 0 제거하는거임 

    vector<int> ::iterator iter; // 주소값을 가리키는 . 
    
    for(iter = V.begin() ; iter != V.end() ; iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';

    
    
    return 0; 
}