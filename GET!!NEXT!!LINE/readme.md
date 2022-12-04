# GNL

## proto :
```c
char *get_next_line(int fd);
```
## regles :
- ### fonction qui lit une ligne d'un FD passe en param
- ### si on appelle G_N_L plusieurs fois avec un meme FD il lira chacune des lignes une par une jusqu'a la fin du FD
- ### lit sur l'entree standard comme sur un fichier
- ### doit toujours retourner le ``` \n ``` de fin  de ligne sauf dans le cas ou on est a la fin du fichier et qu'il ne contient pas de ```\n```

## doc :
- ## variable statique :
	- ### une variable declaree avec le mot cle ```static``` ne perdra pas sa valeur a la fin du programme celle ci  restera en memoire, elles sont stockes dans le segment de donnees leur duree de vie correspond a celle du programme et leur place en memoire ne peut pas etre libere

- ## File Descriptor :
	- ### int qui contient un index d'une entree d'un fichier ouvert dans une structure de donnee contenant tout les fichiers ouverts.
	- ### Trois descripteur de fichiers sont "reserves" 
		* 0 -> Entree standard
		* 1 -> Sortie standard
		* 2 -> Erreur standard

- ## fonction read
	- ### proto :
		```c
		ssize_t read(int fildes, void *buf, size_t nbyte);
		```
	- ### parcours un fichier defini par un FD
	- ### stock les charactere passe dans un buffer (chaine de char)
	- ### nombre de char a stock dans le buffer

# VIDEO EXPLICATIVE DE LA MISE EN APPLICATION : https://youtu.be/-Mt2FdJjVno