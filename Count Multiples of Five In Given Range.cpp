/*Count Multiples of Five*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100001

int tree[4*MAX],a[MAX];

void build(int idx,int l,int r)
{
    if(l==r)
    {
        if(a[l]%5==0)
        {
            tree[idx]=1;
        }
        else
        {
            tree[idx]=0;
        }
        return;
    }

    int mid=(l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
    return;

}


int query(int idx,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql)
    {
        return 0;
    }

    if(ql<=l && r<=qr)
    {
        return tree[idx];
    }

    int mid=(l+r)/2;
    return query(2*idx+l,mid,ql,qr)+query(2*idx+1,mid+1,r,ql,qr);
}


int main(void)
{
    int t,q,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;

        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }

        build(1,0,n-1);

        int l,r;
        while(q--)
        {
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<" ";
        }
        cout<<endl;
    }
    return 0;
}