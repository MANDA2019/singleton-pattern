#include <iostream>
#include "include/VisitorCounter.h"
#include "include/NotificationManager.h"
#include "include/PrintQueue.h"

int main() {

    std::cout << "\n========================================\n";
    std::cout << "   DEMO : Design Pattern Singleton C++  \n";
    std::cout << "========================================\n\n";

    // --- EXEMPLE 1 : VisitorCounter ---
    std::cout << "--- [1] Compteur de Visiteurs ---\n";
    auto* counter = VisitorCounter::getInstance();
    counter->visit("Accueil");
    counter->visit("Produits");
    counter->visit("Accueil");
    counter->visit("Contact");
    counter->printStats();
    counter->resetDaily();
    counter->visit("Accueil");
    counter->printStats();

    // Preuve : meme instance partout
    auto* counter2 = VisitorCounter::getInstance();
    std::cout << "Meme instance ? " << (counter == counter2 ? "OUI" : "NON") << "\n";

    // --- EXEMPLE 2 : NotificationManager ---
    std::cout << "\n--- [2] Gestionnaire de Notifications ---\n";
    auto* notif = NotificationManager::getInstance();
    notif->send("info",    "Bienvenue sur l'application !");
    notif->send("success", "Fichier sauvegarde avec succes.");
    notif->send("warning", "Espace disque faible (10% restant).");
    notif->send("error",   "Connexion au serveur echouee.");
    notif->printAll();
    notif->markAllRead();
    notif->printAll();

    // --- EXEMPLE 3 : PrintQueue ---
    std::cout << "\n--- [3] File d'attente d'impression ---\n";
    auto* printer = PrintQueue::getInstance();
    printer->addJob("Rapport_Q1.pdf",   "Alice");
    printer->addJob("CV_Martin.docx",   "Bob");
    printer->addJob("Facture_042.pdf",  "Alice");
    printer->addJob("Planning.xlsx",    "Charlie");
    printer->printStatus();
    printer->processNext();   // Imprime le premier
    printer->printStatus();
    printer->processAll();    // Imprime le reste
    printer->printStatus();

    std::cout << "\n========================================\n";
    std::cout << "         FIN DE LA DEMONSTRATION        \n";
    std::cout << "========================================\n";

    return 0;
}
