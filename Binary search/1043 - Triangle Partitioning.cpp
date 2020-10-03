#include<bits/stdc++.h>
using namespace std;
int z;
void solve()
{
    double AB,AC,BC,r;
    cin>>AB>>AC>>BC>>r;

    double AD=AB/2;
    double BD,AE,EC,DE,low=0,high=AB;

    BD=AB-AD;
    AE=(AD*AC)/AB;
    DE=(AD*BC)/AB;
    EC=AC-AE;

    double s1=(AD+DE+AE)/2;
    double s2=(AB+BC+AC)/2;

    double area1,area2;
    area1=sqrt(s1*(s1-AD)*(s1-DE)*(s1-AE));
    area2=sqrt(s2*(s2-AB)*(s2-BC)*(s2-AC));
    area2-=area1;

    double r2=area1/area2;

    while(abs(r-r2)>=1e-8)
    {
        if(r2>r)
            high=AD;

        else if(r2<r)
            low=AD;

            AD=(low+high)/2;
            BD=AB-AD;
    AE=(AD*AC)/AB;
    DE=(AD*BC)/AB;
    EC=AC-AE;

    s1=(AD+DE+AE)/2;
    s2=(AB+BC+AC)/2;

    area1=sqrt(s1*(s1-AD)*(s1-DE)*(s1-AE));
   area2=sqrt(s2*(s2-AB)*(s2-BC)*(s2-AC));
    area2-=area1;

    r2=area1/area2;

    }
    cout<<"Case "<<z<<": ";
    cout<<fixed<<setprecision(10)<<AD<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(z=1;z<=t;z++)
        solve();
    return 0;
}

