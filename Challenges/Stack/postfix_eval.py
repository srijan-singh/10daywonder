from collections import deque

def postfix_eval(exp):
     
     variable = deque()
     operation = deque()

     for elm in exp:
          if (elm.isalnum()):
               variable.append(int(elm))
          else:
               operation.append(elm)

     result = variable[0]
     variable.popleft()

     while(len(variable) != 0):
          left = result

          right = variable[0]
          variable.popleft()

          if(len(operation) != 0):
               elm = operation[0]
               operation.popleft()

               if(elm == '+'):
                    result=left+right

               elif(elm=='-'):
                    result=left-right

               elif(elm=='*'):
                    result=left*right

               elif(elm=='//'):
                    result=left//right

               else:
                    return -1

     return result



if __name__ == "__main__":
     
     exp = "12 12 + 2 3 * -"
     exp=exp.split(" ")
     print(postfix_eval(exp))