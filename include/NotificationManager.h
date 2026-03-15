#pragma once
#include <string>
#include <vector>

// Exemple 2 : Gestionnaire de Notifications
// Toutes les notifications (erreurs, succes, alertes) passent
// par UN SEUL gestionnaire. Sans Singleton, deux modules
// pourraient afficher des notifications en meme temps
// et se chevaucher ou se perdre.
struct Notification {
    std::string type;    // "info", "success", "warning", "error"
    std::string message;
    bool read;
    Notification(const std::string& t, const std::string& m)
        : type(t), message(m), read(false) {}
};

class NotificationManager {
private:
    static NotificationManager* instance;
    std::vector<Notification> notifications;

    NotificationManager();
    NotificationManager(const NotificationManager&) = delete;
    NotificationManager& operator=(const NotificationManager&) = delete;

public:
    static NotificationManager* getInstance();
    void send(const std::string& type, const std::string& message);
    void markAllRead();
    int countUnread();
    void printAll();
};
