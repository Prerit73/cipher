
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n-1) + fib(n-2);
}

int fact(int n){
    if(n==0 || n==1)
    return 1;
    
    return n*fact(n-1);
}

int main ()
{
	int n = 5;
	cout<<fib(n)<<endl;
	cout<<fact(n)<<endl;

}


