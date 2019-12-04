#!/bin/bash

lex minipy-lab.l
yacc minipy-lab.y
g++ y.tab.c
