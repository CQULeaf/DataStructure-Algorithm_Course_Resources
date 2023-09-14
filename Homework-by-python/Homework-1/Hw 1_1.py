def GCD(a,b):
    if b==0:
        return a
    else:
        return GCD(b,a%b)

def LCM(a,b):
    return a*b//GCD(a,b)

a,b=map(int,input().split())

gcd_result = GCD(a,b)
lcm_result = LCM(a,b)

print (f"{gcd_result},{lcm_result}")