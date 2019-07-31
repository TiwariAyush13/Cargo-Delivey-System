for t in range(int(input())):
    n,m,k=map(int,input().split())
for i in range(k):
        x,y=map(int,input().split())
len(string)
a=[]
string.upper()
string.lower()
round(x/y)//returns rounded value
min()
sorted(array)
sum(array)//returns sum of elements
a.strip()//removes whitespaces
a.replace('old','new')
a.append(arg)
a.remove(arg)
a.clear()//removes elements
a.count()
 dct={}
 dct.keys()
 dct.values()
  dct[v]=1
   print(ans)
/*
1. Counter (from collections)

Syntax:

variable=list.Counter()

Working:

Creates a dictionary of elements with the frequency they have appeared in

the list

Ways to Access:

variable.keys()

variable.values()

variable.items()

variable[0]---------------this returns the freqency of the number zero

2. sorted()

syntax:

sorted(list,reverse=True/False)

3.max(list) and min(list)---returns maximum and minimum values in the list

4.len(list)---returns the lengths of the list

5.str(number)----converts the integer into a string

6. '*'.join(list)--------joins all the elements in a string with ‘*’ in the middle of

elements and forms the string

7. all()----returns true if all the conditions in the arguments are true(acts like AND

function in math

8.any()---returns true if any of the conditions mentioned in the arguments is true

acts like OR function in math

For more understanding of all() and any() functions

refer : Any and All // Lee On Coding // My blog about coding and stuff.

9. range(0,n,2)----used basically in for loop to create a list of numbers starting from 0 to n

The third argument is the step value which can be used to increment

the value by specific number.(in this case the numbers will be 0,2,4...n)

10. input()---To take input from the user

11. id()----returns object's memory address which can be used to check if two different variable are pointing to the same memory location

12. for i,j in list_1,list_2:

zip(i,j)	-------------------Create a list containing the values of the iterables

13. for i, (a, b) in enumerate(zip(alist, blist)):

print i, a, b--------------------result would be ---- 0 element1_a element1_b

14. set(list)--------------forms a set by deleting all the duplicate values present in
 the list.

Note:- but a set cannot be iterated just like list so in order to access it as

list use list(set) function or sorted(set)

15. bisect (from bisect)

bisect(list, num, beg, end) :- This function returns the position in the sorted list where the number passed in argument can be placed so as to maintain the resultant list in sorted order

bisect_left(list,num,beg,end):- 
works just like bisect but if elements repeat it gives the left most position at which the element needs to be inserted whereas bisect returns rightmost.

16. random

from random import *

randint(1,5)----output will be 2 or 3 or 4 or 5

Some Meathods of good use

1. list.index('abc')------------------returns the index value in which 'abc' occurs

2. dictionary.keys()

dictionary.values()

dictionary.items()
*/
