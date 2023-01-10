#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define SIZE 501
int R, C ; 
int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, 1, 0,-1} ; 
int MAP[SIZE][SIZE] ; 
int visited_bfs[SIZE][SIZE] ;
int PIC_NUM ; 

int BFS(int a, int b ) { 
    queue<pair<int, int> > Q ; 
    Q.push({b, a});  // (0,0) 부터 시작. 

    visited_bfs[a][b] = 1 ;// (0, 0) 방문 했다~ 


    // cout << " a: " << a << "    b: " << b << endl; 
    int f_max_sum=1; 
    while (!Q.empty()) { 
        // Current
        pair<int, int> curr = Q.front() ; 
        int curr_x = curr.first ; 
        int curr_y = curr.second ; 
        Q.pop() ;

        
        // Finish 

        // 주변 탐색, 동서남북 4방향
        for (int k = 0 ; k < 4 ; k++) { 
            int nx = curr_x + dx[k] ; 
            int ny = curr_y + dy[k] ; 
            // 바깥으로 안나가게 하기 위해
            if ( nx < 0 || nx >= C || ny < 0 || ny >= R ) continue ; 
            // MAP에서 값 1인 것만 이동할 수 있도록, 
            if ( MAP[ny][nx] == 0 || visited_bfs[ny][nx]==1 ) continue ; 
            // // 다음 위치 값 = 현재 위치 값 + 1
            // value[ny][nx] = value[curr_y][curr_x] + 1 ; 
            // Q.push({nx, ny}) ; // !!! 여기서 push 합니다 !!! 
            if (visited_bfs[ny][nx]!= 1 && MAP[ny][nx]==1) {
                visited_bfs[ny][nx] = 1 ;
                Q.push({nx, ny});
                f_max_sum++;
            }   
        }
    }

    PIC_NUM++;
    return f_max_sum;
}

int main(void){
    ios:: sync_with_stdio(false); cin.tie(0);

    cin >> R >> C ; 
    for (int i = 0 ; i < R ; i++) { 
        for (int j = 0 ; j < C ; j++) { 
            scanf("%d", &MAP[i][j]) ; 
        }
    }
    
    int sum =0; 
    int max_sum =0; 

    for (int i = 0 ; i < R ; i++) { 
        for (int j = 0 ; j < C ; j++) {
            if(MAP[i][j]==1 && visited_bfs[i][j] != 1)
                sum = BFS(i,j); 
                if(sum >= max_sum ) max_sum = sum; 
        }
    }
 

    cout << PIC_NUM << '\n' << max_sum << '\n'; 

    return 0;
}