int addDigits(int num)
{
    int number=num;

    while(true)
    {
        int sum{};

        while(number >= 10)
        {
            int digit=number % 10;

            sum+=digit;

            number/=10;
        }

        sum+=number;

        number=sum;

        if(number < 10)
        {
            break;
        }
    }

    return number;
}