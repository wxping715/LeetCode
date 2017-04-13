# 记k的最高次幂为m，从上界 int(log(n)) 向下界 1 递减枚举m

# 问题转化为计算1 + k + k^2 + ... + k^m = n的正整数解

# 由n > k^m得： k < n ** 1/m

# 由n < (k + 1)^m得： k > n ** 1/m - 1，此处使用了二项式定理

# 因此k可能的解为：int(n ** 1/m)

# 最后验证1 + k + k^2 + ... + k^m 是否等于 n
class Solution(object):
    
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        n = int(n)
        max_m = int(math.log(n,2))
        
        for m in xrange(max_m, 1, -1):
            k = int(n ** m ** -1)
            if (1 - k**(m+1)) // (1-k) == n:
                return str(k)
        return str(n-1)
        
