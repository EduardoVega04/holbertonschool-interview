#!/usr/bin/python3
"""Calculate how many square units of water will be retained after it rains"""


def rain(walls):
    """Return: Integer indicating total amount of rainwater retained"""
    totalWater = leftWall = distance = 0
    for wall in walls:
        if wall != 0 and leftWall == 0:
            leftWall = wall
        elif wall == 0 and leftWall != 0:
            distance += 1
        else:
            if wall >= leftWall:
                totalWater += distance * leftWall
            else:
                totalWater += distance * wall
            leftWall = wall
            distance = 0

    return totalWater
