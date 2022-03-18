/*
锯齿数独
3 * 3 的锯齿数独
字符 * 表示空, 字符 1 2 3 表示数字
三行表示三个宫的坐标, 每一行属于同一个宫
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 4;

int cnt;
char g[N][N];
char backup[N][N];  // 备份唯一解
int d[N][N];        // d[i][j] 表示坐标(i,j)属于哪个宫

bool check(int x, int y, int c)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(d[i][j] == d[x][y] && g[i][j] == '0' + c) return false; 
            if((i == x || j == y) && g[i][j] == '0' + c) return false;
        }
    
    return true;
}

void dfs(int k)
{
    if(cnt > 1) return;
    if(k >= 9)
    {
        cnt++;
        memcpy(backup, g, sizeof g);
        return;
    }
    
    int i = k / 3, j = k - 3 * i;

    if(g[i][j] != '*') dfs(k + 1);

    for(int c = 1; c <= 3; c++)
    {
        if(check(i, j, c))
        {
            g[i][j] = '0' + c;
            dfs(k + 1);
            g[i][j] = '*';
        }
    }
    return;
} 

int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        cnt = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> g[i][j];
        
        int x, y;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                cin >> x >> y;
                d[x][y] = i;
            }
            
        
        dfs(0);
        
        if(cnt == 1) 
        {
            cout << "Unique" << endl;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++) cout << backup[i][j];
                cout << endl;
            }
        }
        else if(cnt > 1) cout << "Multiple" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}