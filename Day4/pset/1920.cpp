#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

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

int main(void) {
    
    ios:: sync_with_stdio(false); cin.tie(0);
    
    int N; 
    int M; 

    cin >> N; 
    int N_num[N];
    for(int i=0; i<N; i++){
        cin >> N_num[i];
    }

    cin >> M; 
    int M_num[M];
    for(int i=0; i<M; i++){
        cin >> M_num[i]; 
    }

    // N_num[] 안에 M_num 들이 존재하는지 각각 0/1 로 출력하면됩니다. 

    sort(N_num, N_num+N);

    for(int i=0; i<M; i++){
        if(binary_search_func(N_num, 0, N-1, M_num[i]) == 0 ) printf("0\n");
        else printf("1\n");
    }



    return 0; 
}

