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
		cout << fn << "������ �� �� �����ϴ�. ��.\n";
		exit(EXIT_FAILURE);
	}																	// ���࿡ ep-data.txt ��� ������ �� �� ���ٸ�, ���α׷� ��
	double objective;
	cout << "�빰���� �����Ÿ���" "mm ������ �Է��Ͻʽÿ�: ";			// �����Ÿ� �Է�, ���� ���� �Է�, ��ȷ��� ���� ���� �� ��ŭ �ݺ� �� ���
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "���� ��ȷ����� �����Ÿ��� "
		"mm ������ �Է��Ͻʽÿ�:\n";
	for (int i = 0; i < LIMIT; i++) {
		cout << "��ȷ��� #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);								// file it �Լ� ȣ�� -> ���Ͽ� ���ٴ°Ű�
	file_it(cout, objective, eps, LIMIT);								// ������ ������ ȭ�鿡 ����Ѵ�
	cout << "����\n";
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n) {		// file it(os �� ����?, �Ҽ�, ���� �Ҽ��迭, ����)
	ios_base::fmtflags initial;											// �̰� ����?
	initial = os.setf(ios_base::fixed);									
	os.precision(0);
	os << "�빰������ �����Ÿ�: " << fo << "mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "��ȷ��� �����Ÿ�";
	os.width(15);
	os << "Ȯ�����" << endl;
	for (int i = 0; i < n; i++) {
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}