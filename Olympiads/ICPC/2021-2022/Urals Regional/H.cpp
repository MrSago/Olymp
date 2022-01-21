
#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int phi (unsigned long long n) {
	unsigned long long result = n;
	for (unsigned long long i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


int NOD(ull a, ull b)
{
    while(a > 0 && b > 0)
        if(a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int kek = phi(n-1);
        if (kek % 2 != 0){
            ull s = n/2;
            while (NOD(n,s) != 1){
                s++;
            }
            cout << s << "\n";
        }else{
            ull s = n/2;
            while (NOD(n,s) != 1){
                s--;
            }
            cout << s << "\n";
        }
    }
}

