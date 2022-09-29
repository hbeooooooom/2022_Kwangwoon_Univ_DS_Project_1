#include "Manager.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
Manager::~Manager()
{
    if (fout.is_open())
        fout.close();

    if (ferr.is_open())
        ferr.close();
}

void Manager::Run(const char *filepath)
{
    
    fout.open(RESULT_LOG_PATH);
    ferr.open(RESULT_LOG_PATH);

    fin.open(filepath);
    if (!fin)
    {
        fout << "File open error" << endl;
        return;
    }
    Loaded_List* List;
    char cmd[32];
    while (!fin.eof())
    {
        fin.getline(cmd, 100);
        char *command = strtok(cmd, " ");
        if (command == NULL)
            continue;

        if(strcmp(command,"LOAD")==0){
            fout<<"=======LOAD======="<<endl;
            List->read_csv_file();
        }
    }
}
void Manager::PrintError(Result result)
{
    ferr << "Error code: " << result << std::endl;
}



