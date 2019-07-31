#include <bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define append push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pb push_back
#define print(a) cout<<a<<" "
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define all(x) x.begin(), x.end()
#define search(a,b,x) binary_search(a, b, x)
#define loop(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve()
{
   int arr[11];
    ll count=0;
   mem(arr,0);
   int balls=0,wicket=0;
   int p1=0,p2=1;
   int i=p1;
   string x;


   while((wicket<=10||balls<=120)&&cin>>x)
   {


      int ctr=x.length();
      if(balls%6==0&&balls!=0)
      {
        if(i==p1)
        i=p2;
        else if(i==p2)
        i=p1;
          //balls++;
      }
       if(ctr>2)
       {

         int n=x[0]-'0';
        arr[i]+=n;
         if(n%2==1)
         {
             if(i==p1)
        i=p2;
        else
        i=p1;
         }
       }
       else if(ctr<2)
       {
           if(x[0]=='W')
      {
        balls++;
        if(i==p1)
        {
            p1=p2+1;
            i=p1;
            swap(p1,p2);
        }
        else
        p2+=1;
        i=p2;
      }
     else
      {
         balls++;
        int n=x[0]-'0';
        arr[i]+=n;

        if(n%2==1)
        {
            if(i==p1)
                i=p2;
            else
                i=p1;
        }
       }

       }

   }
   i=0;
    loop(i,11)
    {
      print(arr[i]);
    }
}
int  main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

        solve();

    return 0;
}
