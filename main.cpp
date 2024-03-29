#include <stdio.h>
#include <math.h>
#include <iostream>
#include <io.h>
#include <string>
#include <vector>
//第一个函数：功能为实现对于一个目录下文件的名称获取操作
using  namespace   std;
void getFiles( string, vector<string>& );
int   main(int argc,  char **argv)
{   vector<string> files;
    getFiles( "argv[1]", files );
    // print the files get
    for  (int  j=0;  j<files.size();  ++j){
        cout << files[j] << endl;
    }
    return   0;
}
void getFiles( string path, vector<string>& files )
{
    //文件句柄
    long  hFile  =   0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if   ((hFile =  _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
    {   do
        {   //如果是目录,迭代之
            //如果不是,加入列表
            if ((fileinfo.attrib &  _A_SUBDIR))
            {
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );
            }
            else{
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
            }
        }  while(_findnext(hFile, &fileinfo) == 0);
                _findclose(hFile);
    }
}

//int main(){
//    printf("hello,world");
//    return 0;
//}