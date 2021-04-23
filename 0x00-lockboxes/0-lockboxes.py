#!/usr/bin/python3
"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes"""

def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened.
    The first box boxes[0] is unlocked"""
    if (type(boxes) is not list):
        return False

    if (len(boxes) == 0):
        return False

    keys = [0]
    for i in keys:
        for j in boxes[i]:
            if j not in keys and j != i and j < len(boxes) and j != 0:
                keys.append(j)
    if len(keys) == len(boxes):
        return True

    return False        
