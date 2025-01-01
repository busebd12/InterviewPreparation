use std::collections::{HashMap, BTreeMap, BTreeSet};

struct FoodRatings
{
    food_to_rating: HashMap<String, usize>,

    food_to_cuisine: HashMap<String, String>,

    hashmap: HashMap<String, BTreeMap<usize, BTreeSet<String>>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FoodRatings
{
    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self
    {
        let mut food_to_rating=HashMap::new();

        let mut food_to_cuisine=HashMap::new();

        let mut hashmap=HashMap::new();

        FoodRatings::map_food_to_rating(&mut food_to_rating, &foods, &ratings);

        FoodRatings::map_food_to_cuisine(&mut food_to_cuisine, &foods, &cuisines);

        FoodRatings::build_hashmap(&mut hashmap, &foods, &cuisines, &ratings);

        FoodRatings
        {
            food_to_rating,
            
            food_to_cuisine,

            hashmap,
        }
    }

    fn map_food_to_rating(food_to_rating: &mut HashMap<String, usize>, foods: &Vec<String>, ratings: &Vec<i32>) -> ()
    {
        for (index, food) in foods.iter().enumerate()
        {
            food_to_rating.insert(food.to_string(), ratings[index] as usize);
        }
    }

    fn map_food_to_cuisine(food_to_cuisine: &mut HashMap<String, String>, foods: &Vec<String>, cuisines: &Vec<String>) -> ()
    {
        for (index, food) in foods.iter().enumerate()
        {
            food_to_cuisine.insert(food.to_string(), cuisines[index].to_string());
        }
    }

    fn build_hashmap(hashmap: &mut HashMap<String, BTreeMap<usize, BTreeSet<String>>>, foods: &Vec<String>, cuisines: &Vec<String>, ratings: &Vec<i32>) -> ()
    {
        for (index, cuisine) in cuisines.iter().enumerate()
        {
            let food: String=foods[index].to_string();

            let rating: usize=ratings[index] as usize;

            let cuisine_map: &mut BTreeMap<usize, BTreeSet<String>>=hashmap.entry(cuisine.clone()).or_insert(BTreeMap::new());

            let food_set: &mut BTreeSet<String>=cuisine_map.entry(rating).or_insert(BTreeSet::new());

            food_set.insert(food);
        }
    }
    
    fn change_rating(&mut self, food: String, new_rating: i32)
    {   
        let old_rating: usize=*(self.food_to_rating.get(&food).unwrap());
        
        self.food_to_rating.entry(food.clone()).and_modify(|value| {*value=new_rating as usize;});

        let cuisine: String=self.food_to_cuisine.get(&food.clone()).unwrap().to_string();

        if let Some(cuisine_map)=self.hashmap.get_mut(&cuisine)
        {
            if let Some(food_set)=cuisine_map.get_mut(&old_rating)
            {
                let food_to_remove: String=food.clone();

                food_set.remove(&food_to_remove);

                if food_set.is_empty()
                {
                    cuisine_map.remove(&old_rating);
                }
            }

            if let Some(food_set)=cuisine_map.get_mut(&(new_rating as usize))
            {
                food_set.insert(food);
            }
            else
            {
                let mut new_food_set: &mut BTreeSet<String>=cuisine_map.entry(new_rating as usize).or_insert(BTreeSet::new());

                new_food_set.insert(food);
            }
        }
    }
    
    fn highest_rated(&self, cuisine: String) -> String
    {
        if let Some(cuisine_map)=self.hashmap.get(&cuisine)
        {
            if let Some((highest_rating, food_set))=cuisine_map.iter().next_back()
            {
                if let Some(highest_rated_food)=food_set.iter().next()
                {
                    return highest_rated_food.clone();
                }
            }
        }

        String::new()
    }
}