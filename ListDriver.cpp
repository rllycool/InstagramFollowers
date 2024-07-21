#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

int main() {

    //open files
    ifstream initFollowers("followersData.txt");
    ifstream initFollowing("followingData.txt"); 

    string currFollower;
    vector<string> unsortedFollowerVector;
    vector<string> unsortedFollowingVector;

    //read followerData.txt, add to unsortedFollowerVector
    if(initFollowers.is_open()) {
        while (getline(initFollowers, currFollower)) {
            unsortedFollowerVector.push_back(currFollower);
        }
    } 
    else {
        cout << "File not open" << endl;
    }

    //read followingData.txt, add to unsortedFollowingVector
    if(initFollowing.is_open()) {
        while (getline(initFollowing, currFollower)) {
            unsortedFollowingVector.push_back(currFollower);
        }
    } 
    else {
        cout << "File not open" << endl;
    }




    vector<string> followerUsernameVector = trimVector(unsortedFollowerVector);
    vector<string> followingUsernameVector = trimVector(unsortedFollowingVector);

    int followerCount = followerUsernameVector.size();
    int followingCount = followingUsernameVector.size();

    //print out list
    for(int i = 0; i < followerUsernameVector.size(); i++)
    {
        cout << followerUsernameVector[i] << endl;
    }

    //TODO sort alphabetically
    //sort(followerUsernameVector.begin(), followerUsernameVector.end());
    cout << "What is your Instagram username?" << endl;

    string username;
    cin >> username;

    cout << "--------------------------------" << endl;
    cout << "Hello, " << username << "!" << endl;
    cout << "--------------------------------" << endl;

    //print out follower count and following count
    cout << "You have " << followerCount << " followers." << endl;
    cout << "You are following " << followingCount << " people." << endl;

    return 0;
}


