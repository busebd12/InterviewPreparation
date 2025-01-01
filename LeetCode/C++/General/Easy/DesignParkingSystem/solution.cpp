using namespace std;

class ParkingSystem
{
    private:
        int bigSpaces;

        int mediumSpaces;

        int smallSpaces;
    
    public:
        ParkingSystem(int big, int medium, int small)
        {
            bigSpaces=big;

            mediumSpaces=medium;

            smallSpaces=small;
        }
        
        bool addCar(int carType)
        {
            switch(carType)
            {
                case 1:
                {
                    if(bigSpaces > 0)
                    {
                        bigSpaces-=1;

                        return true;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case 2:
                {
                    if(mediumSpaces > 0)
                    {
                        mediumSpaces-=1;

                        return true;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case 3:
                {
                    if(smallSpaces > 0)
                    {
                        smallSpaces-=1;

                        return true;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                default:
                {
                    return false;

                    break;
                }
            }
        }
};