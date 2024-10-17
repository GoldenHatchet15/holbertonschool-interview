#!/usr/bin/python3
#!/usr/bin/python3
"""
A Python script that reads from stdin line by line, parses HTTP logs,
and prints statistics (total file size and status codes count).
"""


import sys

codes = {}
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count = 0
size = 0

try:
    for ln in sys.stdin:
        if not ln.strip():
            continue  # Ignore empty input

        if count == 10:
            print("File size: {}".format(size))
            for key in sorted(codes):
                print("{}: {}".format(key, codes[key]))
            count = 1
        else:
            count += 1

        ln = ln.split()

        try:
            size += int(ln[-1])
        except (IndexError, ValueError):
            pass

        try:
            if ln[-2] in status_codes:
                if codes.get(ln[-2], -1) == -1:
                    codes[ln[-2]] = 1
                else:
                    codes[ln[-2]] += 1
        except IndexError:
            pass

    # Print remaining stats after all lines are processed
    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))

except KeyboardInterrupt:
    # Handle Ctrl+C interruption and print the current stats
    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))
    raise
