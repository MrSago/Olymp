
@echo off
g++ -O3 %1
%1.exe <cf.in >cf.out
fc cf.out cf.ok

