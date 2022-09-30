#pragma warning(disable : 4996)
#include "Manager.h"
Manager::~Manager()
{
    if (fin.is_open())
        fin.close();
}

void Manager::Run(const char *filepath)
{
    
    fin.open(filepath);
    if (!fin)
    {
        cout << "File open error" << endl;
        return;
    }
    char cmd[32];
    while (!fin.eof())
    {
        fin.getline(cmd, 100);
        char *command = strtok(cmd, " ");
        if (command == NULL)
            continue;
        if (strcmp(command, "LOAD") == 0)
        {
            cout << "=======LOAD=======" << endl;
            Loaded_List *list= new Loaded_List;
            Load(filepath, list);
            
            cout << "===================" << endl;
        }
        
    }
}

void Manager::PrintError(Result result){
    cout<<result<<endl;
    return;
}

Result Manager::Load(const char *filepath, Loaded_List *Load_list)
{
    string filename = "img_files";
    string num, name,temp;
    fread.open("./img_files/filesnumbers.csv", ios::in);
    if(fread.fail()){
        cout<<"=======ERROR======="<<endl;
        PrintError(LoadError);
    }
    while (!fread.eof())
    {
        nodecount++;
        getline(fread, num, ',');
        getline(fread, name, '.');
        getline(fread, temp, '\n');
        cout << name << "/" << num << endl;
        Load_list->make_list(name,filename,num);
        
    }
    fread.close();
    return( Success);
}