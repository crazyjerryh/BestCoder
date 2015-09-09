/*!
 * file main.cpp
 * author Rotile_H
 * date 2015/09/09
 * best coder round #1 01
 */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
#define inf 0x3f3f3f3f
#define maxn 100010

struct cmp
{
	bool operator ()(int &a,int &b){
		return a<b;
	}
};

struct edge{
	int v;
	int next;
}edges[maxn<<1];
int cnt,n,m;
int head[maxn];
int degree[maxn];

void addedge(int u,int v){
	edges[cnt].v=v,edges[cnt].next=head[u],head[u]=cnt++;
}

int main(void){
	//freopen("debug.txt","r",stdin);
	int tcase;
	priority_queue<int,vector<int>, cmp> Q;
	std::vector<int> ans;
	while(~scanf("%d",&tcase)){
		while(tcase--){
			while(!Q.empty()) Q.pop();
			ans.clear();
			memset(degree,0,sizeof(degree));
			memset(head,-1,sizeof(head));
			scanf("%d%d",&n,&m);
			cnt=0;
			for(int i=0;i<m;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				addedge(v,u);
				degree[u]++;
			}
			
		   for(int i=1;i<=n;i++){
			   if(degree[i]==0) Q.push(i);
		   }
		   
		   while(!Q.empty()){
			   int front=Q.top();
			   Q.pop();
			   ans.push_back(front);
			   for(int i=head[front];i!=-1;i=edges[i].next){
			       int v=edges[i].v;
				   --degree[v];
				   if(degree[v]==0)  Q.push(v);
			   }
		   }
		   printf("%d",ans[ans.size()-1]);
		   for(int i=ans.size()-2;i>=0;i--)
			   printf(" %d",ans[i]);
		   printf("\n");
		}
	}
	return 0;
}
