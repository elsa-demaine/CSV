// CSV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "contact.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>

using namespace std;

int main()
{
	//Permet d'afficher le contenu du fichier
	ifstream infile;
	infile.open("projet_CPP.csv");
	string line;
	list<contact> pagesJaunes;
	string topline;

	while (infile >> line) {
		replace(line.begin(), line.end(), ',', ' ');
		istringstream iss(line);
		vector<string> results((istream_iterator<string>(iss)),
			istream_iterator<string>());
		cout << line << endl;

		int id = atoi(results[0].c_str());
		if (id == 0) {
			replace(line.begin(), line.end(), ' ', ',');
			topline = line;
		}
		else {
			int age = atoi(results[3].c_str());
			int phoneNb = atoi(results[4].c_str());
			contact thisContact(id, results[1], results[2], age, phoneNb);
			pagesJaunes.push_back(thisContact);
		}
	}
	infile.close();
	ofstream outfile;
	
	string response;
	cout << "Que voulez vous faire ? (1. Ajouter, 2. Modifier, 3. Supprimer)" << endl;
	cin >> response;
	if (response == "1") {
		outfile.open("projet_CPP.csv", ios::app);
		string nom;
		string prenom;
		int age;
		int telephone;

		cout << "Veuilliez entrer le nom" << endl;
		cin >> nom;
		cout << "Veuilliez entrer le prénom" << endl;
		cin >> prenom;
		cout << "Veuilliez entrer l'age" << endl;
		cin >> age;
		cout << "Veuilliez entrer le numéro de téléphone" << endl;
		cin >> telephone;
		int id = pagesJaunes.back().getId() +1;

		contact c1(id, nom, prenom, age, telephone);
		outfile << endl << c1.makeCSV() << endl;
		outfile.close();
	}
	else if (response == "2") {
		cout << "Quelle contacte voulez vous modifier ?" << endl;

	}
	else if (response == "3") {
		outfile.open("projet_CPP.csv");
		cout << "Quelle contacte voulez vous supprimer ? (Veuilliez spécifier l'identifiant)" << endl;
		cin >> response;
		int eraseId = atoi(response.c_str());
		for (list<contact>::iterator it = pagesJaunes.begin(); it != pagesJaunes.end(); ++it)
		{
			if ((*it).getId() == eraseId)
			{
				pagesJaunes.erase(it);
				break;
			}
		}

		outfile << topline << endl;
		for (list<contact>::iterator its = pagesJaunes.begin(); its != pagesJaunes.end(); ++its) {
			outfile << (*its).makeCSV() << endl;
		}

		cout << "Le contacte a bien ete supprimer" << endl;
		outfile.close();
	}
	else {
		cout << "Ce n'est pas un choix valide, veuilliez saisir un chiffre" << endl;
	}

	
}

