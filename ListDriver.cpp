#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream initFollowers("followersData.txt"); //create input file stream object
    string currFollower;
    vector<string> unsortedFollowerVector;
   
    //initial file read, add to unsortedFollowerArr
    if(initFollowers.is_open()) {
        while (getline(initFollowers, currFollower)) {

            unsortedFollowerVector.push_back(currFollower);
        }
    } 
    else {
        cout << "File not open" << endl;
    }

    int profilePicCount = 0;
    vector<string> followerUsernameVector;

    //go through unsortedFollowerArr 
    for (int i = 0; i < unsortedFollowerVector.size(); i++)
    {
        if (unsortedFollowerVector[i].find("profile picture") != string::npos)
        {
            followerUsernameVector.push_back(unsortedFollowerVector[i+1]);
            cout << unsortedFollowerVector[i+1] << endl;
            profilePicCount++;
        }
    }
    //now we have just the userrnames of all the followers

    //TODO sort alphabetically
    string temp;
    // for(int i = 0; i < followerUsernameArr.size(); i++)
    // {
    //     for(int j = i+1; j < followerUsernameArr.size(); j++)
    //     {
    //         if(followerUsernameArr[i] < followerUsernameArr[j])
    //         {
    //             temp = followerUsernameArr[i];
    //             followerUsernameArr[i] = followerUsernameArr[j];
    //             followerUsernameArr[j] = temp;
    //         }
    //     }
    // }
    sort(followerUsernameVector.begin(), followerUsernameVector.end());

    //print out sorted list
    for(int i = 0; i < followerUsernameVector.size(); i++)
    {
        cout << followerUsernameVector[i] << endl;
    }
    
    // cout << unsortedFollowerArr.size() << endl;
    // cout << unsortedFollowerArr.back() << endl;
    // cout << profilePicCount << endl;

    return 0;
}


