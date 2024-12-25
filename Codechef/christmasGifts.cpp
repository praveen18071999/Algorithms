#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int h,l,w;
	    cin>>h>>l>>w;
	    int t=floor(1000/(2*(h*l + l*w + h*w)));
	    cout<<t<<"\n";
	}

}