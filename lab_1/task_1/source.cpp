#include <string>
#include <iostream>
using namespace std;
unsigned short height;
double salary;
void ReadDataPerson(string&, unsigned short&, double&);
void ReadDataPerson(string&, unsigned short&, unsigned short&, unsigned short&, double&);
void WritePersonData(const string&, unsigned short*, const string&, const string&);

int main() {
	unsigned short weight = 0;
	unsigned short age = 0;
	string name;

	ReadDataPerson(name, age, salary);
	WritePersonData(name,&age,to_string(height), to_string(weight));

	ReadDataPerson(name, age, height, weight, salary);
	WritePersonData(name, &age, to_string(height), to_string(weight));

	return 0;
}

unsigned short ReadPersonAge() {
	unsigned short age;
	cin >> age;
	return(age);
}

string ReadPersonName() {
	string name;
	cin >> name;
	return(name);
}

void ReadPersonHeight(){
	cin >> height;
}

void ReadPersonWeight(unsigned short &weight) {
	cin >> weight;
}

void ReadPersonSalary(double* salary) {
	cin >> *salary;
}

void WritePersonData(const string &name, unsigned short* age, const string &height = "", const string& weight = "") {
	cout << "name = " << name << " " << "height = " << height << " " << "weight = " << weight <<" " << "age = " << *age << " " << "salary = " << salary <<endl;
}

void ReadDataPerson(string &name,unsigned short &age,double &salary) {
	name = ReadPersonName();
	age = ReadPersonAge();
	ReadPersonSalary(&salary);
}
void ReadDataPerson(string &name, unsigned short &age, unsigned short &height, unsigned short &weight, double& salary) {
	name = ReadPersonName();
	age = ReadPersonAge();
	ReadPersonHeight();
	ReadPersonWeight(weight);
	ReadPersonSalary(&salary);
}
