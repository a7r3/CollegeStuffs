# Prime number print
for i in range (2,100):
    for j in range (2,100):
        f=0;
        if j%i==0:
            f=1
        if f==1:
            print i
            break;
