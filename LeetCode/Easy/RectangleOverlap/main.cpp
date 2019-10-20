#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: calculate the area formed by the two rectangles intersecting at there two ends and make sure its positive.
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

bool isRectangleOverlap(vector<int> & rec1, vector<int> & rec2)
{
    return ((rec1[2] - rec2[0] > 0 && rec1[3] - rec2[1] > 0) && (rec2[2] - rec1[0] > 0 && rec2[3] - rec1[1] > 0));
}