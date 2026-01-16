import math
import random

# Generate a list of random numbers between 1 and 100
def RandomList(len): 
   a=[]
   # generate len number of  random numbers and put them in list a 
   for i in range(len):
      # Generate a random integer between 1 and 100 (inclusive)
      random_int = random.randint(1, 100)
      a.append (random_int)
   return a


# Find smallest element in a list
# @param a: a list
# @return largest value stored in a 
# For example, if a[0…4]=[25,3, 7, 100]
#     
def Smallest (a, first=0, last=None): 
    if last==None:
       last = len(a)-1

    smallest=math.inf
    for i in range(first, last+1):
      if a[i]<smallest:
         smallest = a[i]

    return smallest 


l=[-30,1,2,10,-1,-20]
a=Smallest(l)
print(a)

b=Smallest(l,3)
print(b)

b=Smallest(l,3,4)
print(b)

a=RandomList(10);
print(a)
