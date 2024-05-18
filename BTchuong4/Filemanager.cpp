#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
class Folder
{
private:
    string name;
    Folder *left;
    Folder *right;
    vector<string> files;

public:
    Folder(string folderName) : name(folderName), left(nullptr), right(nullptr) {}
    void addFile(string fileName)
    {
        files.push_back(fileName);
    }
    Folder *addChildFolder(string folderName)
    {
        Folder *newFolder = new Folder(folderName);
        newFolder->left = left;
        left = newFolder;
        return newFolder;
    }
    Folder *addPeerFolder(string folderName)
    {
        Folder *newFolder = new Folder(folderName);
        newFolder->right = right;
        right = newFolder;
        return newFolder;
    }
    void getPeerfolders()
    {
        if (right)
        {
            cout << right->name << endl;
            right->getPeerfolders();
        }
    }
    void getChildItems()
    {
        cout << "Folder: " << name << endl;
        left->getPeerfolders();
        cout << "Files: " << name << endl;
        for (auto file : files)
            cout << file << endl;
    }
    Folder *findFolder(string target)
    {
        if (name == target)
            return this;
        Folder *found = nullptr;
        if (left)
        {
            found = left->findFolder(target);
        }
        if (found)
        {
            return found;
        }
        if (right)
        {
            right->findFolder(target);
        }
        return found;
    }
};
Folder *insert(Folder *root, string name, bool type)
{
    if (root == nullptr)
    {
        return root;
    }
    Folder *newFolder = new Folder(name, type);
    new->right = root->right;
    root->right = newFolder;
    return newFolder;
}
int main()
{
    Folder *current;
    Folder root("root");
    root.addFile("File1");
    root.addFile("File2");
    root.addChildFolder("Sub1");
    current = root.addChildFolder("Sub2");
}