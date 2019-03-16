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

#define Inf     1000000000
#define mod		1000000007
using namespace std;

vector<pair<lli,lli> >V[100001];
bool visited[100001];
lli dist[100001];
lli N;
lli A,B;

void Djikstra()
{
    lli i;

    memset(visited,0,szof(visited));

    rep(i,1,N+1)
    {
        dist[i]=Inf;
    }

    dist[A]=0;

    multiset<pair<lli,lli> >M;

    M.insert({0,A});

    while(!M.empty())
    {
        pair<lli,lli> s = *M.begin();

        M.erase(M.begin());

        lli x=s.Frst,y=s.Sec;

        if(visited[y])
        {
            continue;
        }

        visited[y]=1;

        rep(i,0,V[y].sz())
        {
            lli e=V[y][i].Frst,f=V[y][i].Sec;

            if(dist[y]+f<dist[e])
            {
                dist[e]=dist[y]+f;
                M.insert({dist[e],e});

                dp[e]=dp[y];
            }
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

    lli M,i;
    cin>>N>>M;

    while(M--)
    {
        lli x,y,w;
        cin>>x>>y>>w;

        V[x].pb(mp(y,w));
    }

    cin>>A>>B;

    Djikstra();

    if(dist[B]==Inf)
    {
        cout<<"-1";
        exit(0);
    }

    cout<<dist[B]<<' ';


 return 0;
}
