for i in range(1,50):
    for j in range(i+1,50):
        for k in range(j+1,50):
            if i*i+j*j==k*k:
                print(i,j,k)
                continue
                
