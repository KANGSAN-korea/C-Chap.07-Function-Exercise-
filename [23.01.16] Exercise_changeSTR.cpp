#include <iostream>

struct applicant {
	char name[30];
	int credit_rating[3];
};

int main() {
	viewApplicant(applicant);
	viewApplicantwithAddress(applicant);
}

void viewApplicant(applicant structure) {
	cout << structure.name;
	cout << sturcture.credit_rating;
}

void viewApplicantwithAddress(applicant* structures) {
	cout << structures->name;
	cout << sturctures->credit_rating;

}