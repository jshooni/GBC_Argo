#include <iostream>
#include <vector>
using namespace std; 
int mv[501][501];
int max_v[501][501]; 

void func(int N, int a, int b){
    if(a > N) return;
    // cout << "a : " << a << endl; 
    
    if(a>1){
        for(int j=1; j<=b; j++){

            int curr = mv[a][j];

            if(j==1){
                max_v[a][j] = curr + max_v[a-1][j];
                // cout << max_v[a][j] << " " ;
                continue; 
            }

            if(j==b){
                max_v[a][j] = curr + max_v[a-1][j-1];
                // cout << max_v[a][j] << " " ;
                continue; 
            }
            max_v[a][j] = max(curr + max_v[a-1][j-1] , curr + max_v[a-1][j]);
            // cout << max_v[a][j] << " " ;
        }
    }
    // cout << endl; 
    func(N, ++a, ++b);
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int N; 
    cin >> N; 

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){  
            cin >> mv[i][j]; 
        }
    }
    max_v[1][1] = mv[1][1];

    func(N, 1, 1); 

    int max=0; 
    for(int i=1; i<=N; i++){
        // cout << i << " 번째 : " << max_v[N][i] << endl;
        if(max < max_v[N][i]) max = max_v[N][i];  
    }
    cout << max; 

    return 0;
}