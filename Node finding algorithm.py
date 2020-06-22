

import sys

class VulnarableNodes():
	def __init__(self):
		self.array=self.getData()
		self.swap()

	
	def checkPath(self,x,y,skip):
		if self.directPath(x,y,skip)==True:
			return True
		if self.InDirectPath(x,y,skip)==True:
			return True
		return False

	
	def directPath(self,x,y,skip):
		for i in range(0,len(self.array)):
			if(not((self.array[i][0] == skip) and (self.array[i][1] == skip))):
				if ((x==self.array[i][0]) and (y==self.array[i][1])):
					return True
		return False


	def InDirectPath(self,x,y,skip):
		if(x==y):
			return True
		for i in range(0,len(self.array)):
			if(not((self.array[i][0] == skip) or (self.array[i][1] == skip))):
				if(x == self.array[i][0]):
					return self.InDirectPath(self.array[i][1],y,skip)
				if(x==self.array[i][1]):
					return self.InDirectPath(self.array[i][0],y,skip)
		return False

	def MostVulnarable(self):
		mat=[]
		if(len(self.array)==0):
			print("Invalid data")
			return
		if(len(self.array)==1):
			print("no most Vulnarable Nodes")
		for i in range(self.minArray(),self.maxArray()+1):
			count=0
			for j in range(self.minArray(),self.maxArray()+1):
				for k in range(self.minArray(),self.maxArray()+1):
					if((i!=j) and (j<k) and( i!=k)):
						if (self.checkPath(j,k,i)==False):
							count=count+1
			mat.append([i,count])
		self.maxEntry(mat)

	def maxEntry(self,mat):
		max=mat[0][0]
		for i in range(0,len(mat)):
				if max<mat[i][1]:
					max=mat[i][1]
		resultmat=[]
		for i in range(0,len(mat)):
			if mat[i][1]==max:
				resultmat.append(mat[i])
		for i in range(0,len(resultmat)):
			print("RSU#"+str(resultmat[i][0]))


	def minArray(self):
		min=self.array[0][0]
		for i in range(0,len(self.array)):
			for k in range(0,len(self.array[i])):
				if min>self.array[i][k]:
					min=self.array[i][k]
		return min

	def maxArray(self):
		max=self.array[0][0]
		for i in range(0,len(self.array)):
			for k in range(0,len(self.array[i])):
				if max<self.array[i][k]:
					max=self.array[i][k]
		return max

	def getData(self):
		with open(sys.argv[1],'r') as f:
			 data = f.read().replace('\n', '')
		import re
		array = re.findall(r'[0-9]+', data) 
		p=[]
		try:
			l=len(array)
		except:
			print("Invalid data")
			exit(0)
		if((l%2)!=0):
			return 
		for i in range(2,l,2):
			p.append([int(array[i]),int(array[i+1])])
		return p
	def swap(self):
		for i in range(len(self.array)):
			if(self.array[i][0]>self.array[i][1]):
				temp= self.array[i][0]
				self.array[i][0]=self.array[i][1]
				self.array[i][1]=temp




k=VulnarableNodes()
k.MostVulnarable()
