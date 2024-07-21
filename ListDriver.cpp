#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// TRIM VECTOR method
//go through vector and grab just the usernames of the followers
vector<string> trimVector(vector<string> &vec) {
    vector<string> newVec;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].find("profile picture") != string::npos)
        {
            newVec.push_back(vec[i+1]);
        }
    }
    return newVec;
}

// READ FILE method
//read file line by line and add contents to vector
vector<string> readFile(string filename) {
    ifstream file(filename);
    string currFollower;
    vector<string> fileContent;

    if(file.is_open()) {
        while (getline(file, currFollower)) {
            fileContent.push_back(currFollower);
        }
    } 
    else {
        cout << "File not open" << endl;
    }

    return fileContent;
}








int main() {
    
    //read files
    vector<string> unsortedFollowerVector = readFile("followersData.txt");
    vector<string> unsortedFollowingVector = readFile("followingData.txt");
 
    //trim contents
    vector<string> followerUsernameVector = trimVector(unsortedFollowerVector);
    vector<string> followingUsernameVector = trimVector(unsortedFollowingVector);

    //determine sizes
    int followerCount = followerUsernameVector.size();
    int followingCount = followingUsernameVector.size();

    //print out list
    for(int i = 0; i < followingUsernameVector.size(); i++)
    {
        cout << followingUsernameVector[i] << endl;
    }

    //TODO sort alphabetically
    //sort(followerUsernameVector.begin(), followerUsernameVector.end());
    sort(followingUsernameVector.begin(), followingUsernameVector.end());

    //print out (hopefully) sorted list
    for(int i = 0; i < followingUsernameVector.size(); i++)
    {
        cout << followingUsernameVector[i] << endl;
    }

    //output to the user
    cout << "What is your Instagram username?" << endl;

    string username;
    cin >> username;

    cout << "--------------------------------" << endl;
    cout << "Hello, " << username << "!" << endl;
    cout << "--------------------------------" << endl;
    cout << "You have " << followerCount << " followers." << endl;
    cout << "You are following " << followingCount << " people." << endl;
    cout << "--------------------------------" << endl;
    
    return 0;
}


