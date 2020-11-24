#include
#define min(x,y) x>y?y:x
int maze[9][9]={1,1,1,1,1,1,1,1,1,
  1,0,0,1,0,0,1,0,1,
  1,0,0,1,1,0,0,0,1,
  1,0,1,0,1,1,0,1,1,
  1,0,0,0,0,1,0,0,1,
  1,1,0,1,0,1,0,0,1,
  1,1,0,1,0,1,0,0,1,
   1,1,0,1,0,0,0,0,1,
   1,1,1,1,1,1,1,1,1};
int a,b,c,d,m;
void dfs(int x,int y,int s){
   if(maze[x][y]) return;
   if(x==c&&y==d){
       m=min(s,m);（找出最短的步数）
       return;
   }
   s++;
   maze[x][y]=1; （对可以走的路径进行标记）
   dfs(x+1,y,s);
   dfs(x,y+1,s);
   dfs(x-1,y,s);
   dfs(x,y-1,s);
   maze[x][y]=0; （每搜索一次后恢复原状）
}
 
int main(){
   int n;
   scanf("%d",&n);
   while(n--){
       m=9999;
       scanf("%d%d%d%d",&a,&b,&c,&d);
       dfs(a,b,0);
       printf("%d\n",m);
   }
   return 0;
}
