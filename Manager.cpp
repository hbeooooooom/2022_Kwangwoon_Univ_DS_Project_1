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
    char cmd[100];
    Loaded_List *list= new Loaded_List;
    while (!fin.eof())
    {
        
        fin.getline(cmd, 1000);
        char *command = strtok(cmd, " ");
        if (command == NULL)
            continue;
        if (strcmp(command, "LOAD") == 0)
        {
            result = Load(filepath, list);
            if(result!=0){
                PrintError(result);
            }
            list->printnode();
            cout << "===================" << endl;
        }
        else if(strcmp(command, "ADD")==0)
        {
            command = strtok(NULL," ");
            string dir = command;
            command = strtok(NULL,"\n");
            string csv_name = command;
            string add_path= "./"+dir+"/"+csv_name;
            
            result = ADD(filepath, list,dir,add_path);
            if(result!=0){
                PrintError(result);
            }
            else{
                cout<<"=======ADD======="<<endl;
                cout<<"SUCCESS"<<endl;
            }
            cout<<"=================="<<endl;
        }
        else if(strcmp(command,"MODIFY")==0){
            
            command= strtok(NULL," ");
            string dir=command;
            command=strtok(NULL, "\"");
            string img_name = command;
            command= strtok(NULL," ");
            string num = command;
            result = MODIFY(filepath, list,dir,img_name,num);
            if(result == 0){
                cout<<"=======MODIFY======="<<endl;
                cout<<"SUCCESS"<<endl;
            }
            else
                PrintError(result);
            cout<<"=================="<<endl;
        }
        else if(strcmp(command,"MOVE")==0){
            
        }
        
    }
    print(list);
}

Result Manager::MODIFY(const char*filepath, Loaded_List* Load_list,string filename,string name,string num ){
    result = Load_list->modify_list(name,filename,num);
    return result;
}
void Manager::print(Loaded_List* Load_list){
    Load_list->printnode();
}
void Manager::PrintError(Result result){
    cout<<"==========ERROR========="<<endl;
    cout<<result<<endl;
    return;
}
Result Manager::ADD(const char* filepath,Loaded_List* Load_list,string dir,string add_path){
    fread.open(add_path,ios::in);
    if(fread.fail()){
        return AddError;
    }
    string num, name,temp;
    while(!fread.eof()){
        nodecount++;
        getline(fread, num, ',');
        getline(fread, name, '.');
        getline(fread, temp, '\n'); 
        if(nodecount>=101){
            Load_list->pop_head();
        }
        result = Load_list->add_list(name,dir,num);
        if(result!=0){
            return result;
        }
       
    }
    return(Success);
}



Result Manager::Load(const char *filepath, Loaded_List *Load_list)
{
    string filename = "img_files";
    string num, name,temp;
    
    fread.open("./img_files/filesnumbers.csv", ios::in);
    if(fread.fail()){
        return LoadError;
    }
   
    //Load_list->make_first_node(filename);
    cout<<"=======LOAD======="<<endl;
    while (!fread.eof())
    {
        nodecount++;
        getline(fread, num, ',');
        getline(fread, name, '.');
        getline(fread, temp, '\n');
        if(nodecount>=101)
            Load_list->pop_head();
        Load_list->make_list(name,filename,num);
        
    }
    fread.close();
    return Success;
}