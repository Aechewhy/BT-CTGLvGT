#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
class Folder
{
private:
    string name;
    vector<string> files;
    vector<Folder *> subfolders;
    Folder *parent;

public:
    Folder(string folderName, Folder *Parent = nullptr) : name(folderName), parent(Parent) {}
    ~Folder()
    {
        for (auto folder : subfolders)
            delete folder;
    }
    void addFiles(string fileName)
    {
        files.push_back(fileName);
    }
    void addFolder(string folderName)
    {
        Folder *newFolder = new Folder(folderName, this);
        subfolders.push_back(newFolder);
    }
    void addFolderAtSameLevel(string folderName)
    {
        if (!parent)
        {
        }
    }
    void get_child_items()
    {
        cout << "Subfolders" << endl;
        for (auto subfolder : subfolders)
        {
            cout << subfolder->name << endl;
        }
        cout << "Files:" << endl;
        for (auto file : files)
        {
            cout << file << endl;
        }
    }
    Folder *findSubFolder(string folderName)
    {
        for (auto subfolder : subfolders)
        {
            if (folderName == subfolder->name)
                return subfolder;
        }
        return nullptr;
    }
};