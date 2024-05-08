n = int(input("Enter number of jobs: "))
jobs = []

print("Enter ID, deadline, and profit respectively for each job:")
for i in range(n):
    while True:
        job_input = input("Job " + str(i+1) + ": ").split()
        if len(job_input) < 3:
            print("Each job must have at least three elements: ID, deadline, and profit.")
            continue
        break
    jobs.append(job_input)
    
sorter = lambda job: int(job[2]) 

# def sorter(job):
#     return int(job[2])


jobs = sorted(jobs, key=sorter, reverse=True)

scheduled = []
time = 0

for i in jobs:
    
        scheduled.append(i[0])
        time += 1

print("Jobs are scheduled as: ")
print(scheduled)









# Enter number of jobs: 5
# Enter ID, deadline, and profit respectively for each job:
# Job 1: A 2 100
# Job 2: B 1 50
# Job 3: C 2 200
# Job 4: D 1 150
# Job 5: E 3 300





# Jobs are scheduled as: 
# ['E', 'C', 'D', 'A', 'B']



