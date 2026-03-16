# Singleton Pattern

## Description
Ce projet démontre l'implémentation du pattern Singleton en programmation orientée objet.

Le pattern Singleton garantit qu'une classe n'a qu'une seule instance et fournit un point d'accès global à cette instance.

## Caractéristiques
- ✅ Constructeur privé pour empêcher l'instanciation directe
- ✅ Méthode statique pour obtenir l'instance unique
- ✅ Thread-safe
- ✅ Lazy initialization (initialisation à la demande)

## Utilisation

```java
// Obtenir l'instance unique
Singleton instance = Singleton.getInstance();

// Toutes les références pointent vers la même instance
Singleton instance2 = Singleton.getInstance();
assert instance == instance2; // true
```

## Avantages
- Contrôle d'accès centralisé aux ressources partagées
- Économie de mémoire (une seule instance)
- Garantit l'unicité de l'instance

## Inconvénients
- Peut rendre le code plus difficile à tester (dépendance globale)
- Peut masquer les dépendances
- Peut créer des problèmes de concurrence

## Quand l'utiliser
- Gestionnaires de configuration
- Pools de connexions à une base de données
- Loggers
- Caches

## Contribuer
Les contributions sont bienvenues ! N'hésitez pas à ouvrir des issues ou des pull requests.

## Licence
MIT