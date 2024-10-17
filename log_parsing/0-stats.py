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

# Initialize required variables
codes = {}
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count = 0
size = 0

def print_stats():
    """Prints the file size and status code statistics"""
    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))

try:
    for ln in sys.stdin:
        if not ln.strip():
            continue  # Skip empty lines

        ln = ln.split()

        try:
            # Attempt to process the file size
            size += int(ln[-1])

            # Attempt to update status code counts
            if ln[-2] in status_codes:
                codes[ln[-2]] = codes.get(ln[-2], 0) + 1
        except (IndexError, ValueError):
            continue  # Skip malformed lines

        count += 1
        if count == 10:
            print_stats()
            count = 0

    # After finishing input, print remaining stats
    print_stats()

except KeyboardInterrupt:
    # Handle CTRL+C by printing current stats before exiting
    print_stats()
    raise
