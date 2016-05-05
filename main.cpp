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
#include <vector>


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
    bool flag = false;
    string line = "";
    //int mapReadCount = 0;
    ofstream outfile;
    outfile.open ("example.txt");
    outfile << "Writing this to a file.\n";
    outfile.close();
    string result[100][3];
    vector< vector <string> > twoDimVec;
    vector<string> row;
    
    ifstream myFile;
    myFile.open("a.txt");
    int c = 0;
    int j = 0;
    string emp = "";
    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            getline(myFile, line);

            char temp [line.size()];
            memset(&temp[0], 0, sizeof(temp));          //clearing the char
            
            
            if (line[0] != '@' && line.size() != 0)
            {
                unsigned i=0;
                for (; i < line.size(); i++)
                {
                    temp[i] = line[i];
                }

                char* token;
                if (j == 0 )
                {
                    token = strtok(temp, " ");
                    for (i = 0; token[i] != 0; i++);
                    result[c][j] = token;
                    row.push_back(token);
                    if (line.size() != i)
                        line.erase(0, i+1);
                    else if (line.size() == i)
                        line.erase();
                }
                
                while (j < 3)
                {
                    token = strtok(nullptr, " ");
                    if (line == "")
                        break;
                    result[c][j] = token;
                    row.push_back(token);       //adding the coloumn
                    j++;
                    if (line.size() != i)
                        line.erase(0, i+1);
                    else if (line.size() == i)
                        line.erase();
                }
            }
            else if (line[0] == '@')
            {
                cout << "skiping this line" << endl;
                flag = true;
            }
            
            if (!flag)
            {
                twoDimVec.push_back(row);
                row.clear();
                j = 0;
                c++;
                flag = false;
            }
        }
        
    }
    else
        cerr << "Couldn't open the file: " << fileName.c_str() << endl;
        //throw exception(string("Couldn't open the file: " + fileName).c_str());

    myFile.close();

    cout << "vector result: " << endl;

    cout<< twoDimVec[0][0] << endl;
    cout<< twoDimVec[0][1] << endl;
    cout<< twoDimVec[0][2] << endl;
    
    cout<< twoDimVec[1][0] << endl;
    cout<< twoDimVec[1][1] << endl;
    cout<< twoDimVec[1][2] << endl;
    
    return 0;
}
