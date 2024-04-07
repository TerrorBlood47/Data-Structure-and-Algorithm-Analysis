#collection -> single variable used  to store multiple values
#   List  = [] ordered, changeable, Duplicates OK
#   Set   = {} unordered, immutable ,but ADD/REMOVE OK (set is mutable, but the
#              elements contained within it are immutable),  No Duplicates
#   Tuples= () ordered, unchangeable/immutable, Duplicates OK, FASTER

# 'ordered' means objects can be accessed with indexing

"""
### List

fruits = ["apple", "banana", "orange", "lemon"]

# print every 2nd element
print(fruits[::2])

# every 2nd element in backwards
print(fruits[::-2])

# every 2nd element starting from 2nd position
print(fruits[1::2])

#determine if an element is in the list
print("orange" in fruits)
print("coconut" in fruits)
print("meth" not in fruits)

#iterate over the elements
for fruit in fruits:
    print(fruit)


#get the list of functions that are allowed with the data structure
print(dir(fruits))

#get the detailed description of all the attributes/methods of the data structure
print(help(fruits))

"""

### Set

"""
fruits = {"apple", "banana", "oranges", "lemon"}

print(fruits)


#same as before
print(dir(fruits))
print(help(fruits))

# print(fruits[1]) # indexing not possible -> unordered

"""

### Note : all of the DSs can contain values of multiple datatypes

objs = [9 ,  "nothing", None, 'c']    #perfectly fine .... except in the case of sorting 

print(objs)

#objs.sort() #not supported

objs.reverse()

print(objs)

### another way to traverse
for index, item in enumerate(objs):
    print(index , " " , item)


### No need to use TUPLE