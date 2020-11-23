if __name__ == '__main__':
    T = int(input())
    kase = 1
    while(T):
        T -= 1
        length = 0
        candi = ""
        possible = True
        n = int(input())
        for i in range(n):
            line = input()
            line = line[1:]
            if(candi in line or line in candi):
                if(len(line) > length):
                    length = len(line)
                    candi = line
            else:
                possible = False
        print("Case #%d: " % (kase), end="")
        kase += 1
        if(possible): print(candi)
        else: print("*")

