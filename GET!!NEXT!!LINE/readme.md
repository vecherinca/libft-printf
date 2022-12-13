# GNL

## prototype :
```c
char *get_next_line(int fd);
```
## regles :
- ### fonction qui lit une ligne d'un FD passe en param
- ### si on appelle G_N_L plusieurs fois avec un meme FD il lira chacune des lignes une par une jusqu'a la fin du FD
- ### lit sur l'entree standard comme sur un fichier
- ### doit toujours retourner le ``` \n ``` de fin  de ligne sauf dans le cas ou on est a la fin du fichier et qu'il ne contient pas de ```\n```

## how it works in my case :
Important thing to mention, that I use the calloc function that is why the gnltester is showing the timeout problem. I will see later if the moulinette accepts it or not.I have 5 five functions: get_next_line, init_stash, get_the_line, clean_stash and check_the_line. 
- The first thing to do is to decide which variable you are gonna make static.(The benefit of a static variable is that when you repeat the function for the second/third.. time the content of it does not change). In my case I chose to w
