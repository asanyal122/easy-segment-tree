#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX 100001
lli a[MAX],d[MAX];
pair<lli,pair<lli,lli>> tree[4*MAX],lazy;
void build(int idx,int l,int r)
{
	if(l>r)
	{
		return;
	}
	
	if(l==r)
	{
		tree[idx].first=a[l];
		tree[idx].second.first=a[l];
		tree[idx].second.second=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(idx*2+1,l,mid);
	build(idx*2+2,mid+1,r);
	tree[idx].first=tree[2*idx+1].first+tree[2*idx+2].first;
	tree[idx].seecond.first=min(tree[2*idx+1].second.first+tree[2*idx+2].second.first);
	tree[idx].second.second=max(tree[2*idx+1].second.second+tree[2*idx+2].second.second);
}

int query(int idx,int l,int r,int ql,int qr,int val)
{
	if(l>r || l>qr || r<ql)
	{
		return 0;
	}
	
	if(ql<=l && r<=qr)
	{
		if(val<tree[idx].second.first)
		{
			lazy[idx]=-(r-l+1)*val;
			return (r-l+1)*val;
		}
		else if(val>tree[idx].second.second)
		{
			lli sum=tree[idx]
			return tree[idx].first;
		}
		
	}
	
	
}



int main(void)
{
	lli n;
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(i=0;i<n;i++)
	{
		cin>>d[i];
	}
	
	
	return 0;
}
