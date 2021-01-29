#!/usr/bin/python3
"""Reads stdin line by line and computes metrics
   Input format: <IP Address> - [<date>]
   "GET /projects/260 HTTP/1.1" <status code> <file size>\n"""

from sys import stdin

lines_read = 0
status_codes_list = [200, 301, 400, 401, 403, 404, 405, 500]
lines_by_statusCode = {}
file_size = 0

for code in status_codes_list:
    lines_by_statusCode[code] = 0

try:
    for line in stdin:
        lines_read += 1
        input_split = line.split()
        file_size += int(input_split[-1])
        lines_by_statusCode[int(input_split[-2])] += 1

        if lines_read == 10:
            print("File size: {:d}".format(file_size))
            for code in status_codes_list:
                if lines_by_statusCode[code] is not 0:
                    print("{:d}: {:d}".format(code, lines_by_statusCode[code]))
                    lines_by_statusCode[code] = 0
            lines_read = 0
except KeyboardInterrupt:
    print("File size: {:d}".format(file_size))
    for code in status_codes_list:
        if lines_by_statusCode[code] is not 0:
            print("{:d}: {:d}".format(code, lines_by_statusCode[code]))
            lines_by_statusCode[code] = 0
