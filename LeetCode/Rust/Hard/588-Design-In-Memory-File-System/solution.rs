use std::collections::{HashMap};

struct TrieNode
{
    children: HashMap<String, TrieNode>,

    name: String,

    contents: String,

    is_directory: bool
}

impl TrieNode
{
    fn new(name: String, is_directory: bool) -> Self
    {
        Self
        {
            children: HashMap::new(),

            name: name,

            contents: String::from(""),

            is_directory: is_directory
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
            root: TrieNode::new("/".to_string(), true)
        }
    }

    fn get_directory_contents(&self, path: String) -> Vec<String>
    {
        let mut node: &TrieNode=&self.root;

        let tokens: Vec<String>=Self::tokenize_path(&path, '/');

        for token in tokens.iter()
        {
            if !node.children.contains_key(token)
            {
                return Vec::new();
            }

            node=node.children.get(token).unwrap();
        }

        if !node.is_directory
        {
            return vec![node.name.clone()];
        }

        let mut directory_contents: Vec<String>=Vec::new();

        for child in node.children.values()
        {
            directory_contents.push((*child).name.clone());
        }

        directory_contents.sort();

        directory_contents
    }

    fn insert(&mut self, path: String) -> ()
    {
        let mut node: &mut TrieNode=&mut self.root;

        let tokens: Vec<String>=Self::tokenize_path(&path, '/');

        for token in tokens.iter()
        {
            if !node.children.contains_key(token)
            {
                node.children.insert((*token).clone(), TrieNode::new((*token).clone(), true));
            }

            node=node.children.get_mut(token).unwrap();
        }
    }
    
    fn append_content(&mut self, path: String, file_contents: String) -> ()
    {
        let mut node: &mut TrieNode=&mut self.root;

        let tokens: Vec<String>=Self::tokenize_path(&path, '/');

        for token in tokens.iter()
        {
            if !node.children.contains_key(token)
            {
                node.children.insert((*token).clone(), TrieNode::new((*token).clone(), true));
            }

            node=node.children.get_mut(token).unwrap();
        }

        node.is_directory=false;

        node.contents.push_str(file_contents.as_str());
    }

    fn get_file_contents(&self, path: String) -> String
    {
        let mut node: &TrieNode=&self.root;

        let tokens: Vec<String>=Self::tokenize_path(&path, '/');

        for token in tokens.iter()
        {
            if !node.children.contains_key(token)
            {
                return String::from("");
            }

            node=node.children.get(token).unwrap();
        }

        node.contents.clone()
    }

    fn tokenize_path(path: &String, delimiter: char) -> Vec<String>
    {
        let tokens: Vec<String>=path.split(delimiter).filter(|part| !part.is_empty()).map(|part| part.to_string()).collect::<Vec<String>>();

        tokens
    }
}


struct FileSystem
{
    root: Trie
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FileSystem
{

    fn new() -> Self
    {
        Self
        {
            root: Trie::new()
        }
    }
    
    fn ls(&self, path: String) -> Vec<String>
    {
        self.root.get_directory_contents(path)
    }
    
    fn mkdir(&mut self, path: String)
    {
        self.root.insert(path)
    }
    
    fn add_content_to_file(&mut self, file_path: String, content: String)
    {
        self.root.append_content(file_path, content)
    }
    
    fn read_content_from_file(&self, file_path: String) -> String
    {
        self.root.get_file_contents(file_path)
    }
}