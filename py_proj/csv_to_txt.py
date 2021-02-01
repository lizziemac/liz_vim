import csv
import os

def to_txts(c):
    with open(c, 'r') as f:
        reader = csv.reader(f)
        rownumber = 0
        for row in reader:
            if rownumber == 0:
                path = row[0]+"_"+row[1]
                os.mkdir(path)
            g = open(path+"/"+row[3]+".txt","w")
            g.write(str(row))
            rownumber = rownumber + 1
            g.close()
    return path

def iterate_files(dir):
    for filename in os.listdir(dir):
        if filename.endswith(".txt"):
            print(os.path.join(dir, filename))
    print dir

directory = to_txts('test.csv')
iterate_files(directory)