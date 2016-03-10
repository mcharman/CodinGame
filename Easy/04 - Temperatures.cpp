#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    int closest = 9999;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if(n == 0)
        cout << 0 << endl;
    else
    {
        int m;
        stringstream iss(temps);
        vector<int> numbs;
        while(iss >> m)
            numbs.push_back(m);
            
        for(int i = 0; i < numbs.size(); i++)
        {
            if(abs(numbs[i]) < abs(closest))
                closest = numbs[i];
            if(abs(numbs[i]) == abs(closest))
            {
                if(numbs[i] > closest)
                    closest = numbs[i];
            }    
        }
        cout << closest << endl;
    }
    
    
    

    
    
}
