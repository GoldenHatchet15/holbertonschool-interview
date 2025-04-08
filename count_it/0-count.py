#!/usr/bin/python3
"""
Recursive function that queries the Reddit API, parses the titles
of all hot articles, and prints a sorted count of given keywords.
"""
import requests


def count_words(subreddit, word_list, word_count={}, after=None):
    headers = {'User-Agent': 'holbertonschool-countit'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after}

    try:
        response = requests.get(url, headers=headers, params=params, allow_redirects=False)
        if response.status_code != 200:
            return

        data = response.json().get('data')
        posts = data.get('children')
        after = data.get('after')

        # Normalize keywords
        word_list_lower = [word.lower() for word in word_list]
        for post in posts:
            title = post.get('data').get('title').lower().split()
            for keyword in word_list_lower:
                count = title.count(keyword)
                if count > 0:
                    if keyword in word_count:
                        word_count[keyword] += count
                    else:
                        word_count[keyword] = count

        # Recurse if more pages
        if after:
            count_words(subreddit, word_list, word_count, after)
        else:
            if not word_count:
                return
            # Sort by count descending, then alphabetically
            sorted_counts = sorted(word_count.items(), key=lambda item: (-item[1], item[0]))
            for word, count in sorted_counts:
                print(f"{word}: {count}")
    except Exception:
        return
