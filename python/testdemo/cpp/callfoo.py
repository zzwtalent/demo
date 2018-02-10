#!/usr/bin/python
import ctypes 
ll = ctypes.cdll.LoadLibrary  
lib = ll("./libfoo.so")   
lib.foo(1, 3) 
print '***finish***' 
