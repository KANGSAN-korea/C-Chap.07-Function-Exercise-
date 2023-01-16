#include <iostream>
int main() {
	using namespace std;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats狼 林家 = " << &rats;
	cout << ",  rodents狼 林家 = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies狼 林家 = " << &bunnies;
	cout << "rodents狼 林家 = " << &rodents << endl;
	return 0;
}