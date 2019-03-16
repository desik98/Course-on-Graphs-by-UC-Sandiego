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
#define vlli    vector<lli>
#define plli	pair<lli,lli>
#define vplli	vector<plli >
#define Frst	first
#define Sec		second

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<lli>V[100001];
bool visited[100001];
lli dp[100001];
lli N;
I flag=1;

lli bfs(lli x)
{
    queue<lli>Q;
    lli i;

    Q.push(x);
    visited[x]=1;

    while(!Q.empty())
    {
        lli x=Q.front();
        Q.pop();

        rep(i,0,V[x].sz())
        {
            if(dp[x]==-1)
            {
                if(dp[V[x][i]]==-1)
                {
                    dp[x]=0;
                    dp[V[x][i]]=1;
                }
                else
                {
                    dp[x]=1-dp[V[x][i]];
                }
            }
            else
            {
                if(dp[V[x][i]]==-1)
                {
                    dp[V[x][i]]=1-dp[x];
                }
                else
                {
                    if(dp[V[x][i]]==dp[x])
                    {
                        return 0;
                    }
                }
            }

            if(!visited[V[x][i]])
            {
                visited[V[x][i]]=1;
                Q.push(V[x][i]);
            }
        }
    }

 return 1;
}

lli Check()
{
    memset(dp,-1,szof(dp));

    lli i;
    rep(i,1,N+1)
    {
        if(!visited[i])
        {
            if(!bfs(i))
            {
                return 0;
            }
        }
    }

 return 1;
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

    lli M,i,j;
    cin>>N>>M;

    while(M--)
    {
        lli x,y;
        cin>>x>>y;

        V[x].pb(y);
        V[y].pb(x);
    }

    if(!Check())
    {
        cout<<"-1";
    }
    else
    {
        vlli V1;
        vlli V2;

        lli cnt=0;
        rep(i,1,N+1)
        {
            if(dp[i]==0)
            {
                V1.pb(i);
            }
            else
            {
                V2.pb(i);
            }
        }

        cout<<V1.sz();
        nl;

        rep(i,0,V1.sz())
        {
            cout<<V1[i]<<' ';
        }
        nl;

        cout<<V2.sz();
        nl;

        rep(i,0,V2.sz())
        {
            cout<<V2[i]<<' ';
        }
        nl;
    }



 return 0;
}
