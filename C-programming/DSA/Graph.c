#include<stdio.h>
#include<stdlib.h>
int a[20][20],visited[20],n;
int q[20],front=0,rear=-1;
void bfs(int start){
    int i,v;
    visited[start]=1;
    q[++rear]=start;
    while(front<=rear){
        v=q[front++];
        printf("%d",v);
        for(i=1;i<=n;i++){
            if(a[v][i]==1 && visited[i]==0){
                visited[i]=1;
                q[++rear]=i;
            }
        }
    }
}
void dfs(int v){
    int i;
    visited[v]=1;
    printf("%d",v);
    for(i=1;i<=n;i++){
        if(a[v][i]==1&&visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    int i,j,start,ch;
    printf("enetr teh no of vertces:");
    scanf("%d",&n);
    printf("enter teh adjancecy matrix:");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n1.bfs\n2.dfs\n");
    printf("enter teh choice:");
    scanf("%d",&ch);
    printf("enter teh starting vertex:");
    scanf("%d",&start);
    for(i=1;i<=n;i++){
        visited[i]=0;
    }
    if(ch==1){
        printf("the bfs traversal:");
        bfs(start);
    }
    else if(ch==2){
        printf("the dfs traversal:");
        dfs(start);
    }
    else{
        printf("invalidc hoice:");
    }
    return 0;
}
