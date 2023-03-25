#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define ll long long 

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}

bool gr(int a, int b) {
	return a > b;
}
int main()
{
	//x -> zeros
	//y -> ones

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		ll x = 0, y = 0;
		ll l = s.length();
		ll xs = 0, ys = 0;
		ll xcounter = 0;
		ll ycounter = 0;

		if (s[0] == '0') {
			xs = 1;
			xcounter = 1;
		}
		else {
			ys = 1;
			ycounter = 1;
		}
		if (l == 1) {
			cout << 1 << endl;
			continue;
		}

		for (ll i = 1; i < l; ++i) {

			
			if (s[i] == '0') {
				xs++;
				xcounter++;
				x = max(x, xcounter);
				ycounter = 0;
			}
			else {
				ys++;
				ycounter++;
				y = max(y, ycounter);
				xcounter = 0;
			}

			if (s[i] != s[i - 1]) {
				if (s[i] == '0') {
					xcounter = 1;
				}
				else {
					ycounter = 1;
				}
			}
			
			
			
		}

		//cout << x << ' ' << y << endl;
		cout <<  max(max(x * y, x * x), max(y * y, xs * ys)) << endl;
		

	}
	return 0;
}