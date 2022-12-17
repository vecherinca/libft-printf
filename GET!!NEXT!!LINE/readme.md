# GNL

## prototype :
```c
char *get_next_line(int fd);
```
## regles :
- fonction qui lit une ligne d'un FD passe en param
- si on appelle G_N_L plusieurs fois avec un meme FD il lira chacune des lignes une par une jusqu'a la fin du FD
- lit sur l'entree standard comme sur un fichier
-  doit toujours retourner le ``` \n ``` de fin  de ligne sauf dans le cas ou on est a la fin du fichier et qu'il ne contient pas de ```\n```

## how it works in my case :
Important thing to mention, that I use the calloc function that is why the gnltester is showing the timeout problem. I will see later if the moulinette accepts it or not(It is! All the way team calloc and bad optimization). I have 6 five functions: get_next_line, init_stash, get_the_line, clean_stash and check_the_line, ft_do_ze_line. 
- The first thing to do is to decide which variable you are gonna make static.(The benefit of a static variable is that when you repeat the function for the second/third.. time and the content of it does not change). In my case I chose to work with the static buffer because it seemed right and my friend Louis told me to try this way. So in general, it was very random decision, listen to you heart here lol. 
- First think I do is initialize the stash. The idea is that our stash == the content of a buffer. If it's our first appel of a function we also initialise buffer because we need something to read from. 
- After initialising the stash I start the loop with all the reading part. The condition that I use in a while loop: ```c bytes != 0 && check_the_line(buffer[fd]) != 1) || bytes == -1```. When bytes == 0 it means that we are at the end of the string and there is nothing to read so it seems logical to end the loop. The function check_the_line checks if there '\n' or not. If there is one it means that we reached our line and we can stop the loop. if bytes = -1 it means that problem has occured. 
- After all this work we can do our read. ```bytes = read(fd, buffer[fd], BUFFER_SIZE);``` It's our second read here. It is important to mention that before that we already initialized the stash. I'll make a little example. Imagine we have a line like this: ``` For the most part, feminist theory has assumed that there is some ``` and our buffer size is 5. So at this point out stash is: ``` For t ``` and then we did the second read of a buffer, so out buffer is ```he mo```.  Applying this logic we are in loop till we meet '\0' or '\n'. 
- After quitting the loop the stash will be filled with the given line **and** in many cases with the rest of bytes that we read. For example, our final stash can look like this ``` For the most part, feminist theory has assumed that there is some'\n'existing ```. That is why the line should be executed and the stash must be cleaned. 
- That is why I created two functions: get_the_line and clean_stash. 
- The get_the_line function callocs the new line and after that assigns all the content till '\0' or '\n' to it. 
