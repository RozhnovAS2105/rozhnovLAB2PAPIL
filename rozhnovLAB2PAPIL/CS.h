#pragma once
//здесь мы создаем класс КС
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
using namespace std;
class CS {
public: static int max_idcs;
	  CS() {
		  idcs = max_idcs++;
	  }
	  int dostat_id() { return idcs; }
	  double get_unused() { return(((double)cehi - (double)workcehi) / (double)workshop) * 100;
	  }//вычисление процента незадействованных станций
	  string name = "";
	  
private:
	int cehi, workcehi, idcs;
	double effektivnost;
};