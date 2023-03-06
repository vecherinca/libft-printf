# Push-swap algorithm for the 100/100 score 👩🏼‍💻
**Hello, hello!** 

**This is the PUSH SWAP tutorial that is optimized enough and easy to understand.\
Important note: This algorithm is used by everyone in school but not documented anywhere(at least it's not on the top of the google search), that is why I decided to do it by myself. Shout out to *Yassine(ychibani) and Louis (lmarchai)* for the patient explanations.**\
![Alt Text](https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif)

So, let's start.\
First, I am gonna cover easy cases - 3 and 5 random numbers.
## Sorting 3 numbers 
3 numbers sorting is the easiest case in this whole project.\
Here we have 5 main cases to cover, you can see them on a image, that I took from [this very cool article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) .
- If one is greater than two, but less than three, and if two is less than three, we swap the first two elements(**sa**).
- If one is greater than both two and three, and two is greater than three, we swap(**sa**) the first two elements, then reverse rotate(**rra**) them.
- If one is greater than both two and three, but two is less than three, we rotate the elements one time(**ra**).
- If one is less than both two and three, and two is greater than three, we swap(**sa**) the first two elements and then rotate them one time(**ra**).
- If one is less than two, but greater than three, and two is greater than three, we reverse rotate the element one time(**rra**).
![This is an image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*D0U1zQFQnkI4Q_Z0QPi69g.png)

## Sorting 5 numbers

