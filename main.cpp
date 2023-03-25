#include<iostream>
#include"room.hpp"
#include<vector>
using namespace std;

void checkRoomStatus(){

}

int main(){
    
    const int numOfFloors = 4;
    const int roomsPerFloor = 100;

    vector<vector<room>> floors;//vector of all floors

    //store all floors in a vector
    for(int i=0; i<numOfFloors; i++){
        vector<room> rooms; //all rooms on floor

        for(int j=0; j<roomsPerFloor; j++){
            int roomNum = i+1;
            //add rooms to floor
            rooms.push_back(room(roomNum, "Standard Room", false));
        }
        //add floors to floor vector.
        floors.push_back(rooms);
    }

    floors.at(2).at(20).roomStatus();
    
}