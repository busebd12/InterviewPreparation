#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + (n * I) + n + n) [where n is the number of recipes and I is the average length of the ingredients vector for the recipe]
Space complexity: O(n + s) [where n is the number of recipes and s is the number of supplies]
*/

class Solution
{
    public:
        vector<string> findAllRecipes(vector<string> & recipes, vector<vector<string>> & ingredients, vector<string> & supplies)
        {
            vector<string> result{};

            int n=recipes.size();

            //Hashtable that maps an ingredient to the recipe that needs it
            unordered_map<string, vector<string>> graph;

            //Hashtable that maps a recipe to the number of ingredients that it needs in order to be made
            unordered_map<string, int> recipeIndegrees;

            //Use an unordered_set<string> to hold the supplies for O(1) look-up
            unordered_set<string> us(begin(supplies), end(supplies));

            //Initially, all the recipes have an indegree of zero
            for(int i=0;i<n;i++)
            {
                recipeIndegrees[recipes[i]]=0;
            }

            for(int i=0;i<n;i++)
            {
                string recipe=recipes[i];

                for(int j=0;j<ingredients[i].size();j++)
                {
                    string ingredient=ingredients[i][j];

                    //If the supplies do not have the ingredient needed for the recipe
                    if(!us.count(ingredient))
                    {
                        //Create a directed edge from the ingredient to the recipe, indicating that we need this ingredient to make the recipe
                        graph[ingredient].emplace_back(recipe);

                        //Increment the indegree of the recipe
                        recipeIndegrees[recipe]++;
                    }
                }
            }

            deque<string> queue;

            //Iterate through the indegrees for each recipe
            for(const auto & [recipe, indegree] : recipeIndegrees)
            {
                //If the indegree for the recipe is zero, then we already have all the necessary ingredients to make this recipe
                if(indegree==0)
                {
                    //Since recipes can require other reciepes as ingredients, we add the recipe to the queue so that it can be used in other recipes
                    queue.emplace_back(recipe);
                }
            }

            while(!queue.empty())
            {   
                //Remove the recipe at the head of the queue
                auto recipe=queue.front();

                queue.pop_front();

                //Add the recipe to the result vector since we have all the necessary ingredients to make it
                result.emplace_back(recipe);

                //Iterate through all the recipes that require this recipe as an ingredient
                for(auto & neighbour : graph[recipe])
                {
                    //Decrement the indegree of the neighbouring recipe since this recipe serves as an ingredient (one less ingredient needed)
                    recipeIndegrees[neighbour]--;

                    //If the indegree of the neighbour is zero, then we have all the necessary ingredients to make the recipe
                    if(recipeIndegrees[neighbour]==0)
                    {
                        //Add neighbouring recipe to the queue
                        queue.emplace_back(neighbour);
                    }
                }
            }

            return result;
        }
};