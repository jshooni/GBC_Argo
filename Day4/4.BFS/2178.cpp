//미로찾기. 

/*
4 6
101111
101010
101011
111011
*/
#include <iostream> 
#include <vector> 
#include <queue> 
#define SIZE 101 
using namespace std ; 

int dx[4] = {-1, 0, 1, 0} ; 
int dy[4] = { 0, 1, 0,-1} ; 
int MAP[SIZE][SIZE] ; // visit느낌으로 역할을 함. 
int value[SIZE][SIZE] ; //row , column.
int R, C ; 

void BFS() { 
    queue<pair<int, int> > Q ; 
    Q.push({0, 0}); 
    value[0][0] = 1 ; 

    while (!Q.empty()) { 
        // Current 
        pair<int, int> curr = Q.front() ; 
        int curr_x = curr.first ; 
        int curr_y = curr.second ; 
        Q.pop() ; 
        
        // Finish 
        if ( curr_y == R - 1 && curr_x == C - 1) { 
            cout << value[R - 1][C - 1] << '\n'; 
            break ;
        } 

        // 주변 탐색, 동서남북 4방향
        for (int k = 0 ; k < 4 ; k++) { 
            int nx = curr_x + dx[k] ; 
            int ny = curr_y + dy[k] ; 

            // 바깥으로 안나가게 하기 위해
            if ( nx < 0 || nx >= C || ny < 0 || ny >= R ) continue ; 
            // MAP에서 값 1인 것만 이동할 수 있도록, 
            if ( MAP[ny][nx] == 0 || value[ny][nx] != 0 ) continue ; 
            // 다음 위치 값 = 현재 위치 값 + 1
            value[ny][nx] = value[curr_y][curr_x] + 1 ; 
            Q.push({nx, ny}) ; 
        }
    }
}
int main(void) { 
    cin >> R >> C ; 

    for (int i = 0 ; i < R ; i++) { 
        for (int j = 0 ; j < C ; j++) { 
            scanf("%1d", &MAP[i][j]) ; 
        }
    }

    BFS() ; 

    return 0 ;
}

