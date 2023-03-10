#include<bits/stdc++.h>
using namespace std;
int n = 4;
int dp[16][4];
int dist[10][10] ={
{0,20,42,25},
{20,0,30,34},
{42,30,0,10},
{25,34,10,0},
};
//if all city has been visited
int VISITED_ALL = (1<<n) -1;
int tsp(int mask,int pos){

        if(mask == VISITED_ALL){
            return dist[pos][0];
        }
        //overlapping problem
        if(dp[mask][pos] != -1){
            return dp[mask][pos];
        }

        int ans = INT_MAX;
        //try to go to unvisited graph
        for(int city = 0;city < n;city++){
            if((mask&(1<<city))==0){
                int newAns = dist[pos][city] + tsp(mask|(1<<city),city);
                ans = min(ans,newAns);
            }
        }

            return dp[mask][pos] = ans;
}
int main()
{
    for(int i = 0;i < (1<<n);i++){
        for (int j = 0;j < n; j++){
                dp[i][j] = -1;
        }
    }

    cout<<"Min cost of TSP is "<<tsp(1,0)<<endl;
    return 0;
}
