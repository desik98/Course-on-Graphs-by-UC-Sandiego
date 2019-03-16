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

vector<lli>V[1001];
bool visited[1001];
I flag;

void dfs(lli x,lli Parent)
{
    visited[x]=1;

    lli i;
    rep(i,0,V[x].sz())
    {
        if(visited[V[x][i]] && V[x][i]!=Parent)
        {
            flag=1;
            return ;
        }

        if(!visited[V[x][i]])
        {
            dfs(V[x][i],x);
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
        V[y].pb(x);
    }

    rep(i,0,N)
    {
        if(!visited[i])
        {
            dfs(i,-1);
        }
    }

    if(flag)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

 return 0;
}
