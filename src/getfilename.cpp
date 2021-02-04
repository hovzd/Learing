#include<iostream>
#include<fstream>
#include<dirent.h>
#include<vector>

using namespace std;

bool get_filelist_from_dir(std::string _path, std::vector<std::string>& _files)
{
	DIR* dir;	
	dir = opendir(_path.c_str());
	struct dirent* ptr;
	std::vector<std::string> file;
	while((ptr = readdir(dir)) != NULL)
	{
		if(ptr->d_name[0] == '.') {continue;}
		file.push_back(ptr->d_name);
	}
	closedir(dir);
	//sort(file.begin(), file.end());
	_files = file;
}

int main()
{
    ofstream out("register.txt",ios::out);
    if (!out.is_open())
	{
		std::cout << "文件打开失败" << std::endl;
	}

    const std::string Img_path = "collection_faces_/collection_faces_";

    std::vector<std::string> subimgfiles;
    get_filelist_from_dir(Img_path, subimgfiles);

    if(subimgfiles.size() == 0)
    {
        std::cout<<Img_path<<"has no face image"<<std::endl;
        return 0;
    }
    else
    {
        for (auto imgfile:subimgfiles)
        {
            int flag = 1;
            string::size_type idx;
            string::size_type idx1;        
            idx = imgfile.find("jpg");
            idx1 = imgfile.find("jpeg");
            if(idx1 == string::npos and idx == string::npos)          
                flag = 0;
            if(flag == 0)
            {
                std::cout << imgfile << "is not image format" << std::endl;
                continue;
            }
            out << imgfile << "\n";
        }
    }
    out.close();
    return 0;
}

