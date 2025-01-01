import heapq

class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        result: List[int]=None

        w: int=len(workers)

        b: int=len(bikes)

        result=[-1 for _ in range(0, w)]

        assigned_bike_ids: Set[int]=set()

        min_heap: List[Tuple[int, int, int]]=list()

        #For each worker
        for worker in range(0, w):
            worker_x: int=workers[worker][0]

            worker_y:int=workers[worker][1]
            
            #Find the distance to the closest bike and that bike's id
            closest_bike_distance, bike_id=self.find_closest_bike(bikes, assigned_bike_ids, worker_x, worker_y)

            #Add the (closest_bike_distance, worker, bike_id) tuple to the min_heap
            heapq.heappush(min_heap, (closest_bike_distance, worker, bike_id))

        #While there are still bikes to assign and the min_heap is not empty
        while len(assigned_bike_ids) < w and min_heap:
            distance, worker_id, bike_id=heapq.heappop(min_heap)

            #If we've already assigned this bike to a worker
            if bike_id in assigned_bike_ids:
                worker_x, worker_y=workers[worker_id]

                #Find the next closest bike distance and id for the current worker
                next_closest_distance, next_closest_bike_id=self.find_closest_bike(bikes, assigned_bike_ids, worker_x, worker_y)

                heapq.heappush(min_heap, (next_closest_distance, worker_id, next_closest_bike_id))
            else:
                #Assign the current bike to the current worker
                result[worker_id]=bike_id

                #Mark the bike as assigned
                assigned_bike_ids.add(bike_id)

        return result

    def find_closest_bike(self, bikes: List[List[int]], assigned_bike_ids: Set[int], worker_x: int, worker_y: int) -> Tuple[int, int]:
        min_distance: float=float("inf")

        closest_bike_id: int=-1

        for bike_id, (bike_x, bike_y) in enumerate(bikes):
            manhattan_distance: int=self.get_manhattan_distance(bike_x, bike_y, worker_x, worker_y)

            if manhattan_distance < min_distance and bike_id not in assigned_bike_ids:
                closest_bike_id=bike_id

                min_distance=manhattan_distance

        return (min_distance, closest_bike_id)

    def get_manhattan_distance(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return abs(x1 - x2) + abs(y1 - y2)