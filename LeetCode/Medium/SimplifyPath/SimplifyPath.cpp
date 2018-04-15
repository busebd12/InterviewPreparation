#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string simplifyPath(string path)
{
    if(path.empty() || path[0]!='/')
    {
        return "";
    }

    vector<string> directories;

    stack<string> s;

    string delimiter("/");

    size_t last=0;

    size_t next=0;

    //Split the path into its parts (directories) based on the delimiter "/"
    while((next=path.find(delimiter, last))!=string::npos)
    {
        auto directory=path.substr(last, next-last);

        directories.emplace_back(directory);

        last=next+1;
    }

    directories.emplace_back(path.substr(last));

    for(auto directory : directories)
    {
        //The ".." indicates that we should go back up a directory so we remove the previous directory from the stack
        if(directory==".." && !s.empty())
        {
            s.pop();
        }
        //if the directory is not the current one, we aren't going one level up in the directory tree, and it's not an empty directory
        else if(directory!="." && directory!=".." && !directory.empty())
        {
            s.push(directory);
        }
    }

    if(s.empty())
    {
        return "/";
    }

    string simplifiedPath{};

    while(!s.empty())
    {
        string topLevel="/" + s.top();

        simplifiedPath=topLevel + simplifiedPath;

        s.pop();
    }

    return simplifiedPath;
}

int main()
{
    string path="/a/../b/c/";

    simplifyPath(path);
}