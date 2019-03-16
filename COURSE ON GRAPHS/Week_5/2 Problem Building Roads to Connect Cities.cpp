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
#define F   	first
#define S  		second

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<pair<double,plli> >V;
lli id[201];
lli Size[201];

void Initialize()
{
    lli i;

    rep(i,0,201)
    {
        id[i]=i;
        Size[i]=1;
    }
}

lli root(lli x)
{
    while(id[x]!=x)
    {
        x=id[id[x]];
    }

 return x;
}

void Union(lli x,lli y)
{
    lli p=root(x);
    lli q=root(y);

    if(Size[p]<Size[q])
    {
        id[p]=q;
        Size[q]+=Size[p];
    }
    else
    {
        id[q]=p;
        Size[p]+=Size[q];
    }
}

double Kruskal()
{
    lli i;
    double Minimum_Cost=0;

    rep(i,0,V.sz())
    {
        double w=V[i].F;
        lli x=V[i].S.F;
        lli y=V[i].S.S;

        if(root(x)!=root(y))
        {
            Minimum_Cost+=w;
            Union(x,y);
        }
    }

 return Minimum_Cost;
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

    lli N,i,j;
    cin>>N;

    vector<plli >V1;

    V1.pb(mp(0,0));
    rep(i,0,N)
    {
        lli x,y;cin>>x>>y;

        V1.pb(mp(x,y));
    }

    rep(i,1,V1.sz()-1)
    {
        rep(j,i+1,V1.sz())
        {
            lli x1=V1[i].F,y1=V1[i].S,x2=V1[j].F,y2=V1[j].S;

            lli x=x1-x2,y=y1-y2;
            double d=sqrt(x*x+y*y);

            V.pb(mp(d,mp(i,j)));
        }
    }

    sort(V.begin(),V.end());

    Initialize();

    cout<<setprecision(10)<<fixed<<Kruskal();






 return 0;
}
