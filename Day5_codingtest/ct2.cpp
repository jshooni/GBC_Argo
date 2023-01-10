#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios:: sync_with_stdio(false); cin.tie(0);

    int N; 
    scanf("%d",&N);
    
    vector< pair<int, int> >  V(N);

    
    for(int i=0; i<N; i++){

        scanf("%d",&V[i].first);
        scanf("%d",&V[i].second);
    }
    
    // for(int i=0; i<N; i++){
    //     cout << "x : " << V[i].first << " \ty : " << V[i].second << endl; 
    // }
    
    sort(V.begin(),V.end());

    // cout << "응애 "<< endl    ;
    for(int i=0; i<N; i++){
        printf("%d ",V[i].first);
        printf("%d\n",V[i].second);

    }

    
    return 0 ;
}