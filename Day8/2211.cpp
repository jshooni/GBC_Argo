// 네트워크 복구

#include <iostream> 
#include <vector>
#include <climits>

#define INF INT_MAX

vector< pair<int,int> > graph[1001];
int DIST[1001];
int M, N;
using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 

    for(int i=0, a,b,c; i<M; i++){
        cin >> a >> b >> c; 
        graph[a].push_back( {b,c} );
        graph[b].push_back( {a,c} );
    }


    return 0; 
}