#pragma warning(disable : 4996)
#include "Manager.h"
#define CHECK 256
Manager::~Manager()
{
    if (fin.is_open())
        fin.close();
    if(fout.is_open())
        fout.close();
}

void Manager::Run(const char* filepath)
{
    fout.open(RESULT_LOG_PATH);
    fout.close();
    fout.open(RESULT_LOG_PATH,ios::out);
    fin.open(filepath);//open command txt
    if (!fin)
    {
        fout << "File open error" << endl;//if file not open print
        return;
    }
    char cmd[100];
    Loaded_List* list = new Loaded_List;
    Database_BST* BST_list = new Database_BST;
    while (!fin.eof())
    {

        fin.getline(cmd, 1000);
        char* command = strtok(cmd, " "); //get command
        if (command == NULL)
            continue;
        if (strcmp(command, "LOAD") == 0) //if command = LOAD
        {
            result = Load(filepath, list); // make linked list
            if (result != 0) {// if liked list error
                PrintError(result);//go to printerror function
            }
            
            fout << "===================" << endl;
        }
        else if (strcmp(command, "ADD") == 0)// if command = ADD make 2D linked list
        {
            command = strtok(NULL, " ");//get file name
            string dir = command;//file name into dir
            command = strtok(NULL, "\n");//get csv file name
            string csv_name = command;//csv name into csv_name
            string add_path = "./" + dir + "/" + csv_name;//path

            result = ADD(filepath, list, dir, add_path);//go to ADD function
            if (result != 0) {//if result not success
                PrintError(result);//go to printerror
            }
            else {
                fout << "=======ADD=======" << endl;
                fout << "SUCCESS" << endl;
            }
            fout << "==================" << endl;

        }
        else if (strcmp(command, "MODIFY") == 0) {// if command = MODIFY 
            char* change_num;
            command = strtok(NULL, " ");//get file name
            string dir = command;//file name into dir
            command = strtok(NULL, "\"");//get img name
            string img_name = command;//img name into img_name
            command = strtok(NULL, " ");//get num
            string num = command;//num into num
            int int_num = atoi(num.c_str());//string num change integer num
            result = MODIFY(filepath, list, dir, img_name, int_num);//go to MODIFY function
            if (result == 0) {//if result = Success
                fout << "=======MODIFY=======" << endl;
                fout << "SUCCESS" << endl;
            }
            else
                PrintError(result);
            fout << "==================" << endl;
        }
        else if (strcmp(command, "MOVE") == 0) {// if command MOVE

            result = MOVE(filepath, list, BST_list, nodecount);//go to MOVE function
            if (result == Success) {//if result = success
                fout << "=======MOVE=======" << endl;
                fout << "SUCCESS" << endl;
            }
            else {
                PrintError(result);
            }
            fout << "==================" << endl;
            nodecount = 0; //node is 0

        }
        else if (strcmp(command, "PRINT") == 0) {//if command PRINT
            result = PRINT(BST_list);//go to PRINT function
            
        }
        else if (strcmp(command, "SEARCH") == 0) {//if command SEARCH
            command = strtok(NULL, "\"");//get word
            string word = command;//word into word
            result = SEARCH(BST_list, word);//go to SEARCH function

            fout << "==================" << endl;
        }
        else if (strcmp(command, "SELECT") == 0) {//if command SELECT
            Result result;
            command = strtok(NULL, " ");//get num
            string num = command;//num into num
            int int_num = atoi(num.c_str());//string num change int num
            result = SELECT(BST_list, int_num);//go to SELECT 
            if (result == Success) {//if result success
                fout << "===========SELECT============" << endl;
                fout << "SUCCESS" << endl;
            }
            else{
                PrintError(result);//go to printerror function
            }
            fout<<"========================"<<endl;
        }
        else if(strcmp(command,"EDIT")==0){//if command EDIT
            Result result;
            command = strtok(NULL, " ");//get command
            string a = command;//command into a
            if(a=="-l"){//if a -l
                command = strtok(NULL,"\n");//get num
                string b = command;
                int int_num = atoi(b.c_str());//b change integer num into int_num
                result = EDIT(BST_list,a,int_num);//go to EDIT function
                if(result == Success){//if result success
                    fout<<"============EDIT============="<<endl;
                    fout<<"SUCCESS"<<endl;
                }
                else{
                    PrintError(result);//go to printerror function
                }
            }
            else{
                result = EDIT(BST_list,a, 0);//go to EDIT function
                if(result == Success){//result = success
                    fout<<"============EDIT============="<<endl;
                    fout<<"SUCCESS"<<endl;
                }
                else{
                    PrintError(result);//go to printerror function
                }
            }
            fout<<"==========================="<<endl;
        }
        else if(strcmp(command,"EXIT")==0){// if command EXIT
            Database_BST_Node* Node;
            Node = BST_list->getroot();//get root address
            delete_treememory(Node);//delete BST
            if(nodecount>0 ){//if linked list is not deleted
                Loaded_List_Node* Node2;
                Node2 = list->return_head();//get linked list head
                delete_listmemory(Node2);//delete linked list
            }
            fout<<"======EXIT======"<<endl;
            fout<<"SUCCESS"<<endl;
            fout<<"================"<<endl;
        }
        else{
            PrintError(CommandError);//go to printError
            fout<<"======================="<<endl;
            return;
        }
    }
}
void Manager::delete_listmemory(Loaded_List_Node* node){ // delete linked list memory
    Loaded_List_Node* downtemp = node->down;
    Loaded_List_Node* temp = node;
    
    while(1){
        if(node == NULL){//if node null
            if(downtemp==NULL){//if node down null 
                break;//end
            }
            node = downtemp;
            downtemp = downtemp->down;
        }
        node = node->next;
        delete temp;
        temp = node;
    }

   
}
void Manager::delete_treememory(Database_BST_Node* node){//delete tree list memory
    if(node == NULL) return;

    delete_treememory(node->left);//go to node->left
    delete_treememory(node->right);//go to node->right
    delete node;//delete node
}
Result Manager::EDIT(Database_BST* BST_list,string cmd, int num){
    Result result;
    result = BST_list->get_picture(cmd,num);//EDIT img file
    return result;
}
Result Manager::SELECT(Database_BST* BST_list, int num) {//get node address
    Result result;
   result = BST_list->select_bst(BST_list, num);//get node address
    if (result!=0){
        return SelectError ;
    }
    else
        return Success;
}
Result Manager::SEARCH(Database_BST* BST_list, string word) {//SEARCH function
    Result result;
    Stack<Database_BST_Node*> first_stack;//stack 1
    Stack<Database_BST_Node*> output_stack;//stack 2
    Queue<Database_BST_Node*> queue_list;//queue 1
    Database_BST_Node* root = BST_list->getroot();//get bst root address
    first_stack.Push(root);//root push
    while (1) {
        if (first_stack.Isempty() == true) { break; }//if stack1 is empty break
        root = first_stack.Pop();//first tack node address pop into root
        output_stack.Push(root);//push root ouput stack
        if (root->left != NULL) {//if root left != NULL
            first_stack.Push(root->left);//push root->left
        }
        if (root->right != NULL) {//if root right != NULL
            first_stack.Push(root->right);//push root ->right
        }
    }
    while (1) {
        if (output_stack.Isempty() == true) { break; }//if ouputstack is empty break;
        root = output_stack.Pop();//pop output stack into root address
        queue_list.Push(root);//push root address into queue
    }
    int word_size = word.size();//check word size
    fout << "======SEARCH============" << endl;
    while (1) {
        if (queue_list.Isempty() == true) { break; }//if queue is empty break;
        Database_BST_Node* currNode = queue_list.Pop();//queue pop into currNode
        int currNode_name_size = currNode->name.size();//currNode->name size check
        int o[256];
        for (int i = 0; i < 256; i++) {
            o[i] = -1;
        }
        for (int i = 0; i < word_size; i++) {//size count
            o[(int)word[i]] = i;
        }
        int s = 0;
        while (s <= (currNode_name_size - word_size))//exit if you can't navigate any further
        {
            int j = word_size - 1;//if j<0 same string
            while (j >= 0 && word[j] == currNode->name[s + j])//check word, img_name
                j--;
            if (j < 0) {//j<0 is same string so print name, num
                fout << "\"" << currNode->name << "\" /" << currNode->num << endl;
                break;
            }
            else
                s += max(1, j - o[currNode->name[s + j]]);
        }
    }
    return Success;
}
Result Manager::PRINT(Database_BST* BST_list) {//PRINT function
    Result result;
    fout<<"========PRINT===================="<<endl;
    fout.close();
    result = BST_list->print_bst(BST_list);//go to print bst function
    fout.open(RESULT_LOG_PATH,ios::app);
    fout << "==========================" << endl;
    
    return result;
}
Result Manager::MOVE(const char* filepath, Loaded_List* Load_list, Database_BST* BST_list, int nodecount) {//Make BST function
    Result result;
    if (nodecount > 101)
        nodecount = 101;
    nodecount--;
    bool a;
    while (1) {
        tree_nodecount++;
        string name = Load_list->get_name();//get img name
        string filename = Load_list->get_filename();//get dir name
        int num = Load_list->get_num();//get unique num

        if (tree_nodecount >= 300) {//if node > 300 delete smallest unique number node
            BST_list->delete_treenode();
        }
        Load_list->delete_node(); //node delete
        BST_list->make_BST(name, filename, num);//make bst
        a = Load_list->head_check();//if head == null
        if (a == false) {//a == NULL
            break;
        }
    }
    string name = Load_list->get_name();//last node img name
    string filename = Load_list->get_filename();//last node dir name
    int num = Load_list->get_num();//last node unique number
    BST_list->make_BST(name, filename, num);//last node make
    Load_list->delete_head();//last linked list node delete
    return Success;
}
Result Manager::MODIFY(const char* filepath, Loaded_List* Load_list, string filename, string name, int num) {
    result = Load_list->modify_list(name, filename, num);
    return result;
}
void Manager::PrintError(Result result) {
    fout << "==========ERROR=========" << endl;
    fout << result << endl;
    return;
}
Result Manager::ADD(const char* filepath, Loaded_List* Load_list, string dir, string add_path) {//ADD function
    fread.open(add_path, ios::in);
    if (fread.fail()) {
        return AddError;
    }
    string num, name, temp;

    while (!fread.eof()) {

        getline(fread, num, ',');//get unique number
        int int_num = atoi(num.c_str());//string num change integer number
        getline(fread, name, '.');//get img name
        getline(fread, temp, '\n');
        if (nodecount >= 101) {//if node>100
            Load_list->pop_head();//delete head node
        }
        result = Load_list->add_list(name, dir, int_num);//add list
        if (result != 0) {
            return result;
        }
        nodecount++;//node +1
    }
    fread.close();
    return(Success);
}
Result Manager::Load(const char* filepath, Loaded_List* Load_list)//LOAD function
{
    string filename = "img_files";
    string num, name, temp;
    char* change_num;

    fread.open("./img_files/filesnumbers.csv", ios::in);
    if (fread.fail()) {
        return LoadError;
    }
    fout << "=======LOAD=======" << endl;
    while (!fread.eof())
    {
        getline(fread, num, ',');
        int int_num = atoi(num.c_str());//string num change integer
        getline(fread, name, '.');
        getline(fread, temp, '\n');
        if (nodecount >= 101)//if node>100
            Load_list->pop_head();//delete head node
        Load_list->make_list(name, filename, int_num);//make list
        fout<<name<<"/ "<<int_num<<endl;
        nodecount++;
    }
    fread.close();
    return Success;
}