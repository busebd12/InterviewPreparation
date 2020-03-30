#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. As we iterate over the asteroids vector, we handle several cases:
 *
 * a. The stack is empty --> add an asteroid to the stack
 *
 * b. The stack is not empty and the current asteroid is negative --> since the asteroid is negative, it can only
 * collide with positive asteroids. Therefore, while the stack is not empty, the top element in the stack is a
 * positive asteroid, and the absolute value of the top element is less than or equal to the current asteroid,
 * we remove the top element from the stack. Inside the while loop, we check to see if the asteroid collided with
 * another asteroid with absolute value being equal to the value of the current asteroid. After the while loop,
 * we have two possibilities: either, the stack is empty or it is not. If it is not empty, then the only way
 * the current asteroid will be added to the stack is if there weren't any collisions or there was at least one
 * collision and there was not an asteroid with an absolute value equal to the value of the current asteroid.
 * If the stack is empty, then the current asteroid is only added if there was at least one collision and there
 * was not an asteroid with an absolute value equal to the value of the current asteroid.
 *
 * c. The stack is not empty and the current asteroid is positive --> add it to the stack.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 2. Another version of the first solution but using the vector that will be returned as the stack.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

std::vector<int> asteroidCollision(std::vector<int> & asteroids)
{
    if(asteroids.empty())
    {
        return asteroids;
    }

    std::vector<int> result;

    std::stack<int> stk;

    for(auto & asteroid : asteroids)
    {
        if(stk.empty())
        {
            stk.push(asteroid);
        }
        else
        {
            if(asteroid < 0)
            {
                bool collision=false;

                bool equalFound=false;

                while(!stk.empty() && stk.top() > 0 && (std::abs(asteroid) >= stk.top()))
                {
                    if(std::abs(asteroid)==stk.top())
                    {
                        equalFound=true;
                    }

                    stk.pop();

                    collision=true;

                    if(equalFound)
                    {
                        break;
                    }
                }

                if(!stk.empty())
                {
                    if(stk.top() < 0)
                    {
                        if(!collision || (collision && !equalFound))
                        {
                            stk.push(asteroid);
                        }
                    }
                }
                else
                {
                    if(collision && !equalFound)
                    {
                        stk.push(asteroid);
                    }
                }
            }
            else
            {
                stk.push(asteroid);
            }
        }
    }

    while(!stk.empty())
    {
        result.emplace_back(stk.top());

        stk.pop();
    }

    std::reverse(result.begin(), result.end());

    return result;
}

std::vector<int> asteroidCollision(std::vector<int> & asteroids)
{
    if(asteroids.empty())
    {
        return asteroids;
    }

    std::vector<int> result;

    for(auto & asteroid : asteroids)
    {
        if(result.empty())
        {
            result.emplace_back(asteroid);
        }
        else
        {
            if(asteroid < 0)
            {
                bool collision=false;

                bool equalFound=false;

                while(!result.empty() && result.back() > 0 && (std::abs(asteroid) >= result.back()))
                {
                    if(std::abs(asteroid)==result.back())
                    {
                        equalFound=true;
                    }

                    result.pop_back();

                    collision=true;

                    if(equalFound)
                    {
                        break;
                    }
                }

                if(!result.empty())
                {
                    if(result.back() < 0)
                    {
                        if(!collision || (collision && !equalFound))
                        {
                            result.emplace_back(asteroid);
                        }
                    }
                }
                else
                {
                    if(collision && !equalFound)
                    {
                        result.emplace_back(asteroid);
                    }
                }
            }
            else
            {
                result.emplace_back(asteroid);
            }
        }
    }

    return result;
}