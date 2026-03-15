#pragma once
#include <string>

// Exemple 1 : Compteur de Visiteurs
// Sur un site web, toutes les pages partagent le MEME compteur.
// Si chaque page creait sa propre instance, chacune aurait
// son propre compteur -> le total serait faux.
class VisitorCounter {
private:
    static VisitorCounter* instance;
    int total;
    int todayCount;

    VisitorCounter();
    VisitorCounter(const VisitorCounter&) = delete;
    VisitorCounter& operator=(const VisitorCounter&) = delete;

public:
    static VisitorCounter* getInstance();
    void visit(const std::string& pageName);
    void resetDaily();
    void printStats();
};
