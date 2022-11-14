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
	string name = "";
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

float check_effektivnost(float x)
{
	while ((((cin >> x).fail()) || (cin.peek() != '\n')) || (x < 0) || (x > 100)) {
		cout << "Oshibka! Vvedite chislo > 0" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
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
		cout << "oshibka pri proverke pipe \nProverte dobavili li truby voobche?\nVvedite chislo (n > 0) and (n <= kol-vo trub)" << endl;
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
			cout << "Oshibka pri proverke CS \nProverte dobavili li CS voobche?\nVvedite chislo (n > 0) and (n <= kol-vo CS)" << endl;
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
	cout << "\n ID dlya truby\n " << p.idPipe;
	cout << "\nVvedite nazvanie\n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
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


void checkINFO(vector <Pipe>& gp, vector <CS>& gcs) {
	if (gp.size() != 0) {
		for (int i = 0; i < gp.size(); i++) {
			cout << "\nIndex of pipe: " << gp[i].idPipe << "\nPipe info:\nName: " << gp[i].name  << "\nLenght: " << gp[i].dlina << "\nDiameter : " << gp[i].diametr << "\nStatus : " << status_check(gp[i].status) << endl;
		}
	}
	else {
		cout << "\nBbl nichego ne vpisali po PIPE'u" << endl;
	}

	if (gcs.size() != 0) {
		for (int i = 0; i < gcs.size(); i++) {
			cout << "\nIndex of CS: " << gcs[i].idCS << "\nCS info:\nName: " << gcs[i].name << "\nNumber of workshops: " << gcs[i].cehi
				<< "\nNumber of working workshops: " << gcs[i].workcehi << "\nEffectiveness: "
				<< gcs[i].effektivnost << "%" << endl;
		}
	}
	else {
		cout << "\nBbl nichego ne vpisali po CS'u" << endl;
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
	if (idCS == 0)
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

void poisk_pipe(vector <Pipe>& g) {
	if (idPipe != 0) {
		cout << "\nPoisk truby po: 1.Name 2.Status" << endl;
		int edit;
		int k = 0;
		bool status = 0;
		string name;
		edit = check_redac();
		if (edit == 1) {
			cout << "name dlya pipe" << endl;
			cin >> name;
			for (int i = 0; i < g.size(); i++) {
				if (g[i].name == name) {
					k++;
					cout << "\nIndex of pipe: " << g[i].idPipe << "\nPipe info: " << "\nName: " <<
						g[i].name << "\nLenght: " << g[i].dlina << "\nDiameter : " << g[i].diametr
						<< "\nStatus: " << status_check(g[i].status) << endl;
				}
			}
		}
		else {
			cout << "\nPlease, enter status of pipe (0 if pipe is repairing, 1 if pipe works) " << endl;
			status = check_status_change(status);
			for (int i = 0; i < g.size(); i++) {
				if (g[i].status == status) {
					k++;
					cout << "\nIndex of pipe: " << g[i].idPipe << "\nPipe info: " << "\nName: " <<
						g[i].name << "\nLenght: " << g[i].dlina << "\nDiameter : " << g[i].diametr
						<< "\nStatus: " << status_check(g[i].status) << endl;
				}
			}
		}
		if (k == 0) {
			cout << "\nThere is no pipe with this status." << endl;
		}
	}
	else
		cout << "You don't have any pipe" << endl;
}

void poisk_cs(vector <CS>& g) {
	if (idCS != 0) {
		cout << "\nPoisk CS po: 1.Name 2.Effectivnost" << endl;
		int edit;
		int k = 0;
		float eff = 0;
		string name;
		edit = check_redac();
		if (edit == 1) {
			cout << "Please, enter the name of CS" << endl;
			cin >> name;
			for (int i = 0; i < g.size(); i++) {
				if (g[i].name == name) {
					k++;
					cout << "\nIndex of CS: " << g[i].idCS << "\nCS info:\nName: " << g[i].name << "\nNumber of workshops: " << g[i].cehi
						<< "\nNumber of working workshops: " << g[i].workcehi << "\nEffectiveness: "
						<< g[i].effektivnost << "%" << endl;
				}
			}
		}
		else {
			cout << "\nPlease, enter effectiveness of pipe (0-100) " << endl;
			eff = check_effektivnost(eff);
			for (int i = 0; i < g.size(); i++) {
				if (g[i].effektivnost == eff) {
					k++;
					cout << "\nIndex of CS: " << g[i].idCS << "\nCS info:\nName: " << g[i].name << "\nNumber of workshops: " << g[i].cehi
						<< "\nNumber of working workshops: " << g[i].workcehi << "\nEffectiveness: "
						<< g[i].effektivnost << "%" << endl;
				}
			}
		}
		if (k == 0) {
			cout << "\nThere is no CS with this effectiveness." << endl;
		}
	}
	else
		cout << "You don't have any CS" << endl;

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
	Pipe p;
	CS cs;

	vector <Pipe> pipe_group;
	vector <CS> cs_group;
	while (option) {
		cout << "\n 1. Dobavit trubu 2. Dobavit CS 3.Prosmotr obektov 4. Izmenit trubu 5. Izmenit CS 6.Save 7.Load 8. Poisk trub 9. Poisk CS 0. Exit\n";
		//cin >> option; //ввод переменной
		//option = prov_option(option);
		switch (prov_option(1,8)) { //так называемая тумбочка(без ящиков(case'ов))
		case 1: {
			addPipe(p);
			pipe_group.push_back(p);
			break;
		}

		case 2: {
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
			cout << "1. Izmenit trub'y 2. Izmenit vse truby\n";
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
			int redac;
			cout << "1. Izmenit CS'y 2. Izmenit vse CS\n";
			izmCS(select_cs(cs_group));
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
		case 8: {
			poisk_pipe(pipe_group);
			break;
		}

		case 9: {
			poisk_cs(cs_group);
			break;
		}

		case 0: {
			return 0;

		}
		default: cout << "vvedite chislo 1-8";
			break;
		}
	}
	return 0;
}