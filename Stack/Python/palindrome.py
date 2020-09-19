"""Program to check if the word provided is a palindrome
    Uses Stack 
"""

import sys
from Stack import Stack
from Errors import WordNotProvidedError

def main():
    if len(sys.argv) == 1:
        raise WordNotProvidedError()
    print("Good")

if __name__ == '__main__':
    try:
        main()
    except WordNotProvidedError:
        print("Please provide the word")