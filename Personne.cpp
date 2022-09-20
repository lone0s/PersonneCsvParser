//
// Created by ohno on 9/20/2022.
//

#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>
#include <sstream>
#include "Personne.h"

using namespace std;

Personne::Personne(int idPers, const string &prenomPers, const string &nomPers) {
    if (idPers >= 0) {
        id = idPers;
        nom = nomPers;
        prenom = prenomPers;
        cout << "Successfully created " << nom << " " << prenom << endl;
    }
    else
        cerr << "Couldn't create "<< nomPers << " " << prenomPers << endl;
}

void Personne::serialize(const std::string &filename) const {
    ofstream outputStr (filename, ofstream::app);
    outputStr << id << "," << nom << "," << prenom << endl;
    outputStr.close();
}

vector<Personne> Personne::unserialize(const std::string &filename) {
    vector<Personne> res;
    ifstream ifs(filename);
    int nbElems = 0;
    if (ifs.good()) {
        while (!ifs.eof()) {
            string line;
            getline(ifs, line);
            if (!line.empty()) {
//                replace(line.begin(), line.end(), ',', ' ');
                stringstream strStream(line);
                vector<string> words;
                string cell;
                while(std::getline(strStream,cell, ',')) {
                    words.push_back(cell);
                }
                if (words.size() == 3) {
                    res.push_back(*new Personne(stoi(words[0]), words[1], words[2]));
                } else if (words.size() == 2) {
                    res.push_back(*new Personne(stoi(words[0]), words[1]));
                }
                nbElems++;
            }
            else
                cerr << "Incorrect number of elements in a line, couldn't extract line " << nbElems+1 << endl;
        }
        cout << "Successfully extracted " << nbElems << " individuals !" << endl;
    } else
        cerr << "Couldn't open file" << endl;
    return res;
}

int Personne::getId() const {
    return id;
}

std::vector<Personne> Personne::trieur(std::vector<Personne> list) {
    for(int i = 0; i < list . size(); i++) {
        for (int j = 0 ; j < list . size() - i -1; j++) {
            if (list[j] . id > list[j+1] .id) {
                swap(list[j],list[j+1]);
            }
        }
    }
    return list;
}
