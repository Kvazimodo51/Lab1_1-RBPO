#include <string>
#include <iostream>
using namespace std;
unsigned short height;
double salary;
void ReadDataPerson(string&, unsigned short&, double&);
void ReadDataPerson(string&, unsigned short&, unsigned short&, unsigned short&, double&);
void WritePersonData(const string&, unsigned short*, const string&, const string&);
void ReadPersonHeight();
string ReadPersonName();
void ReadPersonSalary(double* salary);
void ReadPersonWeight(unsigned short& weight);
unsigned short ReadPersonAge();