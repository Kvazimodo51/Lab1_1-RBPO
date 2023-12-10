#include"Header.h"
int main() {
	setlocale(LC_ALL, "Russian");
	unsigned short weight = 0;
	unsigned short age = 0;
	string name;

	ReadDataPerson(name, age, salary);
	WritePersonData(name, &age, to_string(height), to_string(weight));

	ReadDataPerson(name, age, height, weight, salary);
	WritePersonData(name, &age, to_string(height), to_string(weight));

	return 0;
}
