#!/usr/bin/python3
import sys

total_file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

def print_stats():
    """Prints the current statistics."""
    print("File size: {}".format(total_file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))

try:
    for line in sys.stdin:
        line_count += 1

        try:
            parts = line.split()
            ip, _, _, date, request, status_code, file_size = parts[0], parts[1], parts[2], parts[3], parts[4], parts[-2], parts[-1]

            # Update total file size
            total_file_size += int(file_size)

            # Update status code count
            if int(status_code) in status_codes:
                status_codes[int(status_code)] += 1

        except (ValueError, IndexError):
            # Skip lines that don't fit the expected format
            continue

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

print_stats()
