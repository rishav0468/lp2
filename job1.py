n =int(input('enter the no of jobs'))
job=[]
print ("enterid ,deadline ,profit")
for i in range(n):
    while True:
        job_input=input("job"+str(i+1)+" : ").split()
        if len (job_input)<3:
            print("plaese enter at least 3 input")
            continue
        break
    job.append(job_input)

sorter = lambda job: int(job[2])
job=sorted(job,key=sorter,reverse=True)

schulded=[]
time=0
for i in job:
    schulded.append(i[0])
    time+=1
    
print ("job are schduled are")
print (schulded)    
        
            
    
