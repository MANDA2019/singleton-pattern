#pragma once
#include <string>
#include <queue>

// Exemple 3 : File d'attente d'impression
// Plusieurs applications envoient des documents a imprimer.
// Une seule file centrale garantit que les documents
// s'impriment dans l'ordre, sans se melanger.
// Avec plusieurs instances, deux documents pourraient
// s'imprimer en meme temps -> sortie illisible.
struct PrintJob {
    int id;
    std::string document;
    std::string sender;
    PrintJob(int i, const std::string& d, const std::string& s)
        : id(i), document(d), sender(s) {}
};

class PrintQueue {
private:
    static PrintQueue* instance;
    std::queue<PrintJob> jobs;
    int nextId;

    PrintQueue();
    PrintQueue(const PrintQueue&) = delete;
    PrintQueue& operator=(const PrintQueue&) = delete;

public:
    static PrintQueue* getInstance();
    void addJob(const std::string& document, const std::string& sender);
    void processNext();
    void processAll();
    void printStatus();
};
