#include "Pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "checking.h"
using namespace std;
string status_check(bool x)
{
	if (x == true)
		return ("Truba rabotaet");
	else if (x == false)
		return ("Truba chinitsya");
	//else
		//return ("Neizvestnaya");

}
int Pipe::max_idp = 0;
istream& operator>> (istream& in, Pipe& p)//���������� ����������(���� �� ����� CIN � �����, �� ����������� ��� �������)
{
	cout << "\n ID dlya truby\n " << p.idpipe;
	cout << "\nVvedite nazvanie\n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "\nVvedite dliny\n"; //����� � �������
	p.dlina = check_cin(p.dlina);//�������� �����
	cout << "\nVvedite diametr\n";
	p.diametr = check_cin(p.diametr);
	cout << "\nVvedite sostoyanie tryBbl 0-remont, 1-rabotaet\n";
	p.status = check_status_change(p.status);
	cout << status_check(p.status) << endl;
}