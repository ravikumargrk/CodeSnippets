# Write the function matrixMultiply(m1, m2) that takes two 2d lists 
# (that we will consider to be matrices) and returns a new 2d list that 
# is the result of multiplying the two matrices. Return None if the 
# two matrices cannot be multiplied for any reason.

import numpy
def fun_matrixmultiply(m1, m2):
    # check if they are matrices
    width = len(m1[1])
    for sub_array in m1:
        if len(sub_array) != width:
            return None
    width = len(m2[1])
    for sub_array in m2:
        if len(sub_array) != width:
            return None
    # check if they can be multiplied
    if len(m1[1])!=len(m2):
        return None
    # mulitply
    m3 = numpy.dot(m1,m2) 
    # m3 is a numpy array
    # return list! not numpy array 
    return m3.tolist() #this will





