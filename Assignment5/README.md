# Files
There are 3 C files, the names are descriptive.

# Dining philosophers
For classical implementation and explation see variation 2 and ignore saucebowls completely.

## Variation 1 -- 1 adjacent fork needed, any 1 out of 4 bowls needed
1. Deadlock maybe possible when a philosopher takes a bowl and another takes a fork but both of them wait for each other to relinquish. To resolve the deadlock, just sequentialize it. Or, put a counting semaphore on the sauce bowls.

## Variation 2 -- both adjacent forks needed, any 1 out of 4 bowls needed
1. Deadlock possible during fork selection. i.e. same as the description in the given pdf. (Each philosopher takes their left fork only and wait eternally to get the right one//same with right fork).
2. Deadlock resolution: 
    - For any philosopher `i`, try to acquire both forks
    - if failed, then set a semaphore to avoid exiting the `takefork` function.
    - if passed eat and exit the `takefork` function
    - Now, for another philospher `j` (not the same as `i`) repeat the same steps. It is guaranteed that there will always be 2 such philosophers who would be able to eat (pigeonhole + 5 forks). Now, bias those philosophers to relinquish a fork to only the *RIGHT* philosopher (implemented in the `put_fork` function). This guarantees that the `takefork` function for some `i` will always exit.
    - Saucebowl? Use counting semaphore wait and post directives to control allocation
    - crisis averted.
