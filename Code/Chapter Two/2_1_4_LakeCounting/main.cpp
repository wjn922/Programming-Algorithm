#include <iostream>

using namespace std;
char maze[101][101];
int n, m;
int xx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int yy[8] = {0, -1, 0, 1, 1, 1, -1, -1};
void dfs(int x, int y);
int main()
{
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> maze[i][j];
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(maze[i][j] == 'w'){
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
void dfs(int x, int y){
	maze[x][y] = '.';
	for(int i = 0;i < 8;i++){
		int tx = x + xx[i];
		int ty = y + yy[i];
		if( (tx>=0&&tx<n) && (ty>=0&&ty<m) && (maze[tx][ty] == 'w')){
			dfs(tx, ty);
		}
	}
}
