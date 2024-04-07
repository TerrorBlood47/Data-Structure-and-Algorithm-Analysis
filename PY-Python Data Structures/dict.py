"""
dictionary = a collection of {key : value} pair -- ordered and changeable, No Duplicate 

*** also called HashMap, map , HashTable ***
""" 

capitals = {
    "France": "Paris",
    "Germany": "Berlin",
    "United States": "Washington D.C.",
    "Japan": "Tokyo",
    "Brazil": "Brasília"
}

#get the value for a key
#print(capitals.get("France")) #returns None if item does not exist
print(capitals)

# capitals.update({"China" : "Beijing"}) #inserts new pair if it does not exist
# capitals.update({"Brazil" : "Rio Di Jeniro"})

# keys = capitals.keys()

# print(capitals)
# print(keys)

# for key in capitals.keys():
#     print(key)

# values = capitals.values()
# print(values)

items = capitals.items()
print(items)

for key, value in capitals.items():
    print(f"{key} : {value}")



#print(dir(capitals))
#print(help(capitals))

