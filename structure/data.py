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

        