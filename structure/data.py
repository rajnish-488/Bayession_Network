import pandas as pd
import numpy as np

class featureData:
    def __init__(self,name,values):
        self.nodeName=name
        self.values=values
    
    def getName(self):
        return self.nodeName
    
    def setName(self,name):
        self.nodeName=name

class Data:
    def __init__(self):
        self.data=[]
        self.dataName=None
        self.description=None
        