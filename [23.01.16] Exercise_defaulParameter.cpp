#include <iostream>
const int ArSize = 80;
char* left(const char* str, int n = 1);
int main() {
	using namespace std;
	char sample[ArSize];
	cout << "���ڿ��� �Է��Ͻʽÿ�:\n";
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
	for (i = 0; i < n && str[i]; i++) // i�� n���� �۰� �� ���� �ƴ� ��, ���� �迭�� �޾ƿ� �迭 ���� ����
		p[i] = str[i];				  // i�� n������ 
	while (i <= n)
		p[i++] = '\0';
	return p;
}