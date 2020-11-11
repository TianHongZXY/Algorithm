def print_(matrix):
    for i in range(len(matrix)):
        print(matrix[i])
    print('-' * 10)
    
def rotate(matrix) -> None:
    """
    目标顺时针转90度，即a_(i)(j) = a'(j)(N-i+1)
    先上下翻折a_(i)(j)=a'(N-i+1)(j)，再转置a_(i)(j)=a'(N-i+1)(j)=a''(j)(N-i+1)
    """
    matrix.reverse()
    print_(matrix)
    # print(matrix[::-1])
    # print(*matrix[::-1])
    matrix[::] = zip(*matrix)

if __name__ == "__main__":
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    print_(matrix)
    rotate(matrix)
    print_(matrix)
    
