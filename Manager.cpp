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
    Loaded_List *list= new Loaded_List;
    while (!fin.eof())
    {
        
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
            command = strtok(NULL," ");
            string dir = command;
            command = strtok(NULL,"\n");
            string csv_name = command;
            string add_path= "./"+dir+"/"+csv_name;
            
            ADD(filepath, list,dir,add_path);
            cout<<"=================="<<endl;
        }
        
        print(list);
    }

    
}
void Manager::print(Loaded_List* Load_list){
    Load_list->printnode();
}
void Manager::PrintError(Result result){
    cout<<result<<endl;
    return;
}
Result Manager::ADD(const char* filepath,Loaded_List* Load_list,string dir,string add_path){
    fread.open(add_path,ios::in);
    if(fread.fail()){
        cout<<"========ERROR========"<<endl;
        return AddError;
    }
    char cmd[32];
    //Load_list->make_first_node(dir);//make first file dir
    //bool error_check = Load_list->add_chek_up();
    //cout<<error_check<<endl;//에러코드 숫자 확인용 삭제할것
    /*if(error_check!=true){//만약 반환값이 1이 아니면
        cout<<200<<endl;
        return AddError;
    }*/
    string num, name,temp;
    while(!fread.fail()){
        nodecount++;
        getline(fread, num, ',');
        getline(fread, name, '.');
        getline(fread, temp, '\n');
        cout << name << "/" << num << endl;// 이건 나중에 지우기
        Load_list->add_list(name,dir,num);
    }
    return(Success);
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
   
    //Load_list->make_first_node(filename);
    
    while (!fread.eof())
    {
        nodecount++;
        getline(fread, num, ',');
        getline(fread, name, '.');
        getline(fread, temp, '\n');
        cout << name << "/" << num << endl;
        //stringstream ssInt(num);
        Load_list->make_list(name,filename,num);
        
    }
    fread.close();
    return(Success);
}