#!/usr/bin/env python3
# Use this code to optimize Python's input and output

from sys import stdin, stdout

input = stdin.readline
def print(*args):
  stdout.write(' '.join(map(str,args)) + '\n')

# Write your solution here
