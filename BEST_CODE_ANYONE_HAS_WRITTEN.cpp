
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

struct country{
    string name;
    vector<float> number;
};

int main(){
    vector<country> data;
    ifstream FILE("renewable-share-energy.csv");
    string line;
    data.resize(300);
    int country_count = 0;
    getline(FILE, line); // skip header
    while (getline(FILE, line)) {
        int count = 0;
        string country_name;
        string percentage;

        for(size_t i = 0 ;i<line.size();i++){
            if(line[i] == ',' && count == 0){
                country_name = line.substr(0,i);
                cout<<country_name<<endl;
            }
            else if(line[i] == ',' && count == 2){
                percentage = line.substr(i+1,line.size()-1);
                cout<<percentage<<endl;
            }
            if(line[i] == ','){
                count++;
            }
        }

        if(data[country_count].name == country_name)
        {
            data[country_count].number.push_back(stof(percentage));
        }
        else{
            country_count++;
            country new_country;
            new_country.number.push_back(stof(percentage));
            new_country.name = country_name;
            data[country_count] = new_country;
            
        }
    }
    FILE.close();

    ofstream output("wide_data.csv");
    for(int i = 0 ; i < country_count; i++){
        output << data[i].name;
        output << ',';
        for(size_t j = 0; j < data[i].number.size();j++){
            output << data[i].number[j];
            output << ',';

        }
        output<<endl;
    }
    


}




