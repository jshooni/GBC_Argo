#include <iostream> 
#include <algorithm> 
#include <vector>
#define SIZE 10 // 10이라는게 굉장히 많이 나오면 이렇게 define 해주면 좋음 . (나중에 혹시 바뀌면 이것만 바꾸면되니까)
using namespace std; 


int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    int arr[SIZE] = {1, 3, 5, 2, 7, 8, 4, 10, 9, 6};
    vector<int> V;

    cout << "10개의 숫자를 입력해주세요. "<< endl; 
    for(int i=0, k; i<SIZE; i++){ // int i=0; int k; 선언한거임.
        cin >> k; 
        V.push_back(k);
    }

    sort( arr, arr+ SIZE ); // sort 내부 quik sort가 구현되어잇을거임. // 어디서부터 어디까지 sort할 것인지. 
    //sort( a, b, greater<int>() ) --> 내림차순 하려면 저거 넣어주면 됨. 
    //sort ( a, b ) --> 오름 차순. 

    sort(V.begin(), V.end());

    for(int i=0; i<SIZE ; i++) cout << arr[i] << ' ';
    cout << endl; 

    for(int i=0; i<V.size(); i++) cout << V[i] << ' ';
    cout << '\n';
    
    return 0; 
}