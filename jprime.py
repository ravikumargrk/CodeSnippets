# If num>1:
#     for i in range(2, num): 
#          if num%i ==0:
#               return "false" 
#               break 
#           else: 
#                return "true"
# else: 
        # return "false"
def isPrime(num):
    if (num > 1):
        for i in range(2, num):
            if (num%i==0):
                return False
            else:
                return True
    else:
        return False
        
test_nums = [0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]
result = [isPrime(num) for num in test_nums]
print("value\tisPrime(value)")
for i in range(0, len(test_nums)):
    print(str(test_nums[i]) + "\t" + str(isPrime(test_nums[i])))
