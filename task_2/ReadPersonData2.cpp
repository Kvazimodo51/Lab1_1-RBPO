#include <string>
using namespace std;
unsigned short ReadPersonAge();
void ReadPersonHeight();
string ReadPersonName();
void ReadPersonSalary(double* salary);
void ReadPersonWeight(unsigned short& weight);
void ReadDataPerson(string& name, unsigned short& age, unsigned short& height, unsigned short& weight, double& salary) {
	name = ReadPersonName();
	age = ReadPersonAge();
	ReadPersonHeight();
	ReadPersonWeight(weight);
	ReadPersonSalary(&salary);
}