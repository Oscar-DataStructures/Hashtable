# -*- coding: utf-8 -*-
import math
import matplotlib.pyplot as pyplot

def hash(k):
  knum = 0         # ensure we have a number here
  for letter in k:
    knum = knum + int.from_bytes(letter.encode(), "little")
  m = 3079	                   # big prime number
  A = (math.sqrt(5) - 1) / 2   # Knuth

  return abs(( m * (knum * A) // 1)) % 1000

def min(list):
    min = list[0]
    for i in range(0, len(list) - 1):
        if list[i] < min:
            min = list[i]
            
    return min

def max(list):
    max = list[0]
    for i in range(0, len(list) - 1):
        if list[i] > max:
            max = list[i]
            
    return max

def stdDev(data):
    n = len(data)
    mean = sum(data) / n
    total = 0
    for x in data:
        total += (x - mean) ** 2
    return math.sqrt(total / n)


def readFile(fileName):
  file = open(fileName, "r")
  text = file.read()
  file.close()
  hashedList = []

  word = ""
  wordList = []
  for letter in text:
    if letter != " ":
      word = word + letter
    else:
      hashedList.append(hash(word))
      word = ""

  return hashedList, wordList
        

def main():
  hashedList, wordList = readFile("scrabble.txt")
  print("Min = " + str(min(hashedList)) + "\n")
  print("Max = " + str(max(hashedList)) + "\n")
  print("Standard Deviation = " + str(stdDev(hashedList)) + "\n")
  pyplot.hist(hashedList, bins = 50)
  pyplot.show()

main()

