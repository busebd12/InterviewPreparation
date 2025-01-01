import heapq

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        result=list()

        graph=dict()

        for meeting in meetings:
            x=meeting[0]

            y=meeting[1]

            time=meeting[2]

            if x not in graph.keys():
                graph[x]=list()

            graph[x].append((y, time))

            if y not in graph.keys():
                graph[y]=list()

            graph[y].append((x, time))

        knows_secret=[False for _ in range(0, n)]

        #Minimum heap of tuples of the form (time secret was discovered, person)
        min_heap=list()

        #Add (person 0, knows the secret at time 0) to the heap
        heapq.heappush(min_heap, (0, 0))

        #Add (firstPerson, time 0) to the heap
        heapq.heappush(min_heap, (0, firstPerson))

        while min_heap:
            time, person=heapq.heappop(min_heap)

            if knows_secret[person]:
                continue

            result.append(person)

            knows_secret[person]=True

            if person not in graph.keys():
                continue

            for (other_person, meeting_time) in graph[person]:
                if knows_secret[other_person] or meeting_time < time:
                    continue

                heapq.heappush(min_heap, (meeting_time, other_person))

        return result