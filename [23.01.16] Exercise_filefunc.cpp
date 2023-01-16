#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main() {
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open()) {
		cout << fn << "파일을 열 수 없습니다. 끝.\n";
		exit(EXIT_FAILURE);
	}																	// 만약에 ep-data.txt 라는 파일을 열 수 없다면, 프로그램 끝
	double objective;
	cout << "대물렌즈 초점거리를" "mm 단위로 입력하십시오: ";			// 초점거리 입력, 제한 값을 입력, 대안렌즈 값을 제한 값 만큼 반복 및 출력
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "가지 대안렌즈의 초점거리를 "
		"mm 단위로 입력하십시오:\n";
	for (int i = 0; i < LIMIT; i++) {
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);								// file it 함수 호출 -> 파일에 쓴다는거고
	file_it(cout, objective, eps, LIMIT);								// 동일한 정보는 화면에 출력한다
	cout << "종료\n";
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n) {		// file it(os 가 뭐임?, 소수, 고정 소수배열, 정수)
	ios_base::fmtflags initial;											// 이게 뭔데?
	initial = os.setf(ios_base::fixed);									
	os.precision(0);
	os << "대물렌즈의 초점거리: " << fo << "mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "대안렌즈 초점거리";
	os.width(15);
	os << "확대배율" << endl;
	for (int i = 0; i < n; i++) {
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}