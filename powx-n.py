class Solution:
    def pow(self, x, n):
        if n == 0:
            return 1
        if n < 0:
           x = 1/x
        n = abs(n)
        div = n % 2
        if div != 0:
            return x*self.pow(x*x, n // 2)
        else:
            return self.pow(x*x, n //2)
    def myPow(self, x: float, n: int) -> float:
        return self.pow(x,n)