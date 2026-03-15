#include "../include/NotificationManager.h"
#include <iostream>

NotificationManager* NotificationManager::instance = nullptr;

NotificationManager* NotificationManager::getInstance() {
    if (instance == nullptr)
        instance = new NotificationManager();
    return instance;
}

NotificationManager::NotificationManager() {
    std::cout << "[NotificationManager] Instance unique creee.\n";
}

void NotificationManager::send(const std::string& type, const std::string& message) {
    notifications.emplace_back(type, message);
    std::cout << "[" << type << "] " << message << "\n";
}

void NotificationManager::markAllRead() {
    for (auto& n : notifications) n.read = true;
    std::cout << "[Notifications] Toutes marquees comme lues.\n";
}

int NotificationManager::countUnread() {
    int count = 0;
    for (auto& n : notifications) if (!n.read) count++;
    return count;
}

void NotificationManager::printAll() {
    std::cout << "\n=== Notifications ===\n";
    for (auto& n : notifications) {
        std::cout << "  [" << n.type << "] "
                  << n.message
                  << (n.read ? " (lu)" : " (non lu)") << "\n";
    }
    std::cout << "  Non lues : " << countUnread() << "\n";
}
