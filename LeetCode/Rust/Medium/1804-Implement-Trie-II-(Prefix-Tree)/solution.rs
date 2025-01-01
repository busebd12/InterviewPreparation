use std::collections::{HashMap};

struct TrieNode
{
    children: HashMap<char, TrieNode>,

    prefix_count: i32,

    frequency: i32,

    end_of_word: bool
}

impl TrieNode
{
    fn new() -> Self
    {
        Self
        {
            children: HashMap::new(),

            prefix_count: 0,

            frequency: 0,

            end_of_word: false
        }
    }
}

struct Trie
{
    root: TrieNode
}

impl Trie
{
    fn new() -> Self
    {
        Self
        {
            root: TrieNode::new()
        }
    }

    fn insert(&mut self, word: String) -> ()
    {
        let mut node: &mut TrieNode=&mut self.root;

        for character in word.chars()
        {
            if !node.children.contains_key(&character)
            {
                node.children.insert(character, TrieNode::new());
            }

            node=node.children.get_mut(&character).unwrap();

            node.prefix_count+=1;
        }

        if !node.end_of_word
        {
            node.end_of_word=true;
        }

        node.frequency+=1;
    }

    fn count_words_equal_to(&mut self, word: String) -> i32
    {
        let mut node: &mut TrieNode=&mut self.root;

        let mut count: i32=0;

        for character in word.chars()
        {
            if !node.children.contains_key(&character)
            {
                return 0;
            }

            node=node.children.get_mut(&character).unwrap();
        }

        if !node.end_of_word
        {
            return 0;
        }

        node.frequency
    }

    fn count_words_starting_with(&mut self, prefix: String) -> i32
    {
        let mut node: &mut TrieNode=&mut self.root;

        for character in prefix.chars()
        {
            if !node.children.contains_key(&character)
            {
                return 0;
            }

            node=node.children.get_mut(&character).unwrap();
        }

        node.prefix_count
    }

    fn erase(&mut self, word: String) -> ()
    {
        let mut node: &mut TrieNode=&mut self.root;

        for character in word.chars()
        {
            node=node.children.get_mut(&character).unwrap();

            if node.prefix_count > 0
            {
                node.prefix_count-=1;
            }
        }

        if node.end_of_word
        {
            if node.frequency > 0
            {
                node.frequency-=1;

                if node.frequency==0
                {
                    node.end_of_word=false;
                }
            }
        }
    }
}