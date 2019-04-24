#include <iostream>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int INF = 100000;
const int MAXN = 105;
char maze[MAXN][MAXN];
int N, M;
int sx, sy, gx, gy;
int d[MAXN][MAXN] = {INF};	//到各个位置的最短距离 
int vis[MAXN][MAXN] = {0};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct node
{
	int x, y;
	node(int a, int b){
		x = a;
		y = b;
	}
};

void bfs()
{
	queue<node> q;
	q.push(node(sx, sy));
	d[sx][sy] = 0;
	vis[sx][sy] = 0;
	
	//不断循环至队列为0
	while(!q.empty()) 
	{
		//取出队列最前的节点 
		node point = q.front();
		q.pop();
		
		if(point.x == gx && point.y == gy)
			break;
		
		//进行四个方向搜索
		for(int i = 0; i <4; i++) 
		{
			int tx = point.x + dx[i];
			int ty = point.y + dy[i];
			if((tx>=0&&tx<N) && (ty>=0&&ty<M) && maze[tx][ty]!='#' && !vis[tx][ty])
			{
				q.push(node(tx,ty));
				d[tx][ty] = d[point.x][point.y] + 1;
				vis[tx][ty] = 1;
			}	
		}
	}
	
	
}

int main(int argc, char** argv) {
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j< M; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			if(maze[i][j] == 'G')
			{
				gx = i;
				gy = j;
			}
		}		
	}
	
	bfs();
	cout << d[gx][gy];
	return 0;
}
