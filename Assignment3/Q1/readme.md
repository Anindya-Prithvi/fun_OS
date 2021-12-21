# Vruntime manipulation

## Logic | RB and timeline
Make a new variable in `sched_entity` representing delay in nano seconds. Use that delay in `update_curr` while updating vruntime. Also double the value. Why? Property of a red black, max depth shall be less than double. Since the timeline is based on vruntime, it'll try to push the task at the end. Everytime a balancer ticks, it'll force the process to wait.

## Logic | Syscall and logging
The syscall takes in a pid (that's taken using getpid in userland) and the delay in ms. Then I put an rcu_lock for read safety and find which `task_struct` has the given pid. Then, the delay variable of that task is set to the given argument (along the syscall).
Also, based on the nice values of this task, I have traversed all the available task and set their delay to 1 NANOSECOND (i.e. insignificant and will be ignored since it's less than `sched_latency`). Finally, since whenever a process is scheduled the `update_curr` method is called, I have put a small logic to check if that `sched_entity` has a delay... If so, print the `exec_start` as required by the quesiton.


## How to run
1. compile the tester.c
2. patch the kernel source with the supplied patch
3. install and boot the kernel
4. run the compiled file with a specific nice value (or not...your wish)
5. Finally, view kernel logs (dmesg)