def fac(n):
    if n==1:
        return 1
    else:
        return n*fac(n-1)

def my_power(num, pow_):
    if pow_ == 0:
        return 1
    else:
        return num*my_power(num,pow_-1)

depth=0
def fibonacci(num):
    global depth
    depth+=1
    print("Depth ->",depth)
    if num <2:
        return num
    else:
        return fibonacci(num-2)+fibonacci(num-1)

def inverse_input():
    word = input()
    if word != '\n':
        inverse_input()
        print(word)

# print(fac(5))
# print(my_power(2,7))
# inverse_input()
print(fibonacci(10))