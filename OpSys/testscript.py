import sys
import random
file = open('pytest.txt','w+')
print int(sys.argv[1])
items = range(1,int(sys.argv[1]))
random.shuffle(items)
print items
file.seek(0)
for i in range (1,int(sys.argv[1])):
    x = items.pop()
    file.write(str(random.randint(1000,9999))+ ', '+
        str(random.randint(0,10))+ ', ' +str(random.randint(1,25))
        + ', ' + str(x) + '\n')
