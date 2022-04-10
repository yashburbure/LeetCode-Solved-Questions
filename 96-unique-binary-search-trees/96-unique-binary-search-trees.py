class Solution:
    def numTrees(self, n: int) -> int:
        temp1=1
        temp2=1
        for i in range (2,(2*n)+1):
            temp1=temp1*i
            if(i==n):
                temp2=temp1
        ans=temp1/(temp2*temp2)
        ans/=(n+1)
        return int(ans)