// CSV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "contact.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Permet d'afficher le contenu du fichier
	ifstream infile;
	infile.open("projet_CPP.csv");
	string line;
	while (infile >> line) {
		cout << line << endl;
	}
	infile.close();


	ofstream outfile;
	outfile.open("projet_CPP.csv", ios::app);

	string response;
	cout << "Que voulez vous faire ? (1. Ajouter, 2. Modifier, 3. Supprimer)" << endl;
	cin >> response;
	if (response == "1") {
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

		contact c1(nom, prenom, age, telephone);
		outfile << c1.makeCSV() << endl;
	}
	else if (response == "2") {
		cout << "Quelle contacte voulez vous modifier ?" << endl;

	}
	else if (response == "3") {
		cout << "Quelle contacte voulez vous supprimer ?" << endl;
		cin >> response;

	}
	else {
		cout << "Ce n'est pas un choix valide, veuilliez saisir un chiffre" << endl;
	}

	outfile.close();
}

