
@echo off
g++ -O3 %1
a.exe <cf.in >cf.out
fc cf.out cf.ok

