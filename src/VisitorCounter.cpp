#include "../include/VisitorCounter.h"
#include <iostream>

VisitorCounter* VisitorCounter::instance = nullptr;

VisitorCounter* VisitorCounter::getInstance() {
    if (instance == nullptr)
        instance = new VisitorCounter();
    return instance;
}

VisitorCounter::VisitorCounter() : total(0), todayCount(0) {
    std::cout << "[VisitorCounter] Instance unique creee.\n";
}

void VisitorCounter::visit(const std::string& pageName) {
    total++;
    todayCount++;
    std::cout << "[Visite] Page : '" << pageName
              << "' | Total : " << total << "\n";
}

void VisitorCounter::resetDaily() {
    todayCount = 0;
    std::cout << "[VisitorCounter] Compteur journalier remis a zero.\n";
}

void VisitorCounter::printStats() {
    std::cout << "\n=== Statistiques Visiteurs ===\n";
    std::cout << "  Total general : " << total << "\n";
    std::cout << "  Aujourd'hui   : " << todayCount << "\n";
}
