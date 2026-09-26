# p4rr0t
![P4rr0t](parrot.png)
A DLL process to self-kill management softwares

# How it works
Assuming I don't want to break anything: if I had created a simple C# application to kill a process, it would have required administrator privileges. With this method, however, we use an external program to inject a DLL that tricks Windows into thinking the program itself wants to terminate. As a first approach, let's try creating an intentional bug that uses int pointers (*) to crash the program. If this fails, it might be due to insufficient privileges. In this case, a second method involves having the program close itself from within, without triggering any exit errors.

# Exploits
First method: *Intentional int bug (666)* - 85cs/Itelcan3 (aka. @MasterSharp3210)

Second method: *Environment Exit* - 85cs/Itelcan3 (aka. @MasterSharp3210)

# Note
I'm working on a future exploit to bypass permission escalation and so inject DLLs into classmate programs that are executed with elevated privileges
