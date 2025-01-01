from collections import OrderedDict

class LRUCache:
    __cache: dict[int, int]=None

    __capacity: int=None

    def __init__(self, capacity: int):
        self.__cache=OrderedDict()
        
        self.__capacity=capacity

    def get(self, key: int) -> int:
        if key not in self.__cache.keys():
            return -1

        #OrderedDict's move_to_end method will move a key value pair to either the end
        #or the beginning or the dictionary depending on the value for the second argument
        #Since we are using False for the second argument, the key-value pair with key
        #"key" will be moved to the beginning/front of the cache
        self.__cache.move_to_end(key, False)

        return self.__cache[key]

    def put(self, key: int, value: int) -> None:
        if key not in self.__cache.keys():
            
            #If the cache is full
            if len(self.__cache)==self.__capacity:
                
                #Use the popitem() method to remove the last key value pair/key value pair at the end of the OrderedDict
                self.__cache.popitem()
        
        #Update the value for key or insert a new key-value pair into the cache
        self.__cache[key]=value

        #Move the newly updated/added key-value pair to the front of the cache
        self.__cache.move_to_end(key, False)