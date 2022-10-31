//Папилина Татьяна Михайловна
#include <iostream>
#include <fstream>
#include <string>
#include <vector>;

using namespace std;

int idPipe = 0;
int idCS = 0;

struct Pipe
{
	float dlina = 0, diametr = 0;
	bool status = 0;
	int idPipe = 0;
};

struct CS
{
	string name = "";
	int cehi = -1, workcehi = -1, idCS = 0;
	float effektivnost = 0;
};

string check_name(string name)
{
	if (name.empty())
		return ("Oshibka!!!Pustoe pole");
	else
		return (name);
}


int prov_option(int min, int max)
{ // !x - proverka na tip dannyhpon
	int x;
	do
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nType number (" << min << "-" << max << "):\n";
		cin >> x;	
	} while (cin.fail() || x < min || x>max);
	//while (!x) {
		//cout << "\nVvedite chislo ot 1 do 8" << endl;
		//cin.clear();
		//cin.ignore(INT_MAX, '\n');
	//}
	return x;
}

string status_check(bool x)
{
	if (x == true)
		return ("Truba rabotaet");
	else if (x == false)
		return ("Truba chinitsya");
	else
		return ("Neizvestnaya");

}

float check_cin(float x)
{
	while ((((cin >> x).fail()) || (cin.peek() != '\n')) || (x <= 0)) { // "||" - или
		cout << "Oshibka!Vvedite chislo > 0\n" << endl;
		cin.clear();//o4istka 
		cin.ignore(INT_MAX, '\n'); //ubiraet new stroku v CIN(propusk vvodimoy peremenoy)
	}
	return x;
}

bool check_status_change(bool x)
{
	while (((cin >> x).fail()) || (cin.peek() != '\n')) {
		cout << "Oshibka! Vvedite chislo 0-remont ili 1-rabotaet\n" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return x;
}

int check_workcehi_cin(int x, int y)//x - рабочие цехи y - всего цехов
{
	while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < 0) || (x > y)) {
		cout << "Oshibka! Proverte, chtoby kol-stvo cehov > workcehov ili vvedennoe chislo > 0" << endl; //Функция endl не только вставляет символ перехода на новую строку, но еще и очищает буфер.
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return x;
}

