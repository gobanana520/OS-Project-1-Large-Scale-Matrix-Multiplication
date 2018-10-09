# /bin/sh

cc prog1.c -o prog1 > 1.txt

cc prog2.c -pthread -o prog2 > 2.txt

date

nohup ./prog1 > 1.txt

date

nohup ./prog2 > 2.txt

date
