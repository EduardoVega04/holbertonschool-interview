#!/usr/bin/python3
"""
Determine the minimum operations performed by
a text editor to result in exactly n 'H' characters.
Only 2 operations are supported: 'Copy all' and 'Paste'.
In the text file, there is initially a single character 'H'
"""


def minOperations(n):
    if type(n) != int or n < 0:
        return 0

    res = 0
    i = 2
    while i <= n:
        if n % i == 0:
            res += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(res)
