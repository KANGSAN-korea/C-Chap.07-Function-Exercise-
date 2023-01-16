#include <iostream>
#include <string>
struct free_throw {
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throw& ft);
void set_pc(free_throw& ft);
free_throw& accumulate(free_throw& target, const free_throw& source);

int main() {
	free_throw one = { "Ifelsa Branch", 13 , 14 };
	free_throw two = { "Andor Knott", 10, 16 };
	free_throw three = { "Minnie Max", 7, 9 };
	free_throw four = { "Whily Looper", 5, 9 };
	free_throw five = { "Long Long", 6, 15 };
	free_throw team = ("Throwgoods", 0, 0);

	free_throw dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	
	dub = accumulate(team, five);
	std::cout << "team 출력: \n";
	display(team);
	std::cout << "대입 이후 dup 출력:\n";
	display(dup);
	set_pc(four);

	accumulate(dup, five) = four;
	std::cout << "문제 소지가 있는 대입 이후 dup 출력:\n";
	display(dup);
	return 0;
}

void display(const free_throw& ft) {
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << "Made: " << ft.name << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " >> ft.percent << '\n';
}

void set_pc(free_throw& tf) {
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

free_throw& accumulate(free_throws& target, const free_throws& source);
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}