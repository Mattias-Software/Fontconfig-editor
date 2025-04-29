#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
namespace fs = std::filesystem;
using namespace std;


string path = "/usr/share/fontconfig/conf.avail/";
int input;
string fn_in;
string filename;
string cmd="vim ";
vector <string> paths;
 vector<string>::iterator cfn;
int main()
{
    for (const auto & entry : fs::directory_iterator(path)){
        //std::cout << entry.path()<<"\n";
        paths.push_back(entry.path());
    }
    while(true){
    cout<<"Mattia's software FontConfig editor v1.0"<<endl;
    cout<<"Choose and option:"<<endl;
    cout<<"[1] List all config files\n[2] Edit a config file\n[3] Quit"<<endl;
    cin>>input;

    switch(input) {

        case 1:{

                for (const auto & entry : fs::directory_iterator(path))
                {
                    std::cout << entry.path()<<"\n";
                }
                cout<<endl;
                break;

            }

        case 2:{
                //for (auto i : paths)
                //cout << i << " ";
                cout<<"Type the config file name"<<endl;
                cin>>fn_in;
                filename=path.append(fn_in);
                cfn = find(paths.begin(), paths.end(), filename);
                //if(cfn !=paths.end)
                //cout<<*cfn<<endl;
                //cout << distance(paths.begin(), cfn)<<endl;
                  ifstream inputFile(*cfn);

                if (inputFile.is_open())
                {
                    string line;

                while (getline(inputFile, line))
                    {
                        cout << line << endl;
                    }
                }
                else
                {
                    cout << "Invalid file name" << std::endl;
                }

                inputFile.close();

                cmd=cmd.append(*cfn);

                system(cmd.c_str());

                break;

            }

        case 3:{
                return 0;

            }


    }





     //for (auto s : paths)std::cout << s << "\n";
    }

}
