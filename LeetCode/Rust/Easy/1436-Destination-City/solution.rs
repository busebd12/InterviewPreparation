use std::collections::HashMap;

impl Solution
{
    pub fn dest_city(paths: Vec<Vec<String>>) -> String
    {
        let mut result: String=String::new();

        let mut hashmap: HashMap<String, usize>=HashMap::new();

        for path in paths.iter()
        {
            let outgoing: &String=&path[0];

            let incoming: &String=&path[1];

            if !hashmap.contains_key(outgoing)
            {
                hashmap.insert(outgoing.to_string(), 0);
            }
            else
            {
                hashmap.entry(outgoing.to_string()).and_modify(|value| {*value+=1;});
            }

            if !hashmap.contains_key(incoming)
            {
                hashmap.insert(incoming.to_string(), 0);
            }
            else
            {
                hashmap.entry(incoming.to_string()).and_modify(|value| {*value+=1;});
            }
        }

        for path in paths.iter()
        {
            let incoming: &String=&path[1];

            if hashmap.get(incoming)==Some(&0)
            {
                result=incoming.to_string();

                break;
            }
        }

        result
    }
}


impl Solution
{
    pub fn dest_city(paths: Vec<Vec<String>>) -> String
    {
        let mut result: String=String::new();

        let mut hashmap: HashMap<String, usize>=HashMap::new();

        for path in paths.iter()
        {
            let outgoing: &String=&path[0];

            let incoming: &String=&path[1];

            if !hashmap.contains_key(outgoing)
            {
                hashmap.insert(outgoing.to_string(), 0);
            }
            else
            {
                hashmap.entry(outgoing.to_string()).and_modify(|value| {*value+=1;});
            }

            if !hashmap.contains_key(incoming)
            {
                hashmap.insert(incoming.to_string(), 0);
            }
            else
            {
                hashmap.entry(incoming.to_string()).and_modify(|value| {*value+=1;});
            }
        }

        for path in paths.iter()
        {
            let incoming: &String=&path[1];

            match hashmap.get(incoming)
            {
                Some(&0) =>
                {
                    result=incoming.to_string();

                    break;
                }
                _ =>
                {
                    
                }
            }
        }

        result
    }
}