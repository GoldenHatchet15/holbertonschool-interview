#!/usr/bin/python3
"""Reads from stdin and computes metrics."""
import sys

total_file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0


def print_stats():
    """Print the metrics."""
    print("File size: {}".format(total_file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()
        try:
            file_size = int(parts[-1])
            status_code = int(parts[-2])
            total_file_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1
        except (ValueError, IndexError):
            # Skip the line if there's a formatting issue
            continue

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise
