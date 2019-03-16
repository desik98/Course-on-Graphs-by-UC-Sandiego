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
#define F		first
#define S		second

#define Inf     10000000000000
#define mod		1000000007
using namespace std;

vector<pair<lli,lli> >V[1001];
lli dist[1001];
lli N,M;

void BellMan_Ford()
{
    lli i,j,k;

    rep(i,0,1001)
    {
        dist[i]=Inf;
    }

    dist[1]=0;

    rep(i,1,N+1)
    {
        lli cnt=0;
        rep(j,1,N+1)
        {
            rep(k,0,V[j].sz())
            {
                if(dist[V[j][k].F]>dist[j]+V[j][k].S)
                {
                    dist[V[j][k].F]=dist[j]+V[j][k].S;
                    cnt++;

                    if(i==N)
                    {
                        cout<<"1";
                        exit(0);
                    }
                }
            }
        }

        if(cnt)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    cout<<'0';
}

int main()
{
    opt;

    cin>>N>>M;

    while(M--)
    {
        lli x,y,w;
        cin>>x>>y>>w;

        V[x].pb(mp(y,w));
    }

    BellMan_Ford();


 return 0;
}
