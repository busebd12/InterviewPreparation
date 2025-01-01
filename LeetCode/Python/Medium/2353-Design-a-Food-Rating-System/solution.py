import heapq

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisine_heaps=dict()

        self.food_to_cuisine=dict()

        self.food_to_rating=dict()

        self.build_cuisine_heaps(foods, cuisines, ratings)

        self.map_food_to_cuisine(foods, cuisines)

        self.map_food_to_rating(foods, ratings)

    def build_cuisine_heaps(self, foods: List[str], cuisines: List[str], ratings: List[int]) -> None:
        for (index, food) in enumerate(foods):
            cuisine=cuisines[index]

            rating=ratings[index]

            if cuisine not in self.cuisine_heaps.keys():
                self.cuisine_heaps[cuisine]=list()

            heapq.heappush(self.cuisine_heaps[cuisine], (-rating, food))

    def map_food_to_cuisine(self, foods: List[str], cuisines: List[str]) -> None:
        for (index, food) in enumerate(foods):
            cuisine=cuisines[index]

            self.food_to_cuisine[food]=cuisine

    def map_food_to_rating(self, foods: List[str], ratings: List[str]) -> None:
        for (index, food) in enumerate(foods):
            rating=ratings[index]

            self.food_to_rating[food]=-rating

    def changeRating(self, food: str, newRating: int) -> None:
        self.food_to_rating[food]=-newRating
        
        cuisine=self.food_to_cuisine[food]

        heapq.heappush(self.cuisine_heaps[cuisine], (-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        while self.food_to_rating[self.cuisine_heaps[cuisine][0][1]] != self.cuisine_heaps[cuisine][0][0]:
            heapq.heappop(self.cuisine_heaps[cuisine])

        return self.cuisine_heaps[cuisine][0][1]