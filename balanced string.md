given a String, find the longest substring which is balanced, return the length. balanced string means every character in the string has its upper case and lower case

for example
“AAAaaa” 6
  'acABaabca' 5
  'TacoAC' 0
  'TAAAacoCat'  2
```python
# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(string):
    n = len(string)
    if n < 2:
        return 0
    res = 0
    for subLen in range(2, n):
        for offset in range(n-subLen):
            strSet = set(string[offset:subLen+offset])
            checkList = [c.upper() in strSet and c.lower() in strSet for c in strSet]
            if all(checkList):
                res = max(res, subLen)
    return res
    
print(solution('acABaabca'))
```