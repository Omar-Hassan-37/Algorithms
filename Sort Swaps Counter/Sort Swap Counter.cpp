// GROUP:   3
// ID:      20170174
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    Omar Hassan Hosny

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long CountInvMerge(long long* a, int n);
long long CountInv(long long* a, int n);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int n;
	int j = 0;
	int input;
	cin >> n;
	long long* a = new long long[n];
	vector <long long> a2;

	while (n != 0 && n < 500000)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			if (input >= 0 && input <= 999999999) {
				a[i] = input;
			}
		}
		a2.push_back(CountInvMerge(a, n));
		j++;
		cin >> n;
	}
	delete[]a;
	for (int i = 0; i < j; i++)
	{
		cout << a2[i] << endl;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long CountInvMerge(long long* a, int n)
{
	int mid = 0;
	long long inv_count = 0;
	mid = n / 2;

	if (n > 1) {
		inv_count += CountInvMerge(a, mid);
		inv_count += CountInvMerge(a + mid, n - mid);
		inv_count += CountInv(a, n);
	}
	return inv_count;
}

long long CountInv(long long* a, int n)
{
	int i = 0;
	int j = n / 2;
	int k = 0;
	int mid = n / 2;

	long long inv_count = 0;
	long long* temp = new long long[n];

	while ((i <= mid - 1) && (j <= n - 1)) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			i++;
			k++;
		}
		else {
			temp[k] = a[j];
			j++;
			k++;
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1) {
		temp[k] = a[i];
		i++;
		k++;
	}

	while (j <= n) {
		temp[k] = a[j];
		j++;
		k++;
	}

	for (int i = 0; i < n; i++) {
		a[i] = temp[i];
	}

	return inv_count;
}

