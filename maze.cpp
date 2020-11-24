maze.cpp
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int c, step, ex, ey;
int x, y;
int vis[9][9];
int map[9][9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1,
                  1, 0, 0, 1, 0, 0, 1, 0, 1,
                  1, 0, 0, 1, 1, 0, 0, 0, 1,
                  1, 0, 1, 0, 1, 1, 0, 1, 1,
                  1, 0, 0, 0, 0, 1, 0, 0, 1,
                  1, 1, 0, 1, 0, 1, 0, 0, 1,
                  1, 1, 0, 1, 0, 1, 0, 0, 1,
                  1, 1, 0, 1, 0, 0, 0, 0, 1,
                  1, 1, 1, 1, 1, 1, 1, 1, 1};
struct node
{
    int x, y, step;
};
int bfs()
{
    node s, now, next;                      //s为第一个访问的节点
    s.x = x;
    s.y = y;
    s.step = 0;

    vis[x][y] = 1;                         //对访问过的点进行标记
    queue<node>qu;
    qu.push(s);                               //第一个点入队
    while(!qu.empty())
    {
        now = qu.front();               //把正在访问的点提出来
        qu.pop();     //提出来后进行出队操作，把他相邻符合条件的点全部入队
                                                 //找到终点
        if(now.x == ex && now.y == ey)
            return now.step;

        for(int i = 0; i < 4; i++)
        {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.step = now.step;
            if(map[next.x][next.y] == 0 && vis[next.x][next.y] == 0)
            {
                vis[next.x][next.y] = 1;
                next.step += 1;
                qu.push(next);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d %d %d", &x, &y, &ex,&ey);
        printf("%d\n", bfs());
    }
    return 0;
}
--------------------- 
作者：空巷挽清风 
来源：CSDN 
原文：https://blog.csdn.net/Kong_xiang/article/details/76546544 
版权声明：本文为博主原创文章，转载请附上博文链接！