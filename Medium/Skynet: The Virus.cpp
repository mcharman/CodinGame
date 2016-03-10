#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    vector<int> gatewayNode;
    vector<int> linkNode1;
    vector<int> linkNode2;
    
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        linkNode1.push_back(N1);
        linkNode2.push_back(N2);
        
    }
    
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gatewayNode.push_back(EI);

    }
    
    int x1, y1;
    
    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        x1 = SI;
        int priorityGate;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if(gatewayNode.size() > 1)
        {
            // get nearest gateway node to agent and set to priority
            for(int i = 0; i < gatewayNode.size(); i++)
            {
                for(int j = 0; j < linkNode1.size(); j++)
                {
                    if(gatewayNode[i] == linkNode1[j] && x1 == linkNode2[j])
                    {
                        priorityGate = gatewayNode[i];
                        break;
                    }
                    else if(gatewayNode[i] == linkNode2[j] && x1 == linkNode1[j])
                    {
                        priorityGate = linkNode2[i];
                        break;
                    }
                }
                
            }
        }
        else // only 1 gate
        {
            priorityGate = gatewayNode[0];
        }
        bool flag = false;
        
        for(int i = 0; i < linkNode1.size(); i++) // loops to determine if agent is next to goal node
        {
            if(x1 == linkNode1[i] && linkNode2[i] == priorityGate)
            {
                y1 = priorityGate;
                flag = true;
                break;
            }
            else if(x1 == linkNode2[i] && linkNode1[i] == priorityGate)
            {
                y1 = priorityGate;
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            for(int i = 0; i < linkNode1.size(); i++)
            {
                if(linkNode1[i] == x1)
                {
                    y1 = linkNode2[i];
                }
            }
        }
           
        
        
        cout << x1 << " " << y1 << endl;
        
       // cout << "2 1" << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}
