#pragma once
#include <iostream>
#include <list>
#include <sstream>
using namespace std;
namespace buscarEnPolinomio {
	list<float> buscarNumeros(const string& polinomio) {
		string r = polinomio;
		list<float> lista;
		int i = 0;
		for (char a : polinomio) {
			switch (a) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				lista.push_front(i);
			}
			i++;
		}
		return lista;
	}
	list<float> buscar(const string& a, const char&b) {
		list<float> aux;
		int i = 0;
		for (char c : a) {
			if (c == b) aux.push_front(i);
			i++;
		}
		return aux;
	}
	list<float> coeficientes(const string& s) {
		string aux = s;
		string pass ="";
		cout << aux<<endl;
		bool *deletenumbers= new bool;
		*deletenumbers = false;
		auto guardar = [](char x, bool *&deletenumbers) {
			bool character = (48 <= x and x <= 57) or x == '.';
			if (x == '^') *deletenumbers = true;
			if (x == '+' or x == '-') *deletenumbers = false;
			if (*deletenumbers == true) return true;
			else if (character and *deletenumbers == false) return false;
			else return true;
		};
		auto esUnNUmero = [](char x) {
			if (48 <= x and x <= 57) return true;
			else if (x == '.') return true;
			else return false;
		};
		for (int i = 0; i < aux.length(); i++) {
			bool set = guardar(aux[i], deletenumbers);
			if(set == false) {
				pass += aux[i];
			}
			else {
				pass += " ";
			}
		}
		string aux2 ="";
		list<float> numeros;
		for (char s : pass) {
			bool isnumber = esUnNUmero(s);
			if (isnumber == true) {
				aux2 += s;
			}
			else {
				if (0 < aux2.length()) {
					numeros.push_front(atof(aux2.c_str()));
					aux2 = "";
				}
			}
		}
		return numeros;
	}
	
}

