#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> tree[MAX];

string s;

void build(int idx,int l,int r)
{
    if(l>r)
    {
        return;
    }

    if(l==r)
    {
        vector<int> v(26);
        tree[idx]=v;
        tree[l][s[l]-'a']=1;
    }

    int mid=(l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);

    for(int i=0;i<26;i++)
    {
        tree[idx][i]=tree[2*idx][i]+tree[2*idx+1][i];
    }
    return;
}

int query(int idx,int l,int r,int ql,int qr,char ch)
{
    if(ql>r || qr<l)
    {
        return 0;
    }

    if(ql<=l && r<=qr)
    {
        return tree[idx][ch-'a'];
    }

    int mid=(l+r)/2;

    return query(idx*2,l,mid,ql,qr,ch)+query(idx*2+1,mid+1,r,ql,qr,ch);
}


int main(void)
{
    
    cin>>s;
    build(1,0,s.length()-1);
    int l,r;
    char ch;
    while(true)
    {
        cin>>l>>r>>ch;
        cout<<query(1,0,s.length()-1,l,r,ch);
    }

    return 0;
}