#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;
    list<pair<int, int>> *adj;

  public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    vector<int> shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
vector<int> Graph::shortestPath(int src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set<pair<int, int>> setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;

    /* Looping till all shortest distance are finalized 
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in 
                    our set, so removing it and inserting again 
                    with updated less distance.   
                    Note : We extract only those vertices from Set 
                    for which distance is finalized. So for them,  
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

//Utiliy functions to print the distance vector
void display(vector<int> d)
{
    for (int i = 0; i < d.size(); i++)
    {
        cout << i << "\t\t" << d[i] << endl;
    }
}

vector<int> d;
pair<int, int> tmp;

class Truck
{
  public:
    int fuel, cap, capDefault, price, fuelDefault;
    int trucksUsed = 0, travelled = 0, p = 0, c = 0;

    Truck(int f, int c, int p)
    {
        fuel = fuelDefault = f;
        cap = capDefault = c;
        price = p;
    }

    //To find the closest cargo location
    pair<int, int> closestCargo(vector<int> flag, vector<int> d)
    {
        pair<int, int> min = make_pair(0, INF);
        for (int i = 0; i < d.size(); i++)
        {
            if (flag[i])
            {
                if (d[i] < min.second)
                    min = make_pair(i, d[i]);
            }
        }
        return min;
    }

    //this function describes what happens when we pickup a cargo
    int pick(pair<int, int> tmp, vector<int> &flag)
    {
        travelled += tmp.second;
        fuel -= tmp.second;

        if (cap >= flag[tmp.first])
        {
            ++p;
            cap -= flag[tmp.first];
            flag[tmp.first] = 0;
        }
        else
        {
            flag[tmp.first] -= cap;
            cap = 0;
        }
        return tmp.first;
    }

    //decribes what happens when we drop all picked up cargo
    int drop(int src, int des, Graph &g)
    {
        d = g.shortestPath(src);
        travelled += d[des];
        c += p;
        p = 0;
        return -1;
    }

    int start(int src, vector<int> &flag, Graph &g)
    {
        d = g.shortestPath(src);
        tmp = closestCargo(flag, d);
        trucksUsed += 1;
        fuel = fuelDefault;
        cap = capDefault;
        return pick(tmp, flag);
    }

    int check(int src, int des, vector<int> &flag, Graph &g)
    {
        d = g.shortestPath(src);
        tmp = closestCargo(flag, d);
        int weight = tmp.second;
        d = g.shortestPath(tmp.first);
        weight += d[des];
        if (fuel >= weight && cap > 0)
            return pick(tmp, flag);
        else
            return drop(src, des, g);
    }
};

//Calculates min-fuel reqd to deliver every package
int minFuel(int src, int des, vector<int> &flag, Graph &g)
{
    vector<int> d1;
    d = g.shortestPath(src);
    int weight = 0;
    for (int i = 0; i < flag.size(); i++)
    {
        if (flag[i])
        {
            d1 = g.shortestPath(i);
            if (d[i] + d1[des] > weight)
                weight = d[i] + d1[des];
        }
    }
    return weight;
}
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    //marking locations with cargo
    vector<int> flag(V, 0);
    flag[1] = flag[7] = flag[6] = flag[5] = 9;
    int nCargo = 4, src = 0, des = 4, u = 0, v = 0;

    int fuel = minFuel(src, des, flag, g);
    cout << "Minimum fuel per truck for this graph is: " << fuel << endl
         << endl;

    //Making Trucks
    Truck small(fuel, 3, 500);
    Truck med(fuel * 1.3, 6, 1500);
    Truck large(fuel * 1.7, 9, 2500);
    Truck xl(fuel * 2, 15, 4500);
    Truck arr[] = {small, med, large, xl};
    string name[] = {"small", "Mid-Sized", "large", "Xtra-Large"};

    for (int i = 0; i < 4; i++)
    {
        //marking locations with cargo
        flag[1] = flag[7] = flag[6] = flag[5] = 9;

        while (arr[i].c != nCargo)
        {
            u = arr[i].start(src, flag, g);
            v = arr[i].check(u, des, flag, g);
            while (v != -1)
                v = arr[i].check(v, des, flag, g);
        }
        cout << "For " << name[i] << " truck" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "distance covered: \t\t" << arr[i].travelled << endl;
        cout << "Trucks Used: \t" << arr[i].trucksUsed << "\t\t"
             << "Hiring Cost: \t$" << (arr[i].price * arr[i].trucksUsed) << endl;
        cout << "Fuel Used: \t" << arr[i].travelled << "\t\t"
             << "Fuel Cost: \t$" << (arr[i].travelled * 50) << endl;
        cout << "\t\t\t\t"
             << "Total Cost: \t$" << (arr[i].price * arr[i].trucksUsed) + (arr[i].travelled * 50) << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl
             << endl;
    }

    return 0;
}