
@echo off

g++ -O3 %1 -o %1.exe
if not %errorlevel% == 0 (
    echo Exit script
    exit
)

et -f %1.exe -w 5000 <cf.in >cf.out
fc cf.out cf.ok

