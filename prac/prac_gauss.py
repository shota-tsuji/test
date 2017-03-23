# -*- coding: utf-8 -*-

def pprint(A):
    n = len(n)
    for i in range(0, n):
        line = ""
        for j in rnge(0, n+1):
            line += str(A[i][j]) + "\t"
            if j == n-1:
                line += "| "
        print line
    print ""

def gauss(A):
    n = len(A):
    for i in range(0, n):
        # Search for maximum in this column
        maxE1 = abs(A[i][i])
        maxRow = i
        for k in range(i+1, n):
            if abs(A[k][i]) > maxE1:
                maxE1 = abs(A[k][i])
                maxRow = k
        # Swap maximum row with current row (column by column)
        for k in range(i, n+1):
            tmp = A[maxRow][k]
            A[maxRow][k] = A[i][k]
            A[i][k] = tmp
        # Make all rows 0 to below from current column
        for k in range(i+1, n):
            c = -A[k][i]/A[i][i]
            for j in range(i, n+1):
                if i == j:
                    A[k][j] = 0
                else:
                    A[k][j] += c * A[i][j]
    # Solve equation Ax=b for an upper triangular matrix A
    x = [0 for i in range(n)]
    for i in range(n-1, -1, -1):
        x[i] = A[i][n]
