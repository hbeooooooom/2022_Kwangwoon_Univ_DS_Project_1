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
        Loaded_List *list= new Loaded_List;
        fin.getline(cmd, 100);
        char *command = strtok(cmd, " ");
        if (command == NULL)
            continue;
        if (strcmp(command, "LOAD") == 0)
        {
            cout << "=======LOAD=======" << endl;
            Load(filepath, list);
            cout << "===================" << endl;
        }
        else if(strcmp(command, "ADD")==0)
        {
            cout<<"=======ADD======="<<endl;
            ADD(filepath, list);
            cout<<"=================="<<endl;
        }
    }
}

void Manager::PrintError(Result result){
    cout<<result<<endl;
    return;
}

Result Manager::Load(const char *filepath, Loaded_List *Load_list)
{
    int i=0;
    string filename = "img_files";
    string num, name,temp;
    int changenum;
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
        //stringstream ssInt(num);
        i=boost::lexical_cast<int>(num);
        Load_list->make_list(name,filename,num);
        
    }
    fread.close();
    return( Success);
}