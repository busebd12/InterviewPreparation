use std::collections::HashMap;

impl Solution
{
    pub fn roman_to_int(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();

        let hashmap: HashMap<String, u32>=Solution::populate_hashmap();

        let mut index: usize=0;

        while index < n
        {
            let mut character: char=s.chars().nth(index).unwrap();

            let mut key: String=String::from(character);

            match(character)
            {
                'I' =>
                {
                    if index + 1 < n
                    {
                        let next: char=s.chars().nth(index + 1).unwrap();
                        
                        if next=='V'|| next=='X'
                        {
                            key.push(next);

                            index+=2;
                        }
                        else
                        {
                            index+=1;
                        }
                        
                        let value: &u32=hashmap.get(&key).unwrap();

                        let amount: i32=*value as i32;

                        result+=amount;
                    }
                    else
                    {
                        let value: &u32=hashmap.get(&key).unwrap();

                        let amount: i32=*value as i32;

                        result+=amount;

                        index+=1
                    }
                },

                'X' =>
                {
                    if index + 1 < n
                    {   
                        let next: char=s.chars().nth(index + 1).unwrap();
                        
                        if next=='L'|| next=='C'
                        {
                            key.push(next);

                            index+=2;
                        }
                        else
                        {
                            index+=1;
                        }
                        
                        let value: &u32=hashmap.get(&key).unwrap();

                        let amount: i32=*value as i32;

                        result+=amount;
                    }
                    else
                    {
                        let value: &u32=hashmap.get(&key).unwrap();

                        let amount: i32=*value as i32;

                        result+=amount;

                        index+=1
                    }
                },

                'C' =>
                {
                    if index + 1 < n
                    {
                        let next: char=s.chars().nth(index + 1).unwrap();
                        
                        if next=='D'|| next=='M'
                        {
                            key.push(next);

                            index+=2;
                        }
                        else
                        {
                            index+=1;
                        }
                        
                        let value: &u32=hashmap.get(&key).unwrap();

                        let amount: i32=*value as i32;

                        result+=amount;
                    }
                    else
                    {
                        let value: &u32=hashmap.get(&key).unwrap();

                        let amount: i32=*value as i32;

                        result+=amount;

                        index+=1
                    }
                },

                _ =>
                {
                    let value: &u32=hashmap.get(&key).unwrap();

                    let amount: i32=*value as i32;

                    result+=amount;

                    index+=1
                }
            };
        }

        result
    }

    pub fn populate_hashmap() -> HashMap<String, u32>
    {
        let symbols: Vec<String>=vec!["I".to_string(), "IV".to_string(), "V".to_string(), "IX".to_string(), "X".to_string(), "XL".to_string(), "L".to_string(), "XC".to_string(), "C".to_string(), "CD".to_string(), "D".to_string(), "CM".to_string(), "M".to_string()];

        let mut hashmap: HashMap<String, u32>=HashMap::new();

        for symbol in symbols
        {
            match(symbol.as_str())
            {
                "I" =>
                {
                    hashmap.insert(symbol, 1);
                },

                "IV" =>
                {
                    hashmap.insert(symbol, 4);
                },

                "V" =>
                {
                    hashmap.insert(symbol, 5);
                },

                "IX" =>
                {
                    hashmap.insert(symbol, 9);
                },

                "X" =>
                {
                    hashmap.insert(symbol, 10);
                },

                "XL" =>
                {
                    hashmap.insert(symbol, 40);
                },

                "L" =>
                {
                    hashmap.insert(symbol, 50);
                },

                "XC" =>
                {
                    hashmap.insert(symbol, 90);
                },

                "C" =>
                {
                    hashmap.insert(symbol, 100);
                },

                "CD" =>
                {
                    hashmap.insert(symbol, 400);
                },

                "D" =>
                {
                    hashmap.insert(symbol, 500);
                },

                "CM" =>
                {
                    hashmap.insert(symbol, 900);
                },

                "M" =>
                {
                    hashmap.insert(symbol, 1000);
                },

                _ => (),
            };
        }

        hashmap
    }
}

impl Solution
{
    pub fn roman_to_int(s: String) -> i32
    {
        let mut result: i32=0;

        let n: usize=s.len();

        let translate=|character: char| match(character)
        {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0
        };

        let mut values: Vec<i32>=s.chars().map(translate).collect();

        for index in 0..n-1
        {
            if values[index] < values[index + 1]
            {
                values[index]*=-1;
            }
        }

        result=values.iter().sum();

        result
    }
}