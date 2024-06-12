#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char grid[N][N];
bool vis[N][N];
int n, m;

int di[] = {+1, -1 ,0 ,0 , 1, 1, -1, -1};
int dj[] = {0,0,+1,-1,+1,-1,+1,-1};

bool valid_or_not(int i, int j){
    return (i>=0 && j>=0 && i<n && j<m);
}
void dfs(int i, int j) {
    
    vis[i][j] = 1;
    for(int k=0;k<8;k++)
    {
    int ii = i+ di[k];
    int jj = j + dj[k];

    if(valid_or_not(ii,jj) &&  grid[ii][jj]=='@' && !vis[ii][jj])
    {
        dfs(ii, jj);
        }
}
   /* dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j + 1);
    dfs(i + 1, j - 1);
    dfs(i - 1, j + 1);
    dfs(i - 1, j - 1);*/
}
int main()
{
    while(cin>>n>>m && n && m){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }

        int oil_deposit = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='@'){
                    dfs(i,j);
                    oil_deposit++;
                }
            }
        }
        cout<<oil_deposit<<'\n';

    memset(vis, 0, sizeof(vis));
    }

}
