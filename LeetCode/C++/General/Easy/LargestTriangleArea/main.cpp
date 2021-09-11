#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approach: formula found here ---> https://www.mathopenref.com/coordtrianglearea.html
 *
 * Time complexity: O((n-2)(n-1)(n))=n-cubed - 3n squared + 2n = O(n^3)
 * Space complexity: O(1)
 */

double largestTriangleArea(vector<vector<int>>& points)
{
    double result{};

    if(points.empty())
    {
        return result;
    }

    size_t n=points.size();

    for(size_t i=0;i<n-2;++i)
    {
        for(size_t j=i+1;j<n-1;++j)
        {
            for(size_t k=j+1;k<n;++k)
            {
                double Ax=points[i][0];

                double Bx=points[j][0];

                double Cx=points[k][0];

                double Ay=points[i][1];

                double By=points[j][1];

                double Cy=points[k][1];

                double first=Ax * (By - Cy);

                double second=Bx * (Cy - Ay);

                double third=Cx * (Ay - By);

                double area=abs((first + second + third))/2;

                result=max(result, area);
            }
        }
    }

    return result;
}