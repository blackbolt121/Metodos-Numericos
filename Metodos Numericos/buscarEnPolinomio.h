#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
namespace buscarEnPolinomio {
	vector<int> buscarNumeros(const string& polinomio) {
		string r = polinomio;
		vector<int> lista;
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
				lista.push_back(i);
			}
			i++;
		}
		return lista;
	}
	vector<int> buscar(const string& a, const char&b) {
		vector<int> aux;
		int i = 0;
		for (char c : a) {
			if (c == b) aux.push_back(i);
			i++;
		}
		return aux;
	}
	void coeficientes(const string& s) {
		string aux = s;
		string pass ="";
		cout << aux<<endl;
		bool *deletenumbers= new bool;
		*deletenumbers = false;
		auto lambda = [](char x, bool *&deletenumbers) {
			bool character = (48 <= x and x <= 57) or x == '.';
			if (x == '^') *deletenumbers = true;
			if (x == '+' or x == '-') *deletenumbers = false;
			if (*deletenumbers == true) return true;
			else if (character and *deletenumbers == false) return false;
			else return true;
		};
		for (int i = 0; i < aux.length(); i++) {
			cout << lambda(aux[i], deletenumbers) << "deletenumbers: " << *deletenumbers << endl;
			bool set = lambda(aux[i], deletenumbers);
			if(set == false) {
				pass += aux[i];
			}
			else {
				pass += " ";
			}
		}
		cout << pass;
	
	}
}

