#include<cstdio>  
#include<cmath>
#include<iostream>
using namespace std;  
int main()  
{  
	int t;
	cin>>t;
	while(t--)
	{ 
	    int n,m;  
	    int i;  
	    scanf("%d %d",&n,&m);  
		int flag=0;  
	    for(i=2;i<=n;i++)  
	    {  
	    	int cnt=0; 
	    	if(n%i==0) flag++;
	        while(n%i==0)
	        {
	        	cnt++;
	        	n/=i;
			}
			if(flag==1&&cnt*m>1)
			{
				cout<<i<<"^"<<cnt*m;
			}
			else if(flag==1&&cnt*m==1)
			{
				cout<<i;
			}
			else if(cnt*m>1) cout<<" * "<<i<<"^"<<cnt*m;
			else if(cnt*m==1) cout<<" * "<<i;
	    }   
	    cout<<endl;
	}
    return 0;  
} 
