#! /usr/bin/python2.7

filename = raw_input(">> input file name: ")
infile = open(filename+".in", 'w')
outfile = open(filename+".exp", 'w')
a = []
while(1):
    try:
        a.append(int(raw_input()))
    except:
        break


infile.write(str(len(a))+'\n')

for i in a:
    infile.write(str(i)+"\n")

a.sort()

for i in a:
    outfile.write(str(i)+'\n')
