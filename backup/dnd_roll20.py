#!/bin/python3
import random

att_list = ["Str","Dex","Con","Int","Wis","Cha"]

for i in range(6):
    randnum = random.randint(8,19)
    outstr = att_list[i]+": "+str(randnum)
    print(outstr)