int check_pipe_id(vector <Pipe>& g) {
	int x;
	while (((cin >> x).fail()) || (cin.peek() != '\n') || (x > g.size()) || (x < 0))
	{
		cout << "oshibka proverka pipe > 0" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return x;
}

int check_cs_id(vector <CS>& g) {
	int x;
	if (idPipe == 0)
		cout << "NET truby dlya izm";
	else {
		while (((cin >> x).fail()) || (cin.peek() != '\n') || (x > g.size()) || (x < 0))
		{
			cout << "oshibka proverka pipe > 0" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
	return x;
}

int check_redac() {
	int x;
	while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < 1) || (x > 2)) {
		cout << "Error!!! Input integer numeric value (1 or 2) " << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return x;
}

void addPipe(Pipe& p)
{
	idPipe++;
	p.idPipe = idPipe;
	cout << "\n Vvedite ID dlya truby\n " << p.idPipe;
	cout << "\nVvedite dliny\n"; //вывод в консоль
	p.dlina = check_cin(p.dlina);//проверка длины
	cout << "\nVvedite diametr\n";
	p.diametr = check_cin(p.diametr);
	cout << "\nVvedite sostoyanie tryBbl 0-remont, 1-rabotaet\n";
	p.status = check_status_change(p.status);
	cout << status_check(p.status) << endl;
}

void addCS(CS& cs)//FIX (Теряется название трубы «hahsh hahsh hahsh”, в просмотре только «hahsh»)
{
	idCS++;
	cs.idCS = idCS;
	cout << "\n Vvedite ID dlya truby\n " << cs.idCS;
	cout << "\nVvedite nazvanie\n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, cs.name);
	cs.name = check_name(cs.name);
	cout << "\nVvedite kolichestvo cehov\n";
	cs.cehi = check_cin(cs.cehi);
	cout << "\nVvedite kolichestvo cehov v rabote\n";
	cs.workcehi = check_workcehi_cin(cs.workcehi, cs.cehi);
	cs.effektivnost = float(cs.workcehi) / float(cs.cehi) * 100;
	cout << "\nEffektivnost\n" << cs.effektivnost << "%" << endl;
}
/*
void checkINFO(Pipe& p, CS& cs)
{
	if (p.dlina == 0)
		cout << "\nBbl nichego ne vpisali po PIPE'u" << endl;
	else {
		cout << "\nTruba informaciya dlina:\n" << p.dlina << "\nTruba informaciya diametr:\n" << p.diametr << "\nTruba informaciya status:\n" << p.status << endl << status_check(p.status) << endl;
	}
	if (cs.workcehi == -1)
		cout << "\nBbl nichego ne vpisali po CS'u" << endl;
	else {
		cout << "\nCS informaciya nazvanie:\n" << cs.name << "\nCS informaciya vsego cehov:\n" << cs.cehi << "\nCS informaciya rabochie cehi:\n " << cs.workcehi << "\nCS effektivnost:\n" << cs.effektivnost << "%" << endl;
	}
}
*/

/*void checkINFO(vector <Pipe>& gp, vector <CS>& gcs)
{
	if (gp.size() != 0) {
		for (int i = 0; i < gp.size(); i++) {
			cout << "\nId truby " << gp[i].idPipe << "\nPipe info:\nLenght: " << gp[i].dlina << "\nDiameter: " << gp[i].diametr
				<< "\nStatus: " << status_check(gp[i].status) << endl;
		}
	}
	if (gcs.size() != 0) {
		for (int i = 0; i < gp.size(); i++) {
			cout << "\nIndex of CS: " << gcs[i].idcs << "\nCS info:\nName: " << gcs[i].name << "\nNumber of workshops: " << gcs[i].cehi
				<< "\nNumber of working workshops: " << gcs[i].workcehi << "\nEffectiveness: "
				<< gcs[i].effektivnost << "%" << endl;
		}
	}
}*/
		//cout << "\nBbl nichego ne vpisali po PIPE'u" << endl;
	/*else {
		cout << "\nTruba informaciya dlina:\n" << p.dlina << "\nTruba informaciya diametr:\n" << p.diametr << "\nTruba informaciya status:\n" << p.status << endl << status_check(p.status) << endl;
	}
	if (cs.workcehi == -1)
		cout << "\nBbl nichego ne vpisali po CS'u" << endl;
	else {
		cout << "\nCS informaciya nazvanie:\n" << cs.name << "\nCS informaciya vsego cehov:\n" << cs.cehi << "\nCS informaciya rabochie cehi:\n " << cs.workcehi << "\nCS effektivnost:\n" << cs.effektivnost << "%" << endl;
	}
}*/

void checkINFO(vector <Pipe>& gp, vector <CS>& gcs) {
	if (gp.size() != 0) {
		for (int i = 0; i < gp.size(); i++) {
			cout << "\nIndex of pipe: " << gp[i].idPipe << "\nPipe info:\nLenght: " << gp[i].dlina << "\nDiameter: " << gp[i].diametr
				<< "\nStatus: " << status_check(gp[i].status) << endl;
		}
	}
	if (gcs.size() != 0) {
		for (int i = 0; i < gp.size(); i++) {
			cout << "\nIndex of CS: " << gcs[i].idCS << "\nCS info:\nName: " << gcs[i].name << "\nNumber of workshops: " << gcs[i].cehi
				<< "\nNumber of working workshops: " << gcs[i].workcehi << "\nEffectiveness: "
				<< gcs[i].effektivnost << "%" << endl;
		}
	}
}

void izmPipe(Pipe& p)
{
	if (idPipe == 0)//PROVERKA, chtovy byla tryba
		cout << "\nY nas net dostatochnou informacii dlya redactirovaniya\n";
	else {
		cout << "\nVvedite svezhiu status dlya tryby(0-remont, 1 -rabotaet)\n";
		p.status = check_status_change(p.status);
		cout << status_check(p.status) << endl;
	}
}

void izmPipe_all(vector <Pipe>& g) {
	bool x = 0;
	if (idPipe == 0)
		cout << "\nY nas net dostatochnou informacii dlya redactirovaniya\n";
	else {
		cout << "\nVvedite svezhiu status dlya tryby(0-remont, 1 -rabotaet)\n";
		x = check_status_change(x);
		for (int i = 0; i < g.size(); i++) {
			g[i].status = x;
		}
		cout << status_check(x) << endl;
	}
}

void izmCS(CS& cs) 
{
	if (cs.workcehi == -1)
		cout << "\nY nas net dostatochnou informacii dlya redactirovaniya\n";
	else {
		cout << "Vvedite svezhiu kolichestvo rabochih cehov\n";
		cs.workcehi = cs.workcehi = check_workcehi_cin(cs.workcehi, cs.cehi);
		cs.effektivnost = float(cs.workcehi) / float(cs.cehi) * 100;
		cout << "\nEffektivnost\n" << cs.effektivnost << "%" << endl;
	}
}


void save(Pipe& p, CS& cs)
{
	ofstream file;
	file.open("SAVE.txt");
	file << p.dlina << endl << p.diametr << endl << p.status << endl << cs.cehi << endl << cs.workcehi << endl << cs.effektivnost << endl << cs.name << endl;
	file.close();
}

void load(Pipe& p, CS& cs)//dobavil proverku na nalichie file
{
	ifstream file2;
	string line;
	file2.open("SAVE.txt");
	if (file2.is_open()) {//если успешно открыт, то работаем дальше 
		getline(file2, line);
		p.dlina = stof(line);
		getline(file2, line);
		p.diametr = stof(line);
		getline(file2, line);
		p.status = stoi(line);
		getline(file2, line);
		cs.cehi = stoi(line);
		getline(file2, line);
		cs.workcehi = stoi(line);
		getline(file2, line);
		cs.effektivnost = stod(line);
		getline(file2, line);
		cs.name = line;
	}
	else//иначе высвечивается "не нашел файл"
		cout << "Ne nashel file";
}

Pipe& select_pipe(vector <Pipe>& g) {
	cout << "id Pipe ";
	int id = check_pipe_id(g);
	return g[id - 1];
}
CS& select_cs(vector <CS>& g) {
	cout << "id CS ";
	int id = check_cs_id(g);
	return g[id - 1];
}

int main()
{
	//setlocale(LC_ALL, "ru");
	int option = -1;
	cout << "PRESS ENTER";
	//Pipe p;
	//CS cs;

	vector <Pipe> pipe_group;
	vector <CS> cs_group;
	while (option) {
		cout << "\n 1. truba 2. CS 3.Prosmotr obektov 4. izmenit trubu 5. izmenit CS 6.save 7.load 8. 9. 0. exit\n";
		//cin >> option; //ввод переменной
		//option = prov_option(option);
		switch (prov_option(1,8)) { //так называемая тумбочка(без ящиков(case'ов))
		case 1: {
			Pipe p;
			addPipe(p);
			pipe_group.push_back(p);
			break;
		}

		case 2: {
			CS cs;
			addCS(cs);
			cs_group.push_back(cs);
			break;

		}
		case 3: {
			//checkINFO(p, cs);
			checkINFO(pipe_group, cs_group);
			break;
		}
		case 4: {
			int redac;
			cout << "1. Izmenit trub'y 2. Izmenit vse truby";
			redac = check_redac();
			if (redac == 1)
				izmPipe(select_pipe(pipe_group));
			else
				izmPipe_all(pipe_group);
			//izmPipe(p);
			break;
		}
		case 5: {
			//izmCS(cs);
			break;
		}
		case 6: {
			//save(p, cs);
			break;
		}
		case 7: {
			//load(p, cs);
			break;
		}
		/*case 8: {
			()
			break;
		}

		case 9: {
			()
			break;
		}*/

		case 0: {
			return 0;

		}
		default: cout << "vvedite chislo 1-8";
			break;
		}
	}
	return 0;
}