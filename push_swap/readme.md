# Push-swap algorithm for the 100/100 score 👩🏼‍💻
**Hello, hello!** 
**This is the PUSH SWAP tutorial that is optimized enough and easy to understand.\
Important note: This algorithm is used by everyone in school but not documented anywhere(at least it's not on the top of the google search), that is why I decided to do it by myself. Shout out to *Yassine(ychibani) and Louis (lmarchai)* for the patient explanations.**\
![Alt Text](https://media.tenor.com/XSdY1YWJzowAAAAC/jess-new-girl-new-girl-jess.gif)


So, let's start.
### **First, I am gonna cover easy cases - 3 and 5 random numbers.**
## ❗️Sorting 3 numbers
3 numbers sorting is the easiest case in this whole project.\
Here we have 5 main conditions to cover, you can see them on a image, that I took from [this very cool article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a):
Here we consider that **one** is the first number, **two** is the second and **three** - is oubviosly the third. 

- If one is greater than two, but less than three, and if two is less than three, we swap the first two elements(**sa**).
- If one is greater than both two and three, and two is greater than three, we swap(**sa**) the first two elements, then reverse rotate(**rra**) them.
- If one is greater than both two and three, but two is less than three, we rotate the elements one time(**ra**).
- If one is less than both two and three, and two is greater than three, we swap(**sa**) the first two elements and then rotate them one time(**ra**).
- If one is less than two, but greater than three, and two is greater than three, we reverse rotate the element one time(**rra**).
![This is an image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*D0U1zQFQnkI4Q_Z0QPi69g.png)

Voilà! We are done we with the first sorting case. 

## ❗️Sorting 5 numbers
The sorting of 5 numbers is also a very easy case. And having the algo for the three numbers will a be a great benefit here.\
**What should be done:**
- First, in the **stack A** we need to find the smallest element. Once it is found, it needs to be pushed to the top of the **stack A**. 
- Now when we have the smallest element on the top, it(*smallest element*) should be pushed to stack B.
- Then, we repeat the same thing with the second smallest element. We are finding it -> pushing it to the top -> pushing to the **stack B**.
- Now we have two smallest numbers in a stack B and three values in **stack A**. 
- So now we sort 3 numbers in a **stack A** with the algo for the three numbers and after than we execute two times the command push to list a (**pa**).\
Now, our list of 5 numbers is succesfully sorted.\
Important note: when pushing the minumum node to the top of the list it's important that the position of the node is considered. If the smallest number is more that **size of a list/2** the we do the **rra**, if it's less - the **ra** is implemented. 

## ❗️Sorting 100-500 numbers

Now, the most interesting part. *Push-swap itself*. We can divide it in four parts: **Pre-sort, Finding the most efficient node to move, Moving the most efficient node and pushing the zero-node to the top.**

Before the algorithm implementation, one important step must be done. 

### Indexation

The idea behind indexation is that we need to assign indexes(lol, what a surprise) to every node we in a list A, before pushing it to a list B. In this case it is will be easier to visualize it. 

|Actual number    | Index |
| ----------- | ----------- |
| 3           |2        |
|5            | 4       |
|4            | 3       |
|2            | 1       |
|1            | 0       |
|6            | 5       |

The node structure should be look like this. For every node we have an **int** value that is an actual number and **int** value for an assigned index. 

![This is an image](https://i.pinimg.com/originals/85/36/9f/85369f81ccd5b961c490f045809a21c5.png)

In terms of code the structure of a linked list that I used has this form.

```c
typedef struct t_a_list
{
	int				content;
	int				index;
	struct t_a_list	*next;
}	t_a_list;

```

When the indexation part is done and ready, we can start to implement the algorithm. Hoooray :)


## Pre-sort by using median
❗️***NB: From this point we are working only with the indexes and not the actual values.***

The first part of this push-swap algorithm is very very easy understand. At this point what we need to do is to push all our numbers from list A to list B in a certain manner by using the median.

Step by step what must be done: 

- Finding the median of the **list A**.
- Finding the maximum node of the **list A**. (at this point all our values are in list A) 
- After identifying maximum and the median, we need to loop through the whole list and compare every node to a median. If it's bigger than a median we first push the node to a **list B** and then execute the rotate function(**ra**). If it's less than a median we only do the push to be function(**pa**). **Important notion: while sending nodes to the list B, we need to keep track on a maximum and not to push it to the List B.**

### So after the pre-sort is done we have list A with one maximum node and pre-sorted **list B** that looks like this: the big numbers are on the top and small numbers are on the bottom of the list. 

![An image](https://i.pinimg.com/originals/0d/ea/12/0dea125082397ea72882aaf1a16a46c6.png)

## Finding the most efficient node to move

After the pre-sort we can start the search for the most efficient node. But first I need to explain the sorting concept. 

### ✨✨✨ The concept ✨✨✨✨
![gif with the concept](https://gfycat.com/unfoldedsmugkentrosaurus)
