#include <iostream>
unsigned long left(unsigned long num, unsigned ct);	// 함수 오버로딩
char* left(const char* str, int n = 1);				// 함수 오버로딩 동시에, 디폴트 매개변수 설정
int main() {
	using namespace std;
	const char * trip = "Hawaiii!!";			
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++) {
		cout << left(n, i) << endl;						// 10개의 숫자공간으로 이루어진 숫자배열을 차례로 출력
		temp = left(trip, i);							// 10개의 문자공간으로 이루어진 문자배열을 차례로 출력
		cout << temp << endl;
		delete[] temp;									// 임시 저장 공간 삭제(문자)
	}
	return 0;
}

unsigned long left(unsigned long num, unsigned ct) {	// 숫자에 대한 오버로딩
	unsigned digits = 1;								
	unsigned long n = num;
	if (ct == 0 || num == 0)							// 만약에 숫자 또는, 길이가 0일 경우 함수 탈출을 한다
		return 0;

	while (n /= 10)										// 만약 숫자를 10으로 나눴을 때 값이 있을 경우
		digits++;
														// 자릿수를 카운트 하고
	if (digits > ct) {									// 만약 해당 자릿수가 지정한 숫자의 자릿수보다 많을 경우
		ct = digits - ct;								// 출력을 원하는 자릿수는 자릿수 - 원하는 갯수
		while (ct--)									// 출력을 원하는 자릿수를 -1함
			num /= 10;									
		return num;
	}

	else
		return num;
}

char* left(const char* str, int n) {
	if (n < 0) n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}