#pragma warning(disable:4996)
#include"one.h"
using namespace std;

Manager::~Manager()
{
    if (fin.is_open())
        fin.close();

}

void Manager::Run(const char* filepath)
{
    fin.open(filepath);
    if (!fin)
    {
        fout << "File open error" << endl;
        return;
    }
    char cmd[32];
    while (!fin.eof())
    {
        fin.getline(cmd, 100);
        char* command = strtok(cmd, " ");
        if (command == NULL)
            continue;

        if (strcmp(command, "LOAD") == 0) {
            fout << "=======LOAD=======" << endl;
            Loaded_List* list= new Loaded_List;
            string num, name;
            fread.open("filenumbers.csv", ios::in);
            while (!fread.eof()) {
                getline(fread, num, ',');
                getline(fread, name, '\n');

                cout << name << "/" << num << endl;
                make_list( name, num);
            }
            fread.close();
            cout << "===================" << endl;
        }
    }
}


void Manager::make_list(string name,string num)
{
    
    Loaded_List_Node * newNode  = new Loaded_List_Node;
    newNode->name = name;
    newNode->num = num;

    if (List_head->Node== NULL) {
        List_head->Node = newNode;
        return;
    }
    if (List_head->Node->next == NULL) {
        List_head->Node->next = newNode;
        newNode->prev = List_head->Node;
    }
    while (1) {
        if (List_head->Node->next == NULL)
            break;
        List_head->Node = List_head->Node->next;
    }
    List_head->Node->next = newNode;
    newNode->prev = List_head->Node;
    return;
}


int main(int argc, char* argv[])
{
    const char* commandFilepath = "command.txt";
    if (argc > 1)
        commandFilepath = argv[1];

    Manager m;
    m.Run(commandFilepath);

    return 0;
}