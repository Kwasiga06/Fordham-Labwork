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

###############################
# MY FUNCTIONS
###############################

def SortedCheck(a):
   """
   Checks if the list is sorted in descending order.
   Returns True if sorted in descending order.
   """
   for i in range(1, len(a)):
      if a[i] > a[i - 1]:
         return False
   return True

def CheckDuplicate_Sorted(a):
   """
   Checks if a sorted list has any duplicate elements.
   Returns True if there are duplicates.
   """
   for i in range(1, len(a)):
      if a[i] == a[i - 1]:
         return True
   return False


def CheckDUplicate_Unsorted(a):
   """
   Checks if an unsorted list has any duplicates.
   Returns True if there are duplicates.
   """
   for i in range(len(a) - 1):
      for j in range(i + 1, len(a)):
         if a[i] == a[j]:
            return True
   return False

def isPalindrome(word):
   """
   Checks if the string 'word' is a palindrome using slicing (coding pattern #4).
   Returns True if palindrome.
   """
   return word == word[::-1]


###############################
# TESTS FOR EACH FUNCTION
###############################

# SORTED CHECK 
print("Testing SortedCheck:")
print(SortedCheck([10, 9, 8, 7, 6]))
print(SortedCheck([1, 2, 3, 4, 5]))
print(SortedCheck([5, 5, 3, 1]))
print(SortedCheck([10]))
print(SortedCheck([])) 

# Test with random list
rand0list = RandomList(5)
print(f"Random list: {rand0list}")
print("Is sorted descending?", SortedCheck(rand0list))

# DUPLICATE SORTED
print("\nTesting CheckDuplicate_Sorted:")
print(CheckDuplicate_Sorted([9, 7, 7, 3, 1]))
print(CheckDuplicate_Sorted([5, 4, 3, 2, 1]))
print(CheckDuplicate_Sorted([5, 5, 5, 5]))
print(CheckDuplicate_Sorted([10]))  
print(CheckDuplicate_Sorted([]))


# DUPLICATE UNSORTED
print("\nTesting CheckDUplicate_Unsorted:")
print(CheckDUplicate_Unsorted([1, 2, 3, 4, 5]))
print(CheckDUplicate_Unsorted([1, 2, 3, 2, 5]))
print(CheckDUplicate_Unsorted([5, 5, 5, 5]))
print(CheckDUplicate_Unsorted([10]))  
print(CheckDUplicate_Unsorted([])) 

# Test with random list
rand0list2 = RandomList(8)
print(f"Random list: {rand0list2}")
print("Has duplicates?", CheckDUplicate_Unsorted(rand0list2))

# PALINDROME
print("\nTesting isPalindrome:")
print(isPalindrome('Welcome'))
print(isPalindrome('kayak'))  
print(isPalindrome('racecar'))
print(isPalindrome('a'))
print(isPalindrome('')) 
print(isPalindrome('madam'))  
print(isPalindrome('python')) 

