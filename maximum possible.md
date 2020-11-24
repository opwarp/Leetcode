Write a function that returns the maximum possible value obtained by inserting one '5' digit inside the decimal representation of integer N.

examples:
input: 1234 -> output: 51234
input: 7643 -> output 76543
input: 0 -> output 50
input: -661 -> output -5661
```python
# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(num):
    res = ""
    nStr = str(num)
    if nStr[0] == '-':
        for (i, c) in enumerate(nStr):
            if '5' <= c:
                return nStr[:i] + '5' + nStr[i:]
    else:
        for (i, c) in enumerate(nStr):
            if '5' >= c:
                return nStr[:i] + '5' + nStr[i:]
    return res
    
print(solution(-12467))
```