class Node:
    def __init__( self,name,prob,parent,child):
        self.name=name
        self.prob=prob
        self.parent=parent
        self.child=child
    
    def getprob(self):
        return self.prob
    
    def setprob(self,prob):
        self.prob=prob
    


class Relation:
    def __init__(self):
        self.reation=[]


    def append_parents(self,node):
        self.relation.append(node)
  