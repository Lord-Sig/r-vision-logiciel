/*
 * trucpourrev.cpp
 *
 *  Created on: 7 juil. 2018
 *      Author: totod
 */

#include "trucpourrev.h"
#include <fstream>;
#include <iostream>
#include <vector>
#include "list";
using namespace std;

/**
 *
 */
int main()
{
	cout << "Bonjours est bienvenue dans mon programme de révision"<<"\n"<<"Nous rappelons que le programme n est pas fournit avec les question"<< endl; // ligne du message d'acueil
	choixaction();
	return 0;
}
void choixaction(){
	int entreuser = 0;
	cout <<"Menu des action"<<"\n"<< "Ecrit 1 pour ajouté une question/reponse" <<"\n"<<"Ecrit 2 pour lancé un exercice"<<"\n"<<endl;// cette ligne annonce les diférentes action du menu
	cin >> entreuser;
	if (entreuser == 1){
		entreuser = 0;

		writequestionanswer();
	}
	else if (entreuser == 2){
		entreuser = 0;

	}

}

void exodequestion(){
	int conteur = 0;
	string question;
	string reponse;
	string questionL;
	string reponseL;
	ifstream questionFlux("question.txt");  //Ouverture d'un fichier en lecture
	ifstream reponseFlux("reponse.txt");

	if(questionFlux )
	{
		while(getline(questionFlux,question)) //Tant qu'on n'est pas à la fin, on lit
		      {
			conteur+=1;
				getline(reponseFlux,reponse);
				questionL += question;
				questionL += "\t";
				reponseL +=reponse;
				reponseL +="\t";
		      }

	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture  ou fichier inexistant" << endl;
	}
}
/**
 *
 */
void writequestionanswer()
{
	string question;
	string reponse;
		cout << "entré la question"<<endl;
		cin >> question;
		cout <<"entré la réponse" << endl;
		cin >> reponse;
	ofstream questionFlux("question.txt", ios::app); // on ouvre le ficher d'écriture
	ofstream reponseFlux("reponse.txt", ios::app);
	questionFlux << question << endl;
	reponseFlux << reponse <<endl;
	choixaction();

}
