#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <string.h>
using namespace std;
typedef unsigned long long ull;

ull a, b, c, k; 

/*
b가 짝수: a^b = a^(b/2+b/2) = a^(b/2) * a^(b/2)
b가 홀수: a^b = a^(b/2 + b/2+1) = a^(b/2) * a^(b/2+1)
(a * b) % c = (a%c * b%c) % c
*/

ull power(ull b){
	if(b == 0) return 1;
	if(b == 1) return a % c;

	k = power(b / 2) % c;
	if(b % 2 == 0) return k * k % c; 
	else return k * k % c * a % c; 
}

int main()
{ 
	scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", power(b));

	return 0;
}