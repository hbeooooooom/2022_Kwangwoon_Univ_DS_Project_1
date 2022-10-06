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
    Loaded_List_Node *queue_list; 
    Database_BST *BST_list = new Database_BST;
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
            else 
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
            char* change_num;
            command= strtok(NULL," ");
            string dir=command;
            command=strtok(NULL, "\"");
            string img_name = command;
            command= strtok(NULL," ");
            string num = command;
            int int_num=atoi(num.c_str());
            result = MODIFY(filepath, list,dir,img_name,int_num);
            if(result == 0){
                cout<<"=======MODIFY======="<<endl;
                cout<<"SUCCESS"<<endl;
            }
            else
                PrintError(result);
            cout<<"=================="<<endl;
        }
        else if(strcmp(command,"MOVE")==0){
            
            result=MOVE(filepath,list,BST_list,nodecount);
            if(result==Success){
                cout<<"=======MOVE======="<<endl;
                cout<<"SUCCESS"<<endl;
            }
            else{
                PrintError(result);
            }
            cout<<"=================="<<endl;
            nodecount = 0;
            
        }
        else if(strcmp(command,"PRINT")==0){
            result = PRINT(BST_list);
        }
        else if(strcmp(command,"SEARCH")==0){
            command =strtok(NULL,"\"");
            string word = command;
            
            result = SEARCH(BST_list,word);
            if(result==Success){
                cout<<"=======MOVE======="<<endl;
                cout<<"SUCCESS"<<endl;
            }
            else{
                PrintError(result);
            }
            cout<<"=================="<<endl;
        }
        else if(strcmp(command,"SELECT")==0){
            command = strtok(NULL, " ");
            string num=command;
            int int_num=atoi(num.c_str());
            result = SELECT(int_num);
        }
    }
    //print(list);
}

Result Manager::SEARCH(Database_BST* BST_list, string word){
    Result result;
    stack<Database_BST_Node> first_stack;
    stack<Database_BST_Node> output_stack;
    queue<Database_BST_Node> queue_list;
    result= BST_list->postorder(word);

    if(result != Success){
        return SearchError;
    }
    return Success;

}

Result Manager::SELECT(int num){

}

Result Manager::PRINT(Database_BST* BST_list){
    Result result;
    result = BST_list->print_bst(BST_list);
    return result;
}

Result Manager::MOVE(const char*filepath, Loaded_List* Load_list, Database_BST* BST_list,int nodecount){
    Result result;
    if(nodecount>101)
        nodecount=101;
    nodecount--;
    bool a;
    while(1){
        tree_nodecount++;
        string name = Load_list->get_name();
        string filename = Load_list->get_filename();
        int num = Load_list->get_num();
        
        if(tree_nodecount>=300){
           BST_list-> delete_treenode();
        }
        Load_list->delete_node(); //end node delete
        BST_list->make_BST(name,filename,num);
         a = Load_list->head_check();
        if(a==false){
            break;
        }
    }
    string name = Load_list->get_name();
    string filename = Load_list->get_filename();
    int num = Load_list->get_num();
    
    
    BST_list->make_BST(name,filename,num);

    Load_list->delete_head();
    return Success;
}

Result Manager::MODIFY(const char*filepath, Loaded_List* Load_list,string filename,string name,int num ){
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
        cout<<"파일을 못염"<<endl;
        return AddError;
    }
    string num, name,temp;
   
    while(!fread.eof()){
        
        getline(fread, num, ',');
        int int_num=atoi(num.c_str());
        getline(fread, name, '.');
        getline(fread, temp, '\n'); 
        if(nodecount>=101){
            Load_list->pop_head();
        }
        result = Load_list->add_list(name,dir,int_num);
        if(result!=0){
            return result;
        }
       nodecount++;
    }
    fread.close();
    return(Success);
}

Result Manager::Load(const char *filepath, Loaded_List *Load_list)
{
    string filename = "img_files";
    string num, name,temp;
    char* change_num;
    
    fread.open("./img_files/filesnumbers.csv", ios::in);
    if(fread.fail()){
        return LoadError;
    }
    cout<<"=======LOAD======="<<endl;
    while (!fread.eof())
    {
    
        getline(fread, num, ',');
        int int_num=atoi(num.c_str());
        getline(fread, name, '.');
        getline(fread, temp, '\n');
        if(nodecount>=101)
            Load_list->pop_head();
        Load_list->make_list(name,filename,int_num);
        
        nodecount++;
    }
    fread.close();
    return Success;
}