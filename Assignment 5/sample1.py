# a really good syntax checker can ignore parenthesis or brackets in comments as well

# this program has CORRECT syntax, the checker should not find any issues here.

mylist = [(1,2),(3,4),(5,6)]
for i in range(len(mylist)):
    print(mylist[i])

x = []
while(len(x) < 3):
    x.append(mylist[0])
    print(x)

d = {}

for i in range(len(mylist)):
    d[mylist[i][0]] = mylist[i][1]

d = dict(sorted(d.items()))
print(d)
