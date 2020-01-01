import math
x=int(input())

def is_prime(y):
    if y==1: return False
    
    for i in range(2,int(math.sqrt(y))+1):
        if y % i == 0:
            return False
    
    return True

while not is_prime(x):
    x=x+1

print(x)
