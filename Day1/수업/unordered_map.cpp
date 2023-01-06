/**
 * 
 * 그리디 알고리즘 풀 때 쓰긴하마. 
 * Red-black Tree가 내부에 구현이 되어서 돌아감. 
 * */
#include <iostream>
#include <unordered_map>
using namespace std; 

int main(void) {
    
    ios:: sync_with_stdio(false);
    cin.tie(0);
    
    unordered_map<int, int> m ; // Red-black Tree

    //key - value 
    m.insert(make_pair(2,3));
    m.insert(make_pair(1,5));
    m.insert(make_pair(8,1));

    m[3] = 5;  // 일반적으로 이렇게 넣어도 무방함, key를 연동하고 싶으면 절허게 하면됨. 
    // m[key] = value; 

    //map<int> ::iterator iter;
    
    for( auto iter = m.begin() ; iter !=m.end() ; iter ++){
        cout << iter->first << ' ' << iter->second << '\n'; //first : key, second : value 
    }
    


    cout << '\n';

    return 0; 
}