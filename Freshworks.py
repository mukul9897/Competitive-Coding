import os
import sys
import json
import datetime
def power(x, y): 
  
    if (y == 0): return 1
    elif (int(y % 2) == 0): 
        return (power(x, int(y / 2)) *
               power(x, int(y / 2))) 
    else: 
        return (x * power(x, int(y / 2)) *
                   power(x, int(y / 2))) 
  
def binarySearch (arr, l, r, x): 
  
    # Check base case 
    if r >= l: 
  
        mid = l + (r - l) // 2
  
        # If element is present at the middle itself 
        if arr[mid] == x: 
            return mid 
          
        # If element is smaller than mid, then it  
        # can only be present in left subarray 
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        # Else the element can only be present  
        # in right subarray 
        else: 
            return binarySearch(arr, mid + 1, r, x) 
  
    else: 
        # Element is not present in the array 
        return -1
  
class Util:
    def parse(d): 
        dictionary = dict() 
        # Removes curly braces and splits the pairs into a list 
        pairs = d.strip('{}').split(', ') 
        for i in pairs: 
            pair = i.split(': ') 
            # Other symbols from the key-value pair should be stripped. 
            dictionary[pair[0].strip('\'\'\"\"')] = pair[1].strip('\'\'\"\"') 
        return dictionary

    def contains(path, key): 
        try: 
            file = open(path, 'rt') 
            lines = file.read().split('\n') 
            for l in lines: 
                if l != '': 
                    dictionary = parse(l) 
                    #print(dictionary.keys) 
                    if list(dictionary.keys())[0] == key:
                        return True
            file.close() 
        except: 
            print("Something unexpected occurred!")

        return False
        
    def secTillNow():
        now = datetime.datetime.now()
        midnight = datetime.datetime.combine(now.date(), datetime.time())
        seconds = (now - midnight).seconds
        return seconds

class Library:
    
    '''Describe this class'''
    
    def __init__(self, path = None):
        if path == None:
            self.path = os.getcwd()
        else:
            self.path = path
        
        self.__fileName = "library.txt"  #library file
        
        try:
            self.path = os.path.join(self.path, self.__fileName)
            with open(self.path, "a+") as file:
                file.close()
                
        except FileNotFoundError as fnf_error:
            print("Error : ", fnf_error)
            
        except:
            print('Unable to initialize library')
            
            
    def create(self, key, value, timeToLive = 86400):
        
        if Util.contains(self.path, key) == False:            
            
            fileStats = os.stat(self.path)
            fileSize = (fileStats.st_size)/(1024*1024)
            if fileSize >= 1024:
                print("file size is too large")
                return "Operation Unsuccessfull"
            #else:
                #print(fileSize)
            dict = {} 
            
            if type(key) == type("") and len(key) <= 32:
                if key.isalpha():
                    try: 
                        value = json.loads(value) 
                        # print ("Is valid json? true") 
                    except ValueError as e: 
                        print ("It is not valid json object")
                        return
                    if(sys.getsizeof(value) <= (1024*16)):
                        dict[key] = value
                        tSec = Util.secTillNow()
                        if timeToLive == 86400:
                            dict['timeToLive'] = timeToLive-1
                        else:
                            dict['timeToLive'] = (tSec + timeToLive)
                        try:
                            with open(self.path, "a+") as file:
                                file.write(str(dict)+"\n")
                                file.close()
                                print("The value was appended in library")
                        except:
                            print("Unable to perform create operation")
                    else:
                        print("json object size exceeded")
                else:
                    print("key should be alpha numeric")

            else:
                print("Key size exceeded")
            
        else:
            print("Key is already present")
            
    
    def read(self, key):
        try: 
            file = open(self.path, 'rt') 
            lines = file.read().split('\n') 
            for l in lines: 
                if l != '': 
                    dictionary = eval(l)
                    #print(dictionary.keys) 
                    if list(dictionary.keys())[0] == key:
                        if dictionary['timeToLive'] >= Util.secTillNow():
                            return dictionary[key]
                        else:
                            return "json object is not accessible"
            file.close() 
        except: 
            print("Something unexpected occurred!")

        return "Key Not Found"
    
    def delete(self, key):
        try:
            flag = False
            readFile = open(self.path, "r")
            lines = readFile.readlines()
            readFile.close()
            #print(lines)
            
            writeFile = open(self.path, "w")
            for line in lines:
                dictionary = eval(line.strip("\n"))
                if list(dictionary.keys())[0] == key:
                    if dictionary['timeToLive'] < Util.secTillNow():
                        writeFile.write(line)
                    else:
                        flag = True
                        deletedVal = dictionary
                else:
                    writeFile.write(line)
            writeFile.close()
            
            if flag:
                print("Value was deleted")
                return deletedVal
            else:
                print("Either the key is not present or key is unaccessible")
                
        except:
            print("Something unexpected occured!")





try:
  tem=Library()    #can provide path as arguments to make data store library in that directory
  while True:
    print("1.Create  2.Read  3.Delete  4.Exit:-")
    n=int(input())
    if n<1 and n>4:
      print("Invalid Input")
    elif n==4:
      print("Thanks for using our storage servie :)")
      break
    elif n==3:
      print("Enter the Key")
      s=input()
      tem.delete(s)
    elif n==2:
      print("Enter Key")
      s=input()
      print(tem.read(s))
    else:
      print("Key")
      key=input()
      print("Value(json format)")
      mp=input()
      print("Enter time_to_live(optional)")
      ttl=input()
      if len(ttl)==0:
        tem.create(key,mp)
      else:
        tem.create(key,mp,int(ttl))
except EOFError as e:
  print(e)
