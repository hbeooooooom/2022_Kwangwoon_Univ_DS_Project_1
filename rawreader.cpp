#include "BinarySearchTree.h"
#pragma warning(disable:4996)

Result Database_BST::get_picture(string cmd,int nums)
{
    int width = 512, height = 512;

    FILE* input_file, * output_file;

    unsigned char input_data[512][512];
    unsigned char output_data[512][512];
    cout<<Select_node->name<<endl;
    string path,newpath;
    path = "./"+Select_node->dir+"/"+Select_node->name+".raw";
    newpath = "./Result/"+Select_node->name+"flipped.raw";
    const char* path_char = path.c_str();
    const char* new_path = newpath.c_str();
    input_file = fopen(path_char, "rb");
    cout<<"aa"<<endl;
    if (input_file == NULL)
    {
        printf("File not found!!\n");
        return EditError;
    }

    fread(input_data, sizeof(unsigned char), width * height, input_file);
    if(cmd=="-f"){
    Stack2<unsigned char> pic_stack(width,height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            pic_stack.Push(input_data[i][j]);
            

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            output_data[i][j] = pic_stack.Pop();

    output_file = fopen(new_path, "wb");
    fwrite(output_data, sizeof(unsigned char), width * height, output_file);
    }
    else if(cmd=="-l"){
        
    }

    fclose(input_file);
    fclose(output_file);
}

//void main()
//{
//	FILE* fp_In = nullptr;
//	FILE* fp_Out = nullptr;
//
//	errno_t err_In = fopen_s(&fp_In, "./snoopy.raw", "rb");
//	if (0 == err_In)
//	{
//		//////////////////////////////////////////////////////////////////////
//		errno_t err_Out = fopen_s(&fp_Out, "./snoopy_change.raw", "wb");
//		if (0 == err_Out)
//		{
//			char	ch = 0;
//			// ���� ������ ������ ����
//
//			while (true)
//			{
//				int iCnt = fread(&ch, sizeof(char), 1, fp_In);
//				//ch += 10;
//				if (1 > iCnt)
//					break;
//				fwrite(&ch, sizeof(char), 1, fp_Out);
//			}
//
//
//			fclose(fp_Out);
//		}
//
//		//////////////////////////////////////////////////////////////////////
//
//		fclose(fp_In);
//	}
//	
//}