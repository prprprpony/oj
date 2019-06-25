n=int(input())
r=range(n)
M=[input()for i in r]
print(sum((lambda x,y:0<min(x,y)<=max(x,y)<n-1 and len(set(['X',M[x][y],M[x-1][y-1],M[x-1][y+1],M[x+1][y-1],M[x+1][y+1]]))==1)(x,y)for x in r for y in r)) 
