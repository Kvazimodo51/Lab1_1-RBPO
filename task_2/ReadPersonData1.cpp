#include <string>
using namespace std;
unsigned short ReadPersonAge();
void ReadPersonHeight();
string ReadPersonName();
void ReadPersonSalary(double* salary);
void ReadPersonWeight(unsigned short& weight);
void ReadDataPerson(string& name, unsigned short& age, double& salary) {
	name = ReadPersonName();
	age = ReadPersonAge();
	ReadPersonSalary(&salary);
}