# Push Swap

## Description

**Push Swap** est un projet de l'école 42 qui consiste à implémenter un algorithme de tri efficace en utilisant deux piles (`a` et `b`). Le but est de trier une pile `a` dans l'ordre croissant à l'aide de certaines opérations spécifiques sur les piles. Le projet a pour objectif de comprendre les algorithmes de tri, l'optimisation de leur complexité, et la manipulation de structures de données.

## Fonctionnalités

- Trier une pile de nombres à l'aide des opérations suivantes :
  - **sa** : Échanger les deux premiers éléments de la pile `a`.
  - **sb** : Échanger les deux premiers éléments de la pile `b`.
  - **ss** : Effectuer `sa` et `sb` en même temps.
  - **pa** : Pousser le premier élément de la pile `b` vers la pile `a`.
  - **pb** : Pousser le premier élément de la pile `a` vers la pile `b`.
  - **ra** : Faire tourner la pile `a` vers le haut (décalage des éléments vers le haut).
  - **rb** : Faire tourner la pile `b` vers le haut.
  - **rr** : Effectuer `ra` et `rb` en même temps.
  - **rra** : Faire tourner la pile `a` vers le bas (décalage des éléments vers le bas).
  - **rrb** : Faire tourner la pile `b` vers le bas.
  - **rrr** : Effectuer `rra` et `rrb` en même temps.

- Implémenter un algorithme de tri optimal, avec un nombre minimal d'opérations.
