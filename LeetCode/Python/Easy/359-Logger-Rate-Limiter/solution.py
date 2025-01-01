class Logger:
    __hashmap: dict[str, int]=None

    def __init__(self) -> None:
       self. __hashmap=dict()

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.__hashmap:
            self.__hashmap[message]=timestamp + 10

            return True
        else:
            if timestamp >= self.__hashmap[message]:
                self.__hashmap[message]=timestamp + 10
                
                return True
            else:
                return False