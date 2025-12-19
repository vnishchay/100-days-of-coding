from collections import defaultdict
from bisect import bisect_right

class TimeMap:

    def __init__(self):
        # key -> list of (timestamp, value) sorted by timestamp
        self.mp = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        # timestamps for each key are strictly increasing, so append keeps list sorted
        self.mp[key].append((timestamp, value))  # O(1) [web:444][web:465]

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp:
            return ""

        arr = self.mp[key]  # [(ts, val), ...] sorted by ts
        # binary search for rightmost (ts <= timestamp)
        # trick: search for (timestamp, chr(127)) to use tuple ordering directly [web:444]
        i = bisect_left(arr, (timestamp, chr(127))) - 1

        if i < 0:
            return ""
        return arr[i][1]
