#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused_imports)]
#![allow(unused_parens)]

use std::collections::{BinaryHeap, HashMap, HashSet, VecDeque};
use std::{cmp, fmt};
use rand::{Rng, rngs::ThreadRng, thread_rng};
use json::{object, JsonValue};

#[derive(Clone, Debug, Eq, Hash, PartialEq)]
struct Weapon
{
    name: String
}

impl Weapon
{
    fn new(name: &str) -> Self
    {
        Self
        {
            name: name.to_string()
        }
    }

    fn get_name(&self) -> String
    {
        self.name.clone()
    }
}

impl fmt::Display for Weapon
{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> Result<(), std::fmt::Error>
    {
        write!(f, "{}", self.name)?;

        Ok(())
    }
}

struct Spartan
{
    name: String,

    id: i32,

    total_number_of_weapons: i32,

    weapons: HashMap<Weapon, i32>
}

impl Spartan
{
    fn new(name: &str, id: i32) -> Self
    {
        Self
        {
            name: name.to_string(),

            id: id,

            total_number_of_weapons: 0,

            weapons: HashMap::new()
        }
    }

    fn add_weapon(&mut self, weapon_name: &str, count: i32) -> ()
    {
        for _iteration in 0..count
        {
            let w: Weapon=Weapon::new(weapon_name);

            *self.weapons.entry(w).or_insert(0)+=1;

            self.total_number_of_weapons+=1;
        }
    }

    fn get_name(&self) -> String
    {
        self.name.clone()
    }

    fn get_id(&self) -> i32
    {
        self.id
    }

    fn get_weapons(&self) -> &HashMap<Weapon, i32>
    {
        &self.weapons
    }

    fn get_weapon_types(&self) -> Vec<Weapon>
    {
        self.weapons.keys().cloned().collect::<Vec<Weapon>>()
    }

    fn get_total_number_of_weapons(&self) -> i32
    {
        self.total_number_of_weapons
    }
}

impl fmt::Display for Spartan
{
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> Result<(), std::fmt::Error>
    {
        write!(f, "Hello, I am spartan {} {} and I have {} weapons.", self.name, self.id, self.total_number_of_weapons)?;

        Ok(())
    }
}

struct JsonTestClass
{
    pub json: JsonValue
}

impl JsonTestClass
{
    pub fn new() -> Self
    {
        Self
        {
            json: object!
            {
                "code": 200,
                success: true,
                payload: {
                    features: [
                        "awesome",
                        "easyAPI",
                        "lowLearningCurve"
                    ]
                }
            }
        }
    }
}

struct MyObject
{
    hashmap: HashMap<String, i32>
}

impl MyObject
{
    fn new() -> Self
    {
        Self
        {
            hashmap: HashMap::new()
        }
    }
}

fn main()
{
    let option1: Option<i32>=Some(5);

    let option2: Option<i32>=Some(2);

    if option1==option2
    {
        println!("option1==option2");
    }
    else
    {
        println!("option1!=option2");
    }
}

fn return_reference<'lifetime>(first: &'lifetime str, second: &'lifetime str) -> &'lifetime str
{
    if first.len() > second.len()
    {
        first
    }
    else
    {
        second
    }
}
