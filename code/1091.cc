#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int mat[1286][128][60];
int M, N, L;
int threshold;
struct Pos{
  int x, y, z;  
};
int mv_x[] = {-1, 1, 0, 0, 0, 0};
int mv_y[] = {0, 0, -1, 1, 0, 0};
int mv_z[] = {0, 0, 0, 0, -1, 1};
int total_volumn = 0;
queue<Pos> qu;
void bfs(int x, int y, int z)
{
    int cnt = 1;
    int i;
    
    Pos cur, tmp_pos;
    cur.x = x; cur.y = y; cur.z = z;
    mat[x][y][z] = 0;
    qu.push(cur);
    while(!qu.empty()){
        cur = qu.front();
        qu.pop();
        for(i = 0; i < 6; ++i){
            x = cur.x + mv_x[i];
            y = cur.y + mv_y[i];
            z = cur.z + mv_z[i];
            if(x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < L &&
             mat[x][y][z]){
                mat[x][y][z] = 0;
                tmp_pos.x = x; tmp_pos.y = y; tmp_pos.z = z;
                cnt++;
                qu.push(tmp_pos);
            }
        }
    }
    if(cnt >= threshold)
        total_volumn += cnt;
}
int main()
{
    int i, j, k;
    
    //freopen("1091.txt", "r", stdin);
    //freopen("1091.out.txt", "w", stdout);
    scanf("%d%d%d%d", &M, &N, &L, &threshold);
    
    for(i = 0; i < L; ++i)
        for(j = 0; j < M; ++j)
            for(k = 0; k < N; ++k)
                scanf("%d", &mat[j][k][i]);
                
    for(i = 0; i < L; ++i)
        for(j = 0; j < M; ++j)
            for(k = 0; k < N; ++k)
                if(mat[j][k][i])
                    bfs(j, k, i);
    printf("%d", total_volumn);
    return 0;
}