#pragma once
//����� �� ������� ����� �����
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Pipe
{
public:
	static int max_idp;
	string name = "";
	bool status = 0;
	Pipe() {
		idpipe = max_idp++;//��� � ���� ���������� � �����, ������������� ������������� �������� ���.
	}
	int dostaet_id() { return idpipe; }// ������� �� �������
private:
	double dlina = 0, diametr = 0;
	int idpipe = 0;
};