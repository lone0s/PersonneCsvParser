//
// Created by ohno on 9/20/2022.
//

#ifndef TP2_NOTE_PERSONNE_H
#define TP2_NOTE_PERSONNE_H


#include <string>
#include <vector>

class Personne {
    int id;
    std::string nom;
    std::string prenom;
public:
    Personne(int idPers, const std::string& prenomPers = "", const std::string& nomPers = "Smith");
    int getId() const ;
    void serialize(const std::string& filename) const;
    static std::vector<Personne> unserialize(const std::string& filename);
    static std::vector<Personne> trieur(std::vector<Personne> list);
};


#endif //TP2_NOTE_PERSONNE_H
