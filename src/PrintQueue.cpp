#include "../include/PrintQueue.h"
#include <iostream>

PrintQueue* PrintQueue::instance = nullptr;

PrintQueue* PrintQueue::getInstance() {
    if (instance == nullptr)
        instance = new PrintQueue();
    return instance;
}

PrintQueue::PrintQueue() : nextId(1) {
    std::cout << "[PrintQueue] Instance unique creee.\n";
}

void PrintQueue::addJob(const std::string& document, const std::string& sender) {
    jobs.emplace(nextId++, document, sender);
    std::cout << "[Imprimante] Job #" << (nextId - 1)
              << " ajoute : '" << document
              << "' (envoye par " << sender << ")\n";
}

void PrintQueue::processNext() {
    if (jobs.empty()) {
        std::cout << "[Imprimante] File vide, rien a imprimer.\n";
        return;
    }
    PrintJob job = jobs.front();
    jobs.pop();
    std::cout << "[Imprimante] Impression du job #" << job.id
              << " : '" << job.document
              << "' de " << job.sender << " ... OK\n";
}

void PrintQueue::processAll() {
    std::cout << "[Imprimante] Traitement de tous les jobs...\n";
    while (!jobs.empty()) processNext();
}

void PrintQueue::printStatus() {
    std::cout << "\n=== File d'impression ===\n";
    std::cout << "  Jobs en attente : " << jobs.size() << "\n";
}
