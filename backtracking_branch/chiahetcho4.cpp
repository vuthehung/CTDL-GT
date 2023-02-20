#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
string s;
int k=0;

int main()
{
    faster();
   cin>>s;
   int n=s.size();
   for(int i=0;i<n;i++){
   	int c=s[i]-48;
   	if(c%4==0) k++;
   }
	for(int i=0;i<n-1;i++){
		int o=s[i]-48, p=s[i+1]-48;
		int c = o*10 + p;
		if(c%4==0)
			for(int j=0;j<=i;j++) k++;
	}
	cout<<k;
}





