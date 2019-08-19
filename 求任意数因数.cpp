#include<cstdio>  
#include<cmath>
#include<iostream>
using namespace std;  
int  main()  
{  
	int t;
	cin>>t;
	while(t--)
	{ 
	    int n;  
	    int i;  
	    scanf("%d",&n);  
	    printf("%d = ",n);
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
			if(flag==1&&cnt>1)
			{
				cout<<i<<"^"<<cnt;
			}
			else if(flag==1&&cnt==1)
			{
				cout<<i;
			}
			else if(cnt>1) cout<<" * "<<i<<"^"<<cnt;
			else if(cnt==1) cout<<" * "<<i;
	    }   
	    cout<<endl;
	}
    return 0;  
}  
