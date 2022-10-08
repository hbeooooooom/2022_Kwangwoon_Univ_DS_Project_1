#include "BinarySearchTree.h"
#pragma warning(disable:4996)

Result Database_BST::get_picture(string cmd,int nums)
{
    int width = 256, height = 256;

    FILE* input_file, * output_file;

    unsigned char input_data[256][256];
    unsigned char output_data[256][256];
    string path,newpath;
    path = "./"+Select_node->dir+"/"+Select_node->name+".RAW";//make raw file path
    const char* path_char = path.c_str();
    input_file = fopen(path_char, "rb");//open raw file
    if (input_file == NULL)
    {
        return EditError;
    }
    fread(input_data, sizeof(unsigned char), width * height, input_file);
    if(cmd=="-f"){// if cmd -f
    newpath = "./Result/"+Select_node->name+"_flipped.RAW";//after make file name
    const char* new_path = newpath.c_str();
    Edit_Stack<unsigned char> pic_stack;//make stack
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            pic_stack.Push(input_data[i][j]);//push data into stack
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            output_data[i][j] = pic_stack.Pop(); //pop data into output data

    output_file = fopen(new_path, "wb");
    fwrite(output_data, sizeof(unsigned char), width * height, output_file);//make raw file
    fclose(input_file);
    fclose(output_file);
    return Success;
    }
    else if(cmd=="-l"){//if command -l
        newpath = "./Result/"+Select_node->name+"_adjusted.RAW";
        const char* new_path = newpath.c_str();
        IMG_Queue<unsigned char> pic_queue;//make queue
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                pic_queue.Push(input_data[i][j]);//push data into queue

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                output_data[i][j] = nums + pic_queue.Pop();//pop data into ouput data

        output_file = fopen(new_path, "wb");
        fwrite(output_data, sizeof(unsigned char), width * height, output_file);//make raw file
        fclose(input_file);
        fclose(output_file);
        return Success;
    }
    else if(cmd=="-r"){
        unsigned char output_data[128][128];
        newpath = "./Result/"+Select_node->name+"_resized.RAW";
        const char* new_path = newpath.c_str();
        IMG_Queue<unsigned char> pic_queue;//make queue
        for (int i = 0; i < height; i+=2)
            for (int j = 0; j < width; j+=2)
                pic_queue.Push((input_data[i][j]+input_data[i][j+1]+input_data[i+1][j]+input_data[i+1][j+1])/4);
                //push data into queue Add adjacent 4 spaces and divide by 4
            
        for (int i = 0; i < height/2; i++)
            for (int j = 0; j < width/2; j++)
                output_data[i][j] = pic_queue.Pop();//pop data into output data
        output_file = fopen(new_path, "wb");
        fwrite(output_data, sizeof(unsigned char), width * height, output_file);
        fclose(input_file);
        fclose(output_file);
        return Success;
    }
}