#ifndef RESULT_H
#define RESULT_H

enum Result
{
    Success = 0,
    LoadError = 100,
    AddError = 200,
    ModifyError = 300,
    MoveError = 400,
    PrintError = 500,
    SearchError = 600,
    SelectError = 700,
    EditError = 800,
    CommandError = 777,
};
#endif