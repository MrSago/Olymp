
from math import gcd
from fractions import Fraction

m = int(input())
n = int(input())
p = int(input())
q = int(input())

x1 = Fraction(m,n)
x2 = Fraction(p,q)

b = -(x1+x2)
c = x1*x2

if (b.denominator > 1 or c.denominator > 1):
    a = (b.denominator * c.denominator) // gcd(b.denominator, c.denominator)
    b *= a
    c *= a
else:
    a = 1

print (a, b.numerator, c.numerator)

