#include <iostream>

using namespace std;

int DivisorsSum(int n) {
	int Sum = 1;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			Sum += i;
	return Sum;
}

int isAmicable(int a) {
	int b = DivisorsSum(a);
	return (a == DivisorsSum(b) && a != b) ? b : 0;
}

void FromRange(int od, int b) {
	int t, i = od, ifExist = 0;
	while (i < b) {
		if ((t = isAmicable(i)) != 0 && i < t) {
			cout << i << " " << t << endl;
			ifExist = 1;
		}
		i++;
	}
	if (ifExist == 0)
		cout << "Nothing";
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << "Amicable numbers in <" << a << ", " << b << ">" << endl;
	FromRange(a, b);
	return 0;
}
