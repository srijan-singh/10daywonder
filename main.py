class FreqStack:

     def __init__(self):
          self.intStack = []
          self.memo = dict()
          self.max_freq =  0

     def get_max_freq(self):
          self.max_freq = 0

          for elm in self.memo:

               if self.max_freq <= self.memo[elm]:
                    self.max_freq = self.memo[elm]
                    self.max_elm = elm

     def push(self, elm):
          if(elm in self.memo):
               self.memo[elm] += 1

          else:
               self.memo[elm] = 1

          self.intStack.append(elm)

     def pop(self):

          self.get_max_freq()

          buffer = list()

          last_elm = self.memo[self.intStack[-1]]

          while(last_elm != self.max_freq and len(self.intStack) > 0):

               buffer.append(self.intStack[-1])
               self.intStack.pop()

               last_elm = self.memo[self.intStack[-1]]

          last = self.intStack[-1]
          self.intStack.pop()

          self.memo[last] -= 1

          while(len(buffer) != 0):
               self.intStack.append(buffer[-1])
               buffer.pop()

          return last

     
                
     
                    

if __name__ == "__main__":

     freqStack = FreqStack()
     freqStack.push(1)
     freqStack.push(0)
     freqStack.push(0)
     freqStack.push(1)
     freqStack.push(5)
     freqStack.push(4)
     freqStack.push(1)
     freqStack.push(5)
     freqStack.push(1)
     freqStack.push(6)
     #freqStack.print_memo()
     
     
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())
     print(freqStack.pop())