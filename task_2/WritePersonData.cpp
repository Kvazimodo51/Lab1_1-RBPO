#include <iostream>
using namespace std;
extern double salary;
void WritePersonData(const string& name, unsigned short* age, const string& height = "", const string& weight = "") {
	cout << "name = " << name << " " << "height = " << height << " " << "weight = " << weight << " " << "age = " << *age << " " << "salary = " << salary << endl;
}
