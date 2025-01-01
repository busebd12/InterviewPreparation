class Solution
{
    public:
        bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
        {
            int width=(x2 - x1);

            int height=(y2 - y1);

            float testX=xCenter;

            float testY=yCenter;

            //Check if the circle is to the left of the rectangle
            if(xCenter < x1)
            {
                testX=x1;
            }
            //Check if the circle is to the right of the rectangle
            else if(xCenter > x1 + width)
            {
                testX=x1 + width;
            }

            //Check if the circle is above the rectangle
            if(yCenter > y2)
            {
                testY=y2;
            }
            else if(yCenter < y1)
            {
                testY=y1;
            }

            //Calculate the distance between our chosen point and the center of the circle
            float xDistance=(float)(xCenter - testX) * (float)(xCenter - testX);

            float yDistance=(float)(yCenter - testY) * (float)(yCenter - testY);

            float dist=sqrt(xDistance + yDistance);

            //if the distance is less than or equal to the radius, then we return true; else, false
            return int(dist) <= radius;
        }
};