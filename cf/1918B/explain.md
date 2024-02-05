# While sorting the first array, the inversion number decrese. 

eg: 

x x x 1 x x x 
x x x d x x x

1 in 4th position. After moving 1 to the 1st place. The inversion number
decresase by 3. 

While d move to the first place, the inversion number increase by 3 at most.  


# Why it's the minimun? 
A swap with near element

+2/0/-2

for example: 
from 1 2 3 4 5 6 -> 4 2 6 3 1 5

idea: Using swap operation to make sure that the last element is the right
element, 
note like each iteration the inversion number increase 0 or +2, because we move
small element to right (bigger than itself).  

1 2 3 4 5 6     move (5) 
-> 1 2 3 4 6 5  move (1) 
-> 2 3 4 6 1 5  move (3) 
-> 2 4 6 3 1 5  move (6) 
-> 4 2 6 3 1 5  move (2)
-> 4 2 6 3 1 5  move (4)

