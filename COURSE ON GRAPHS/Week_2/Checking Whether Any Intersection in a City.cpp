/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'

#define rep(i,a,b)	for(i=a;i<b;i++)
#define repr(i,a,b)	for(i=a;i>b;i--)
#define elif		else if
#define mset(a,b)	memset(a,b,sizeof(a))

#define pb		push_back
#define pob		pop_back
#define itr		iterator
#define sz()	size()
#define szof    sizeof
#define lb		lower_bound
#define ub		upper_bound
#define mp		make_pair
#define pii		pair<int,int>
#define pll		pair<li,li>
#define vpi		vector<pii >
#define vpl		vector<pll >
#define F		first
#define S		second

#define mod		1000000007
using namespace std;

vector<lli>V[10001];
vector<lli>V1[10001];
bool visited[10001];
bool visited1[10001];
lli preorder[10001];
lli postorder[10001];
lli cnt=0;
lli Time=0;

void dfs1(lli x)
{
    visited1[x]=1;
    preorder[x]=++Time;

    lli i;
    rep(i,0,V1[x].sz())
    {
        if(!visited1[V1[x][i]])
        {
            dfs1(V1[x][i]);
        }
    }

    postorder[x]=++Time;
}

void dfs(lli x)
{
    visited[x]=1;
    postorder[x]=0;

    lli i;
    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            dfs(V[x][i]);
        }
    }
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a)%mod;
        }

        b=b>>1;
        a=(a*a)%mod;
    }

 return result;
}

int main()
{
    opt;

    lli N,M,i;
    cin>>N>>M;

    while(M--)
    {
        lli x,y;
        cin>>x>>y;

        V[x].pb(y);
        V1[y].pb(x);
    }

    rep(i,1,N+1)
    {
        if(!visited1[i])
        {
            dfs1(i);
        }
    }

    while(1)
    {
        lli Max=0;
        I flag=0;

        rep(i,1,N+1)
        {
            if(postorder[i]>postorder[Max] && !visited[i])
            {
                flag=1;
                Max=i;
            }
        }

        if(flag)
        {
            dfs(Max);
            cnt++;
        }
        else
        {
            cout<<cnt;
            exit(0);
        }
    }




 return 0;
}
