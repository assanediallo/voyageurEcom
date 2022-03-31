# voyageurEcom

Le problème du voyageur de commerce est un problème d’optimisation combinatoire qui consiste à trouver la meilleure solution parmi un ensemble de choix possible: pour un nombre de villes n, on cherche à trouver le chemin le plus court passant une fois et une seule par chacune des villes. Ceci s’apparente, par exemple, à un livreur voulant optimiser le temps passé pour livrer tous ses colis ou à l’optimisation de l’ordre de déplacement d’une fraiseuse sur une ligne de production.

Ce problème est notoirement connu pour avoir une complexité augmentant très rapidement avec le nombre de points considérés : ainsi pour 10 points, on dépasse déjà les 3 millions de chemins possibles… Pour un grand nombre de point, obtenir une résolution exacte de ce problème devient donc très compliqué et demande de faire appel à des algorithmes d’optimisation.Dans ce projet, on propose de programmer deux algorithmes permettant la résolution exacte du problème du voyageur de commerce et d’en comparer les forces et les faiblesses

1) La méthode Brute Force
Cette méthode consiste simplement à trouver et calculer le coût de tous les chemins possibles, puis à sélectionner la meilleure option.
A faire pour générer les points:
• Une fonction générant un nombre N de points (N petit ici <8) avec un positionnement aléatoire.
• Une fonction calculant et enregistrant en mémoires les distances entre les différents points. (On peut supposer dans un premier temps que chaque point est relié à       tous les autres et que la distances entre deux points est la même que l’on aille de A à B ou de B à A). Pour réaliser cet algorithme on peut utiliser :
• Une fonction récursive calculant toute les combinaisons de points possibles et une fonction calculant le cout de chaque chemin trouvé.
• Ou bien mixer les deux et faire une seule fonction récursive calculant les couts en même temps que les chemins sont générés.
  
2) La méthode Branch and Bound
La méthode branch and bound est une méthode top down de résolution exacte. Le principe des cet algorithme est d’orienter la recherche de la solution optimale en explorant en priorité les chemins dont les couts sont les plus faibles. La méthode de résolutions est plus simple que dans le cas précédant : on part du point de départ, ici 1, et on calcule les coûts reliant ce point à tous les autres. On choisit d’explorer le nœud dont le coût est le plus faible. On recommence la procédure pour ce nouveau nœud. Ainsi, pour chaque nœud sélectionné, l’algorithme doit calculer les coûts de tous les sous-nœuds, enregistrer ces coûts en mémoire et sélectionner le nœud ayant le coût minimal parmi tous les nœuds déjà calculés (attention, cela signifie qu’on peut remonter une branche si un nœud plus avantageux se présente plus haut dans l’arbre).
