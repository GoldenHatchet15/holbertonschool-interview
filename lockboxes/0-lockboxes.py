#!/usr/bin/python3
def canUnlockAll(boxes):
    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True
    keys = [0]  # Start with box 0 unlocked

    while keys:
        current_box = keys.pop()
        for key in boxes[current_box]:
            if key < n and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)

    return all(unlocked)