#include<stdio.h>
#include<queue>

using namespace std;
#define MAXN 20
#define INF 0x3f3f3f3

int n=3,W=30;
int w[]= {0,16,15,15};
int v[]= {0,45,25,25};

int maxv=-9999;
int bestx[MAXN];
int total=1;
struct NodeType {
	int no;
	int i;
	int w;
	int v;
	int x[MAXN];
	double ub;
	bool operator<(const NodeType &s)const {
		return ub<s.ub;
	}
};

void bound(NodeType &e) {
	int i=e.i+1;
	int sumw=e.w;
	double sumv=e.v;
	while((sumw+w[i]<=W)&&i<=n) {
		sumw+=w[i];
		sumv+=v[i];
		i++;
	}
	if(i<=n) {
		e.ub=sumv+(W-sumv)*v[i]/w[i];
	} else {
		e.ub=sumv;
	}
}

void EnQueue(NodeType e,priority_queue<NodeType> &qu) {
	if(e.i==n) {
		if(e.v>maxv) {
			maxv=e.v;
			for(int j=1; j<=n; j++)
				bestx[j]=e.x[j];
		}
	} else
		qu.push(e);
}

void bfs() {
	int j;
	NodeType e,e1,e2;
	priority_queue<NodeType> qu;
	e.i=0;
	e.w=0;
	e.v=0;
	e.no=total++;
	for(j=1; j<=n; j++)
		e.x[j]=0;
	bound(e);
	qu.push(e);
	while(!qu.empty()) {
		e=qu.top();
		qu.pop();
		if(e.w+w[e,i+1]<=W) {
			e1.no=total++;
			e1.i=e.i+1;
			e1.w=e.w+w[e1.i];
			e1.v=e.v+v[e1,i];
			for(j=1; j<=n; j++) {
				e1.x[j]=e.x[j];
			}
			e1.x[e1,i]=1;
			bound(e1);
			EnQueue(e1,qu);
		}
		e2.no=total++;
		e2.i=e.i+1;
		e2.w=e.w;
		e2.v=e.v;
		for(j=1; j<=n; j++) {
			e2.x[j]=e.x[j];
		}
		e2.x[e2.i]=0;
		bound(e2);
		if(e2.ub>maxv)
			EnQueue(e2,qu);
	}

}

int main() {
	bfs();
	for(int i=1; i<=n; i++) {
		printf("%2d",bestx[i]);
	}
}
