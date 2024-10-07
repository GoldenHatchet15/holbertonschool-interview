#!/usr/bin/python3
#!/usr/bin/python3
"""
Log parsing script.

Reads stdin line by line, extracts IP, status code, and file size,
and prints statistics every 10 lines or on keyboard interruption.

Metrics computed:
- Total file size
- Number of occurrences of each status code (200, 301, 400, 401, 403, 404, 405, 500)
"""

import sys

total_file_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0


""" Print the metrics. """
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
