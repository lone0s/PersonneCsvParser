#include <iostream>
#include "Personne.h"

int main() {
//    Personne a(12,"Omar","Ben");
//    Personne b(15, "Quentin", "Borali");
//    Personne c(555,"Test","Extraction");
//    a.serialize(R"(E:\ohno\Documents\C++\TPs\TP2_Note\test.txt)");
//    b.serialize(R"(E:\ohno\Documents\C++\TPs\TP2_Note\test.txt)");
    std::vector<Personne> test = Personne::unserialize("E:\\ohno\\Documents\\C++\\TPs\\TP2_Note\\test.txt");
    for(int i = 0 ; i < test.size() ; i++) {
        std::cout << test[i] . getId() << std::endl;
    }
    std::cout << "---------------\n";
    std::vector<Personne> trie = Personne::trieur(test);
    for(int i = 0 ; i < trie.size() ; i++) {
        std::cout << trie[i] . getId() << std::endl;
    }
}
