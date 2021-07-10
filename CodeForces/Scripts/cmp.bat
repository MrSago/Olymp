
@echo off

g++ -O3 %1 -o %~n1.exe
if not %errorlevel% == 0 (
    echo Exiting the script
    exit
)

et -f %~n1.exe -w 5000 <cf.in >cf.out
if not %errorlevel% == 0 (
    echo Exiting the script
    exit
)

fc cf.out cf.ok

