#coding: utf-8

import importlib
import threading

def exethre(num,team,file):
    mod = importlib.import_module(file)
    mod.Brain(num,team)

def execute(num,team,file):
    th = threading.Thread(target=exethre,args=([num,team,file]),name="thread%d"%num)
    th.start()
    #th.join()
    return 1