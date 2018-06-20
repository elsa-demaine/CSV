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
	bool res = false;
	while (res == false) {
		cout << "Que voulez vous faire ? (1. Ajouter, 2. Modifier, 3. Supprimer, 4.Voir la liste, 5. Quitter)" << endl;
		cin >> response;
		if (response == "1") {
			outfile.open("projet_CPP.csv", ios::app);
			string nom;
			string prenom;
			int age;
			int telephone;

			cout << "Veuilliez entrer le nom" << endl;
			cin >> nom;
			cout << "Veuilliez entrer le prenom" << endl;
			cin >> prenom;
			cout << "Veuilliez entrer l'age" << endl;
			cin >> age;
			cout << "Veuilliez entrer le numero de telephone" << endl;
			cin >> telephone;
			int id = pagesJaunes.back().getId() + 1;

			contact c1(id, nom, prenom, age, telephone);
			pagesJaunes.push_back(c1);
			outfile << endl << c1.makeCSV() << endl;
			cout << "le contacte a bien ete ajouter" << endl;
			outfile.close();
		}
		else if (response == "2") {
			outfile.open("projet_CPP.csv");
			cout << "Quelle contacte voulez vous modifier ? (Veuilliez specifier l'identifiant)" << endl;
			cin >> response;
			int eraseId = atoi(response.c_str());
			for (list<contact>::iterator it = pagesJaunes.begin(); it != pagesJaunes.end(); ++it)
			{
				if ((*it).getId() == eraseId)
				{
					cout << "Modifier le : 1. Nom, 2. Prenom, 3. Age, 4. Numero de telephone" << endl;
					bool mod = false;
					while (mod == false) {
						cin >> response;
						if (response == "1") {
							cout << "Entrez le Nom" << endl;
							cin >> response;
							(*it).setName(response);
							mod = true;
						}
						else if (response == "2") {
							cout << "Entrez le Prenom" << endl;
							cin >> response;
							(*it).setFirstName(response);
							mod = true;
						}
						else if (response == "3") {
							cout << "Entrez l'age" << endl;
							cin >> response;
							int age = atoi(response.c_str());
							(*it).setAge(age);
							mod = true;
						}
						else if (response == "4") {
							cout << "Entrez le numero de telephone" << endl;
							cin >> response;
							int phone = atoi(response.c_str());
							(*it).setPhoneNb(phone);
							mod = true;
						}
						else {
							cout << "Veuilliez choisir un des chiffres indiquer" << endl;
							mod = false;
						}
					}
					break;
				}
			}

			outfile << topline << endl;
			for (list<contact>::iterator its = pagesJaunes.begin(); its != pagesJaunes.end(); ++its) {
				outfile << (*its).makeCSV() << endl;
			}

			cout << "Le contacte a bien ete modifier" << endl;
			outfile.close();
		}
		else if (response == "3") {
			outfile.open("projet_CPP.csv");
			cout << "Quelle contacte voulez vous supprimer ? (Veuilliez specifier l'identifiant)" << endl;
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
		else if (response == "4") {
			for (list<contact>::iterator its = pagesJaunes.begin(); its != pagesJaunes.end(); ++its) {
				cout << (*its).getId() << " " << (*its).getName() << " " << (*its).getFirstName() << " " << (*its).getAge() << " " << (*its).getPhoneNb() << endl;
			}
		}
		else if (response == "5") {
			res = true;
		}
		else {
			cout << "Ce n'est pas un choix valide, veuilliez saisir un chiffre" << endl;
		}	
	}		
}
