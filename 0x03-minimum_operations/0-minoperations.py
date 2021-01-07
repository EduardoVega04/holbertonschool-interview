#!/usr/bin/python3
"""
Determine the minimum operations performed by
a text editor to result in exactly n 'H' characters.
Only 2 operations are supported: 'Copy all' and 'Paste'.
In the text file, there is initially a single character 'H'
"""


def prime_or_not(n):
    """Determine if n is prime or not
    - Divide n from n / 2 to 2
    - If there is a divisor, return False (n is not prime)
    - If there is not a divisor, return True (n is prime)"""
    for i in range(n // 2, 1, -1):
        if n % i == 0:
            return False
    return True

def minOperations(n):
    """The main function. Returns integer"""
    if type(n) != int or n <= 1:
        return 0
    for i in range(n // 2, 1, -1):
        if n % i == 0:
            if prime_or_not(i) == True:
                return i + (n // i)
    return n