#!/usr/bin/python3
"""
A Python script that reads from stdin line by line, parses HTTP logs,
and prints statistics (total file size and status codes count).

The script handles the following:
- Valid log lines with IP address, date, request, status code, and file size.
- Prints statistics every 10 lines or upon receiving a keyboard interruption (CTRL+C).
- Handles errors like malformed lines or empty input.
"""

import sys

size = [0]  # Using a list to allow modification inside a function
codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

def check_match(line):
    """Parses a line and updates the file size and status codes."""
    try:
        line = line.strip()
        words = line.split(" ")
        size[0] += int(words[-1])
        code = int(words[-2])
        if code in codes:
            codes[code] += 1
    except (ValueError, IndexError):
        # Ignore malformed lines
        pass

def print_stats():
    """Prints the current accumulated statistics."""
    print("File size: {}".format(size[0]))
    for code in sorted(codes.keys()):
        if codes[code]:
            print("{}: {}".format(code, codes[code]))

i = 1
try:
    for line in sys.stdin:
        check_match(line)
        if i % 10 == 0:
            print_stats()
        i += 1
except KeyboardInterrupt:
    print_stats()
    sys.exit(0)

# Print remaining stats after input is finished
print_stats()
