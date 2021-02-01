if __name__== "__main__":
    #run something
    Gateway =  [1, 2, 3, 4, 5, 6, 7, 8, 34, 35, 36]
    Real = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36]
    Gateway.sort()
    Real.sort()
    final = list(set(Real) - set(Gateway))
    final.sort()

    print ', '.join('{:02x}'.format(x) for x in (final))

