#!/usr/bin/python
import ctypes
so = ctypes.cdll.LoadLibrary
lib=so('./libclass.so')
print 'display'
lib.display()
print 'display_100'
lib.display_int(100)

