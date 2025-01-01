class Solution:
    def romanToInt(self, s: str) -> int:
        result: int=0

        n: int=len(s)

        numerals=["I", "V", "X", "L", "C", "D", "M", "IX", "IV", "XL", "XC", "CD", "CM"]

        hashmap=self.populate_hashmap(numerals)

        index: int=0

        while index < n:
            key: str=str(s[index])
            
            if s[index]=='I':
                if index + 1 < n and (s[index + 1]=='V' or s[index + 1]=='X'):
                    key=key + s[index + 1]

                    result+=hashmap[key]

                    index+=2
                else:
                    result+=hashmap[key]

                    index+=1

            elif s[index]=='X':
                if index + 1 < n and (s[index + 1]=='L' or s[index + 1]=='C'):
                    key=key + s[index + 1]

                    result+=hashmap[key]

                    index+=2
                else:
                    result+=hashmap[key]

                    index+=1
                
            elif s[index]=='C':
                if index + 1 < n and (s[index + 1]=='D' or s[index + 1]=='M'):
                    key=key + s[index + 1]

                    result+=hashmap[key]

                    index+=2
                else:
                    result+=hashmap[key]

                    index+=1
            else:
                result+=hashmap[key]

                index+=1
        
        return result


    def populate_hashmap(self, numerals: List[str]) -> dict[str, int]:
        hashmap: dict[str, int]=dict()

        for numeral in numerals:
            if numeral=="I":
                hashmap[numeral]=1

            elif numeral=="IV":
                hashmap[numeral]=4

            elif numeral=="V":
                hashmap[numeral]=5

            elif numeral=="IX":
                hashmap[numeral]=9

            elif numeral=="X":
                hashmap[numeral]=10

            elif numeral=="XL":
                hashmap[numeral]=40

            elif numeral=="L":
                hashmap[numeral]=50

            elif numeral=="XC":
                hashmap[numeral]=90

            elif numeral=="C":
                hashmap[numeral]=100

            elif numeral=="CD":
                hashmap[numeral]=400

            elif numeral=="D":
                hashmap[numeral]=500

            elif numeral=="CM":
                hashmap[numeral]=900

            elif numeral=="M":
                hashmap[numeral]=1000

        return hashmap