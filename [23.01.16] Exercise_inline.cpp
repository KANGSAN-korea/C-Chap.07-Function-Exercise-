#include <iostream>
int main() {
	using namespace std;
	int rats = 101;
	int& rodents = rats;
	
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl; // 같을 것이다 
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl; // 둘 다 추가되어있어야 할 것

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl; // 같은 주소일 것
	return 0;
}