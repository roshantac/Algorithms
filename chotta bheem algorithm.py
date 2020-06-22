
global n
n=5
global x
x=[]
global y
y=[]
global finlX
finlX=[]
global finlY
finlY=[]
global count
count=0
def mazeSolver(i,j):
    global count
    maze =[[0,1,0,0,0],
            [0,0,0,1,0],
            [1,0,1,0,0],
            [0,0,0,1,1],
            [0,1,0,0,0]]
    global n
    global x
    global y
    if((i== (n-1)) and (j== (n-1))):
       x.append(n-1)
       y.append(n-1)
       nextEpoch()
    if(count>(n*n)):
       count=0
       return
    if((i>=0)and(j>=0) and (i<n)and(j<n)and (maze[i][j]==0)and (count<50)):
       count=count+1
       x.append(i) 
       y.append(j)
       mazeSolver(i+1,j)  #down
       mazeSolver(i,j+1)  #right
       mazeSolver(i-1,j)  #up
       mazeSolver(i,j-1)  #left
    count =0
    return 0
       
def nextEpoch():
    global x
    global y
    global finlX
    global finlY
    if(len(finlX)>len(x)):
        finlX=x
        finlY=y
        x.clear()
        y.clear()

#try:
mazeSolver(0,0)
#except:
#    print("hello")
print(finlX)
print(finlY)

