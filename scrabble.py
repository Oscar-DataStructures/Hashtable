"""
Austin Burgess, Oscar Martinez
CS 271
Dr. Lall
Project 6
"""

def readFile(fileName):
    open(fileName, "r")
    print(file.read())
import math

def hash(k):
    knum = 0         # ensure we have a number here
    for letter in k:
      knum = knum + ord(letter) - 96
    m = 8191                    # big prime number
    A = (math.sqrt(5) - 1) / 2  # Knuth

    return (m * (knum * A // 1)) // 1000

def main():
    readFile("scrabble.txt")

main()
