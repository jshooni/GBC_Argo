#include <iostream>
#include <algorithm>

#define SIZE 10
using namespace std;
// 쓰는 이유 : log(n) 만에 값을 찾을 수가 있다. 
// 특정값을 알고 싶을 때,. (특정값이 어떠한 array에 있는 지 알고 싶은거야. ㅇㅇ )
// 특적 값의 위치를 알고 싶을 때.


// 일단 무조건 sort를 해야해. 
// 그리고 반 토막을 내고, 반 내고 반내고 그런식으로 Search 하는거임. 

// (그냥 탐색해도 되는데 그 방법은 O(N)이고 이분탐색은 lon(N) 임 . 훨씬 빠름. )



//이거 자체를 익혀 놓으셈. ㅇㅇ
bool binary_search_func(int arr[], int left, int right, int element){
    while( left <= right ){
        int mid = (left + right) / 2; 
        if( element < arr[mid]){
            right = mid -1; 
        }
        else if ( arr[mid] == element){
            return 1; 
        }
        else {
            left = mid +1; 
        }
    }
    return 0; 
}



int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    int arr[SIZE]= {15,35,52,20,71,82,41,100,94,68};

    sort(arr, arr+SIZE);
    
    int left = 0, right = SIZE -1;
    int find_element = 52; 

    if( binary_search_func(arr, 0, SIZE-1 , find_element)){
        cout << "FIND : " << find_element << '\n';
    }
    else {
        cout << "NOT FOUND" << '\n';
    }
    
    return 0; 
}