# Python List

# Lists are used to store multiple items in a single variable.
# Lists are one of 4 built-in data types in Python used to store collections of data, 
# the other 3 are Tuple, Set, and Dictionary, all with different qualities and usage.
# Lists are created using square brackets:

thislist = ["apple", "banana", "cherry"]
print(thislist)


## List Items

# List items are ordered, changeable, and allow duplicate values.
# List items are indexed, the first item has index [0], the second item has index [1] etc.

## Ordered
# When we say that lists are ordered, it means that the items have a defined order, and that order will not change.
# If you add new items to a list, the new items will be placed at the end of the list.

## Changeable
# The list is changeable, meaning that we can change, add, and remove items in a list after it has been created.

## Allow Duplicates
# Since lists are indexed, lists can have items with the same value:
thislist = ["apple", "banana", "cherry", "apple", "cherry"]
print(thislist)


# To determine how many items a list has, use the len() function:
thislist = ["apple", "banana", "cherry"]
print(len(thislist))

## List Items - Data Types
# List items can be of any data type:

list1 = ["apple", "banana", "cherry"]
list2 = [1, 5, 7, 9, 3]
list3 = [True, False, False]

## A list can contain different data types:

list1 = ["abc", 34, True, 40, "male"]
# This list with strings, integers and boolean values:


## The list() Constructor
# It is also possible to use the list() constructor when creating a new list.
thislist = list(("apple", "banana", "cherry")) # note the double round-brackets
print(thislist)
# Here we used list() constructor to create a list


## Python Collections (Arrays)
# There are four collection data types in the Python programming language:

# List is a collection which is ordered and changeable. Allows duplicate members.
# Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
# Set is a collection which is unordered, unchangeable*, and unindexed. No duplicate members.
# Dictionary is a collection which is ordered** and changeable. No duplicate members.

## Access Items
# List items are indexed and you can access them by referring to the index number:
thislist = ["apple", "banana", "cherry"]
print(thislist[1])
# it will print the 2nd item "banana".


## Negative Indexing
# Negative indexing means start from the end
# -1 refers to the last item, -2 refers to the second last item etc.

thislist = ["apple", "banana", "cherry"]
print(thislist[-1])
# It will print the last item of the list.


## Range of Indexes
# You can specify a range of indexes by specifying where to start and where to end the range.
# When specifying a range, the return value will be a new list with the specified items.
 
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[2:5])
# It will Return the third, fourth, and fifth item.


thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[:4])
# This example returns the items from the beginning to, but NOT including, "kiwi":


thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[2:])
# This example returns the items from "cherry" to the end:

## Check if Item Exists
# To determine if a specified item is present in a list use the in keyword:
thislist = ["apple", "banana", "cherry"]
if "apple" in thislist:
    print("Yes, 'apple' is in the fruits list")

# This will print "Yes 'apple is present in the list


## Change Item Value
# To change the value of a specific item, refer to the index number:

thislist = ["apple", "banana", "cherry"]
thislist[1] = "blackcurrant"
print(thislist)


## To insert a new list item, without replacing any of the existing values, we can use the insert() method.
# The insert() method inserts an item at the specified index:

thislist = ["apple", "banana", "cherry"]
thislist.insert(2, "watermelon")
print(thislist)
# This will add the watermelon at position 2.


## Append Items
# To add an item to the end of the list, use the append() method:

thislist = ["apple", "banana", "cherry"]
thislist.append("orange")
print(thislist)
# This will add the "Orange" at the last index


## Remove Specified Item
# The remove() method removes the specified item.
thislist = ["apple", "banana", "cherry"]
thislist.remove("banana")
print(thislist)


## Removing item from specified position
thislist = ["apple", "banana", "cherry"]
thislist.pop(1)
print(thislist)
# This will remove the banana