# Minitalk

## Description

Minitalk est un projet qui consiste à créer un système de communication entre deux processus en utilisant des signaux Unix. Le programme est divisé en deux parties : un serveur qui reçoit des messages et un client qui envoie des chaînes de caractères, bit par bit, en utilisant les signaux SIGUSR1 et SIGUSR2.

L’objectif est de comprendre et manipuler les signaux Unix pour établir une communication simple sans utiliser de socket ou de pipe.

## Fonctionnalités

- Le serveur affiche les messages reçus sur la sortie standard.
- Le client envoie des chaînes de caractères au serveur via des signaux.
- Transmission bit à bit des caractères ASCII.
- Gestion des erreurs et des signaux inattendus.

## Compilation

Pour compiler le projet, utilisez la commande suivante :

```bash
make
```

Cela générera deux exécutables : `server` et `client`.

## Utilisation

### Lancer le serveur

Exécutez le serveur pour obtenir son PID :

```bash
./server
```

Le PID du serveur sera affiché sur la console.

### Envoyer un message

Avec le PID du serveur, utilisez le client pour envoyer un message :

```bash
./client <PID_SERVEUR> "Votre message ici"
```

Exemple :

```bash
./client 12345 "Hello, Minitalk!"
```

Le serveur affichera :

```
Hello, Minitalk!
```

## Gestion des erreurs

- Vérification des arguments.
- Vérification de la validité du PID.
- Gestion des signaux interrompus.

## Ressources utiles

- `man 2 kill`
- `man 7 signal`
- `man 2 getpid`
