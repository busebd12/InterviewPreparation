class Solution:
    def reorganizeString(self, s: str) -> str:
        result: str=""

        #Hashmap used to store letter frequencies
        hashmap: Dict[chr, int]=dict()

        #Populuate the hashmap with letter frequencies
        for letter in s:
            if letter not in hashmap.keys():
                hashmap[letter]=1
            else:
                hashmap[letter]+=1

        #Maximum heap of tuples of the form {letter frequency, letter}
        max_heap: List[Tuple[chr, int]]=list()

        #Populate the maximum heap
        for (letter, frequency) in hashmap.items():
            heapq.heappush(max_heap, (-frequency, letter))

        #While there is more than one letter left in the heap
        while len(max_heap) > 1:
            #Remove the first letter and its frequency
            first_letter: chr=max_heap[0][1]

            first_letter_frequency: int=(-1 * max_heap[0][0])

            heapq.heappop(max_heap)

            #If the result string is not empty and the letter removed from the heap is the same as the last letter in the string
            if result and result[-1]==first_letter:
                #Remove a second letter and frequency from the heap
                second_letter: chr=max_heap[0][1]

                second_letter_frequency: int=(-1 * max_heap[0][0])

                heapq.heappop(max_heap)

                #Add the first letter and frequency tuple back into the heap
                heapq.heappush(max_heap, (-first_letter_frequency, first_letter))

                #Append the letter to the result string
                result+=second_letter

                #Decrement the frequency
                second_letter_frequency-=1

                #If there is at least one occurrence of the second letter left
                if second_letter_frequency > 0:
                    #Add the frequency, letter tuple back into the heap
                    heapq.heappush(max_heap, (-second_letter_frequency, second_letter))
            #Else, the first letter removed from the heap is not the same as the last letter in the result string or the result strign is empty
            else:
                #Append the first letter to the result string
                result+=first_letter

                #Decrement the frequency
                first_letter_frequency-=1

                #If there is at least one occurrence of the first letter left
                if first_letter_frequency > 0:
                    #Add the frequency, letter tuple back into the heap
                    heapq.heappush(max_heap, (-first_letter_frequency, first_letter))

        #If the heap is not empty, that means there is a single letter left in it
        if max_heap:
            remaining_letter: chr=max_heap[0][1]

            remaining_letter_frequency: int=(-1 * max_heap[0][0])

            #If the result strign is not empty
            if result:
                #If the remaining letter is the same as the last letter in the result string or the remaining letter is different than the last letter in the result string, but the frequency is greater than one, we can't rearrange the letters in the string
                if remaining_letter==result[-1] or remaining_letter_frequency > 1:
                    return ""
                #Else, add the letter to the result string
                else:
                    result+=remaining_letter
            #Else, the result string is empty
            else:
                #If there is more than one copy of the remaining letter, we can't rearrange the letters in the string
                if remaining_letter_frequency > 1:
                    return ""
                #Else, there is just a single copy of the remaining letter
                else:
                    result+=remaining_letter

        return result