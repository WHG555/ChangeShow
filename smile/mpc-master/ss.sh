#!/bin/bash
gcc -std=c99 -Wall main.c mpc.c -ledit -lm -o dd
ctags -R *
cscope -Rb
