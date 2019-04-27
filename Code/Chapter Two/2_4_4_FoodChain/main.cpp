/*
 * runtime error 数组改大
 cin 改为scanf 
 * */
#include <iostream>
#include <cstdio>
#define MAX_N 500000
using namespace std;

int par[MAX_N];
int N, K;
int ans = 0;
void init(int n) {
    for (int i = 1; i <= n*3; i++) {
    par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) {
    par[px] = py;
    }
}

int main() {
    int T, X, Y;
    cin >> N >> K;
    init(3 * N);
    for (int i = 0; i < K; i++) {
    scanf("%d%d%d", &T, &X, &Y);
    if (X <= 0 || N < X || Y <= 0 || N < Y) {
        ans++;
        continue;
    }
    if (T == 1) {
        if (find(X) == find(Y + N) || find(X) == find(Y + 2 * N)) {
        ans++;
        continue;
        }
        else {
        unite(X, Y);
        unite(X + N, Y + N);
        unite(X + 2 * N, Y + 2 * N);
        }
    }
    else {
        if (find(X) == find(Y) || find(X) == find(Y + 2 * N)) {
        ans++;
        continue;
        }
        else {
        unite(X, Y + N);
        unite(X + N, Y + 2 * N);
        unite(X + 2 * N, Y);
        }
    }
    }
    cout << ans << endl;
    return 0;
}

