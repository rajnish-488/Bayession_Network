import pandas as pd
import numpy as np

class read_data:
    def __init__(self,path):
        self.path=path
        self.df=None
    
    def read(self):
        self.df=pd.read_csv(self.path)

    