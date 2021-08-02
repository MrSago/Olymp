
@echo off

if ["%~1"] == [""] (
    echo Arguments not found. Exiting the script.
    exit
)

set warnings=-pedantic -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond
g++ -static -Wl,-stack=268435456 -O2 -std=c++17 %warnings% -g %1 -o %~n1.exe
if %errorlevel% NEQ 0 (
    echo Compile error. Exiting the script.
    exit
)

et -f %~n1.exe -w 5000 <cf.in >cf.out
if %errorlevel% NEQ 0 (
    echo Runtime error. Exiting the script.
    exit
)

fc cf.out cf.ok

