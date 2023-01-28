// 플로이드 
//Floyd-Warshall

#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;
typedef long long ll; 

ll DIST[101][101];  
int N, M; 

void intialize(void){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            DIST[i][j] = INF;  
        }
        DIST[i][i] = 0; 
    }
}

void Floyd_Warshall(void){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                DIST[i][j] = min(DIST[i][j], DIST[i][k]+DIST[k][j]);
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> N >> M ;

    intialize(); 

    for(int i=1; i<=M; i++){
        int a, b; 
        ll c; 
        cin >> a >> b >> c;

        DIST[a][b]= min(DIST[a][b], c);
    }

    Floyd_Warshall(); 
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(DIST[i][j]>=INF) cout << 0 << ' '; 
            else cout << DIST[i][j] << ' ' ;
        }
        cout << '\n';
    }   

    return 0; 
}