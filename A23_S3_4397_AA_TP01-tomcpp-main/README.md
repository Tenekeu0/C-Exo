# TP 01 - MasterMind

**Les consignes sont sujets à modification. Reportez-vous à ce qui est communiqué durant le cours.**

## 1 - Directives

### 1.1 - Déroulement du TP

- La remise du travail doit être effectuée pour le 12 novembre 2023 à 23:59 avant minuit
- Le projet est réalisé en équipe de 2 personnes
- Vidéo de 5 minutes maximum illustrant la structure du code, l'algorithme de validation des biens/mal placés et le fonctionnement (i.e. démonstration) du jeu
- Les vidéos doivent être déposées sur Youtube avec une option de partage « non listée »
- Vous devez utiliser Git pour gérer vos sources
- La structure de votre répertoire racine doit suivre la structure donnée dans le dépôt Git
- Le code source doit être dans le répertoire « src » et suivre la structure d’un projet Visual Studio avec le gabarit C++
- Vous devez modifier un fichier AUTHORS.md contenant :
  - Le prénom, nom et numéro de matricule de chaque personne
  - Le lien de la vidéo sur Youtube
  - Le lien du dépôt GitHub
- La remise du travail doit être effectuée sur et à la date indiquée sur la plateforme d'enseignement
- Vous devez utiliser utiliser votre dépôt Git pour faire votre travail : si une situation particulière est détectée, vos commits moduleront votre note dans le groupe

### 1.2 - À remettre sur la plateforme d'enseignement Léa

- Votre code source
- Les liens YouTube de vos vidéos de présentation
- Le lien de votre dépôt Git

De manière plus simple, si vous avez suivi les directives de la section 1.1, vous n'avez qu'à remettre une version zippée de votre dépôt Git.

### 1.3 - Structure de la remise

- Vous devez remplir le fichier "AUTHORS.md". Il donne le nom et matricule des équipiers, les liens vers la vidéo de présentation et le dépôt Git
- Votre code source doit être dans le répertoire  ```src``` du présent dépôt Git
- Le répertoire source doit suivre la structure d'un projet Microsoft pour Visual Studio avec le gabarit C++ (Pas Make/CMAke)
- Vous devez fournir une vidéo de 5 minutes illustrant le circuit, le code et le fonctionnement
- Pour les vidéos :
  - Elles doivent être déposées sur Youtube avec une option de partage « non listée »
  - Leurs liens doivent être indiqués dans le fichier "AUTHORS.md"

### 1.4 - Évaluation

L'évaluation du travail est effectuée en se basant sur :

- L'historique de Git qui fait office de référence pour évaluer la proportion du travail effectué par chaque équipier

- La qualité et le contenu du code source :

  - Conformité du code et des normes d'écriture utilisées dans le cours
  - Fonctionnalité du code
  - Facilité de lecture du code
  - Modularité
  - Modèle objet
  - Paramétrisation du code
  - Utilisation de constantes
  - Utilisation de fichiers de configuration
  - etc.

- La qualité et le contenu de la présentation vidéo :

  - Vidéo
  - Audio
  - Explication orale
  - etc.

