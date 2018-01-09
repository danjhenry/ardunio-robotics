import requests

url = 'http://192.168.8.109/'

class nodeMCU:
    def __init__(self, url, response = None):
        self.url = url
        self.rep = response
        self.rDir = 0
        self.lDir = 0
        self.rSpd = 0
        self.lSpd = 0
        self.payload = {}
        self.send
        
    def send(self, rightDir=0, leftDir=0, rightSpeed=0, leftSpeed=0):
        verify = False
        if self.rDir != rightDir:
            self.rDir = rightDir
            verify = True           
        if self.lDir != leftDir:
            self.lDir = leftDir
            verify = True          
        if self.rSpd != rightSpeed:
            self.rSpd = rightSpeed
            verify = True
        if self.lSpd != leftSpeed:
            self.lSpd = leftSpeed
            verify = True
        if(verify):
            self.payload['aDir'] = self.rDir
            self.payload['bDir'] = self.lDir
            self.payload['aSpeed'] = self.rSpd
            self.payload['bSpeed'] = self.lSpd
            self.req = requests.get(self.url, params=self.payload)
            if(self.rep):
                self.payload['resp'] = str(self.rep)
                print(self.req.text, '\n')



