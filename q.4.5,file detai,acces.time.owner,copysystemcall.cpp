 //Write a program to print file details including owner access permissions, file access time,
//where file name is given as argument
//Solution 4 :
  
import os
from stat import *
statinfo = os.stat('Downloads')
mode = statinfo.st_mode
if S_ISDIR(mode):
print("Directory")
elif S_ISREG(mode):
print("Regular File")
if (mode & S_IXUSR):
print("Executable User")
elif (mode & S_IWUSR):
print("Writable User")
elif (mode & S_IRUSR):
print("Readable User")
if (mode & S_IXOTH):
print("Executable Others")
elif (mode & S_IWOTH):
print("Writable Others")
elif (mode & S_IROTH):
print("Readable Others")
filePerm = filemode(mode)
print(f"File Permissions are {filePerm}")
print(f"File access time is {statinfo.st_atime}")

//Write a program to copy files using system calls.
//Solution 5 :
 
file1 = "file1.txt"
file2 = "file2.txt"
lines=" "
with open(file1,'r',encoding='utf8') as src:
lines = src.readlines()
with open(file2,'a',encoding='utf8') as dest :
dest.writelines(lines)
print(f"Content copied from {file1} to {file2}")




