//Question 1 :
//Write a program (using fork() and/or exec() commands) where parent and child execute:
//a) same program, same code.
//b) same program, different code.
//c) before terminating, the parent waits for the child to finish its task.
//Solution 1(a) :
 
 // a) same program, same code.
import os
pid = os.fork()
if pid < 0:
print("Fork failed")
quit()
print(f"p(Returned value of os.fork()) : {pid}")
print(f"Process id : {os.getpid()}")
 
//Solution 1(b) :
 
import os
pid = os.fork()
# p > 0 ---> Parent process
if pid > 0:
print(f"I am parent process. Actual process id : {os.getpid()} ")
print("Exiting the parent process")
# p == 0 ---> Child process
elif pid == 0:
print(f"I am child process. Actual process id : {os.getpid()}")
newCode = 'a = 10\nb=20\nprint("Sum =", a+b)'
exec(newCode)
else:
print("Forking Error")
quit()

//Solution 1(c) :
 
# c) before terminating, the parent waits for the child to finish its task.
import os
pid = os.fork()
# p > 0 ---> Parent process
if pid > 0:
print(f"I am parent process. Actual process id : {os.getpid()} ")
os.waitpid(-1, 0)
print("Exiting the parent process")
# p == 0 ---> Child process
elif pid == 0:
print(f"I am child process. Actual process id : {os.getpid()}")
print("Exiting the child process")
else:
print("Forking Error")
quit()

