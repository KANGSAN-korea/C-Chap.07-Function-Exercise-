#include <iostream>
const int ArSize = 80;
char* left(const char* str, int n = 1);
int main() {
	using namespace std;
	char sample[ArSize];
	cout << "문자열을 입력하십시오:\n";
	cin.get(sample, ArSize);
	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
	return 0;
}

char* left(const char* str, int n) {
	if (n < 0) n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++) // i가 n보다 작고 널 값이 아닐 때, 지역 배열에 받아온 배열 값을 읽음
		p[i] = str[i];				  // i가 n개까지 
	while (i <= n)
		p[i++] = '\0';
	return p;
}