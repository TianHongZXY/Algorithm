def all0(digits):
    for d in digits:
        if d > 0:
            return False
    return True

def addpa(string, digits):
    start = 0
    while (0 not in digits and digits):
        string.insert(0, '(')
        string.append(')')
        start += 1
        for i in range(len(digits)):
            digits[i] -= 1
    if all0(digits):
        return string
    else:
        idx0 = digits.index(0)
        return string[:start] + addpa(string[start:start+idx0], digits[:idx0]) + string[start+idx0:start+idx0+1] + addpa(string[start+idx0+1:len(string)-start], digits[idx0+1:]) + string[len(string)-start:]

if __name__ == '__main__':
    t = int(input())
    kase = 1
    while(t):
        t -= 1
        s = input()
        string = list(s)
        digits = [int(d) for d in string]
        res = addpa(string, digits)
        print("Case #%d: %s" %(kase, "".join(res)))
        kase += 1


