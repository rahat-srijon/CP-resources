//Curious Robin Hood LightOJ 1112
#include <bits/stdc++.h>
using namespace std;
//sorry
int tree[4*100007],N[100007],n,q;
void build(int left,int right,int at)
{
	if(left==right){
		tree[at]=N[left];
		return;
	}
	int mid=(left+right)>>1;
	build(left,mid,2*at);
	build(mid+1,right,2*at+1);
	tree[at]=tree[2*at]+tree[2*at+1];
}
int query(int left,int right,int at,int i,int j)
{
	if(left>j||right<i)return 0;
	if(left>=i&&right<=j)return tree[at];
	int mid=(left+right)>>1,ret=0;
	ret+=query(left,mid,2*at,i,j);
	ret+=query(mid+1,right,2*at+1,i,j);
	return ret;
}
void update(int left,int right,int at,int upd,int pos)
{
	if(left==right&&left==pos){
		tree[at]+=upd;
		N[left]+=upd;
		return;
	}
	int mid=(left+right)>>1;
	if(pos<=mid)update(left,mid,2*at,upd,pos);
	else update(mid+1,right,2*at+1,upd,pos);
	tree[at]+=upd;
}
int main(){
	int t,tc=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&q);
		for(int k=1;k<=n;k++)scanf("%d",&N[k]);
		build(1,n,1);
		printf("Case %d:\n",++tc);
		while(q--){
			int o;
			scanf("%d",&o);
			if(o==1){
				int i;
				scanf("%d",&i);
				printf("%d\n",N[i+1]);
				update(1,n,1,-N[i+1],i+1);
			}
			if(o==2){
				int i,v;
				scanf("%d %d",&i,&v);
				update(1,n,1,v,i+1);
			}
			if(o==3){
				int i,j;
				scanf("%d %d",&i,&j);
				printf("%d\n",query(1,n,1,i+1,j+1));
			}
		}
	}
	return 0;
}
