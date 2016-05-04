//
//  main.cpp
//  Barlow_Lab
//
//  Created by Milad Ghoreishi on 5/4/16.
//  Copyright © 2016 Milad Ghoreishi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <exception>
#include <string>



using namespace std;

int main(int argc, const char * argv[]) {
    
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else cout << "Unable to open file";

    //    char dir[PATH_MAX];
    string fileName = "a";
    string line = "";
    int mapReadCount = 0;
    ofstream outfile;
    outfile.open ("example.txt");
    outfile << "Writing this to a file.\n";
    outfile.close();
    
    ifstream myFile;
    myFile.open("a.txt");
//    cout << "Please input the file name:";
//    cin >> fileName;
//    getcwd(dir, PATH_MAX);
//    string temp(dir);
//    cout << temp << " " << temp.size();

    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            getline(myFile, line);
            char temp [line.size()];
            for (unsigned i=0; i < line.size(); i++){
                temp[i] = line[i];
            }
            if (temp[0] != '@') {
                char* token = strtok(temp, " ");
                while (token != nullptr)
                {
                    token = strtok(nullptr, " ");
                }

            }
        }
        
    }
    else
        cerr << "Couldn't open the file: " << fileName.c_str() << endl;
        //throw exception(string("Couldn't open the file: " + fileName).c_str());
    myFile.close();

    return 0;
}