Tout partage de code, d'explication, de bouts de texte, etc. est considéré comme du plagiat. Pour plus de détails, consultez le site (et ses vidéos) [Sois intègre du Cégep de Sainte-Foy](http://csfoy.ca/soisintegre) ainsi que [l'article 6.1.12 de la PÉA](https://www.csfoy.ca/fileadmin/documents/notre_cegep/politiques_et_reglements/5.9_PolitiqueEvaluationApprentissages_2019.pdf). L'utilisation d'IA pour écrire le code est aussi considéré comme du plagiat.

## 2 - Description du projet

Le jeu du MasterMind se joue généralement à deux. Il consiste à choisir une combinaison de pions de couleur pour le premier joueur et à faire deviner cette combinaison au second joueur. Le second joueur doit deviner la combinaison en un nombre limité de coups. Pour chaque proposition, le premier joueur indique le nombre de pions de la bonne couleur bien placés et le nombre de pions de la bonne couleur mal placés. Le second joueur doit alors faire une nouvelle proposition en tenant compte de ces indications. Le jeu se termine lorsque le second joueur a trouvé la combinaison ou lorsque le nombre de coups maximum est atteint.

![Photo MasterMind](img/Mastermind.jpg)

(Crédit : [Wikipedia](https://fr.wikipedia.org/wiki/Mastermind))

### 2.1 - Fonctionnalités

- Le jeu doit être jouable à un ou deux joueurs
- Le jeu doit être jouable en mode texte (mode graphique pour les plus téméraires : 10% de bonus)
- Le/les joueur(s) doit/doivent pouvoir choisir le nombre de pions et le nombre de couleurs. Le nombre de couleurs est déterminé par une chaîne de caractères qui contient les couleurs disponibles. Par exemple, si la chaîne est "RGB", les couleurs disponibles sont le rouge, le vert et le bleu.
- En mode solo, l'ordinateur choisit la combinaison. Le joueur peut revenir en arrière pour corriger ses propositions (Triche)
- En mode deux joueurs, le premier joueur choisit la combinaison et le second joueur doit la deviner. Une fois trouvée ou lorsque le nombre de coups maximum est atteint le programme propose au deuxième joueur de choisir une nouvelle combinaison ou de quitter le jeu.
- Le score de chaque joueur est calculé en fonction du nombre de coups utilisés pour trouver la combinaison. Le score est affiché au fur et à mesure du jeu.
- Le score est calculé de la manière suivante : 10^(nombre de pions dans la combinaison)/(1.618^(nombre tentatives - 1)). Exemple pour une combinaison de 4 pions, 10000 points si trouvé en 1 coup, 6180 points si trouvé en 2 coups, 3820 points si trouvé en 3 coups, 2361 points si trouvé en 4 coups, etc.

### 2.2 - Déroulement du jeu

- Le jeu commence par demander le nombre de pions et les couleurs (une couleur par lettre) à utiliser pour la combinaison
- Le jeu demande le nombre de coups maximum. Ce nombre doit être supérieur ou égal à 1 et inférieur ou égal au nombre de coups qui fait descendre le score à 0.
- Le jeu demande ensuite le nombre de joueurs (1 ou 2)
- Si c'est un joueur, l'ordinateur choisit la combinaison et le joueur doit la deviner
- Si c'est deux joueurs, le premier joueur choisit la combinaison et le second joueur doit la deviner
- À chaque tentative, le joueur doit entrer une combinaison et le programme affiche le nombre de pions bien placés et le nombre de pions mal placés.
- Après chaque tentative, le programme affiche le score du joueur et propose d'afficher l'historique des coups joués dans la manche actuelle, de revenir en arrière d'un pas (cas un joueur - triche), de continuer ou de terminer la manche. (Triche dans le cas un joueur)
- Si la combinaison est trouvée ou que le joueur trouve la combinaison, le programme soit propose de rejouer (cas un joueur), soit invite le second joueur à choisir une nouvelle combinaison (cas deux joueurs), soit de quitter le jeu.

### 2.3 - Contraintes

- Le code doit être modulaire et utiliser la POO
- Le code doit utiliser une liste de combinaisons pour stocker l'historique des coups joués dans la manche actuelle. Cette liste doit utiliser un tableau dynamique tel que vu dans les exercices du cours et **donc votre implantation de liste**.
- L'algorithme de détermination du nombre de pions bien/mal placés doit être testé par des tests unitaires

### 2.4 - Exemple d'exécution

```console
Combien de pions ? 4
Quelles couleurs ? RVB
Combien de coups maximum ? 10
Combien de joueurs ? 1

Proposition 1 : RRRR
Bien placés : 1 - Mal placés : 0
Score : 0

Choix :
1 - Historique
2 - Revenir en arrière
3 - Continuer
4 - Terminer
Votre choix : 3

Proposition 2 : VVVV

Bien placés : 0 - Mal placés : 0
Score : 0

Choix :
1 - Historique
2 - Revenir en arrière
3 - Continuer
4 - Terminer
Votre choix : 3

Proposition 3 : BBBB

Bien placés : 3 - Mal placés : 0

Score : 0

Choix :
1 - Historique
2 - Revenir en arrière
3 - Continuer
4 - Terminer
Votre choix : 3

Proposition 4 : RBBB

Bien placés : 2 - Mal placés : 2

Score : 0

Choix :
1 - Historique
2 - Revenir en arrière
3 - Continuer
4 - Terminer
Votre choix : 3

Proposition 5 : BRBB

Bien placés : 4 - Mal placés : 0

Score : 1459

Choix :
1 - Nouvelle partie
2 - Quitter le programme
Votre choix : 2

Merci d'avoir utilisé le programme.
````

### 2.5 - Bonus

- Mode texte couleur pour afficher les couleurs connues de la combinaison de l'historique : 5%
- Mode graphique : 10% (Exemple : SDL, SFML, etc.)

### 3 - Résumé des points

Modulation de la note en fonction du travail effectué par chaque équipier : utilisation de GitInspector, analyse des commits, etc.

La note est aussi modulée en fonction de la qualité du code :

- Conformité du code et des normes d'écriture utilisées dans le cours (Globalement)
- Gestion mémoire (Globalement)
- Fonctionnalité du code (Par fonctionnalité)
- Complexité algorithmique (Par fonctionnalité)
- Validations des entrées (Par fonctionnalité)
- Validations des préconditions (Par fonctionnalité)
- Bon découpage du code (Globalement)

| Critère | Points |
| --- | --- |
| Explication vidéo | 15% |
| Menu / boucle de jeu | 10% |
| Choix du nombre de pions et des couleurs | 5% |
| Choix du nombre de coups maximum | 5% |
| Choix du nombre de joueurs | 5% |
| Choix de la combinaison | 5% |
| Affichage du nombre de pions bien/mal placés | 5% |
| Affichage du score | 5% |
| Affichage de l'historique | 5% |
| Historique + Revenir en arrière | 10% |
| Tests unitaires - nombre bien/mal placés| 10% |
| Note globale sur la remise | 20% |
| BONUS - Affichage couleur pour les couleurs connues | +5% |
| BONUS - Mode graphique | +10% |

Maximum : 100%.

## 4 - Références

- [MasterMind](https://fr.wikipedia.org/wiki/Mastermind)
- [C++ Reference](https://en.cppreference.com/w/)
