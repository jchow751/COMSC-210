//LAB 12: Write A Customer Service Simulation
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <iomanip>
using namespace std;

#include <cmath>
#include <ctime>
#include <cstdlib>

struct customer
{
  int arrival;
  int serviceT;
  int serviceTEnd;
  char ID;
};

struct serviceEvent
{
  int server;
  int serviceEnd;
  bool operator<(const serviceEvent& a) const {return a.serviceEnd < serviceEnd;}
};

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX; 
    (randomValue -= probOfnRequests) > 0.0; 
    probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 12: Write A Customer Service Simulation\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // read the input values from a text file, one per line, in the order specified above.
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";  
  int servers;
  float custAvg;
  int maxQue;
  int minService;
  int maxService;
  int stopArrivals;
  int arrivals;
  int nonCustomers = 0;
  int custID = 0;
  char buf[1000];
  
  fin >> servers >> custAvg >> maxQue >> minService >> maxService >> stopArrivals;
  
  cout << "Number of servers:       " << servers << endl;
  cout << "Customer arrival rate:   " << custAvg << " per minute, for " << stopArrivals << " minutes\n";
  cout << "Maximum queue length:    " << maxQue << endl;
  cout << "Minimum service time:    " << minService << endl;
  cout << "Maximum service time:    " << maxService << endl;
  cout.setf(ios::fixed);
  cout << "Expected turn away rate: " << setprecision(2) << custAvg - (servers / ((maxService + minService) / 2.0)) << " per minute, while full\n";
  cout.unsetf(ios::fixed);
  // declare and create and assign arrays and queues to be used in the solution
  srand(time(0));
  rand();
  queue<customer> customers;
  vector<customer> serving(servers);
  vector<bool> serverBusy(servers, false);
  priority_queue<serviceEvent> beingServed;
  list<customer> custServed;
  
  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all service events scheduled to complete at this clock time
    //while (event priority queue is not empty AND clock time of the top service event equals the current clock time)
    while(!beingServed.empty() && beingServed.top().serviceEnd == time)
    {
      //remove the top service event from the priority queue
      serviceEvent tempSE = beingServed.top();
      beingServed.pop();
      
      //determine the server associated with the removed service event
      //set this server's current customer's service end time to the current clock time
      serving[tempSE.server].serviceTEnd = time;
      
      //copy this server's current customer to the served customers queue
      custServed.push_back(serving[tempSE.server]);
      
      //set this server to idle
      serverBusy[tempSE.server] = false;
    }

    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    //if time is less than the time at which new arrivals stop
    if(time < stopArrivals)
    {
      //get the #of of arrivals from the Poisson process (a whole number >= 0) -- see the lecture topic notes!
      arrivals = getRandomNumberOfServiceRequests(custAvg);
      //for each new arrival
      for(int i = 0; i< arrivals; i++)
      {
        //if the wait queue is full
        int cSize = customers.size();
        if(cSize == maxQue)
        {
          //"turn away the customer" by adding one to the count of turned away customers
          nonCustomers++;
        }
        else
        {
          //create a new customer object
          customer a;
          //set its arrival time equal to the current clock time
          a.arrival = time;
          //assign it an ID (A-Z)
          a.ID = (char)('A' + (custID++ % 26));
          //copy the new customer to the wait queue
          customers.push(a);
        }
      }
    }
    
    // for idle servers, move customer from wait queue and begin service
    //for each server
    for(int i = 0; i < servers; i++)
    {
      //if (server is idle AND the wait queue is not empty)
      if(!serverBusy[i] && !customers.empty())
      {
         //remove top customer from wait queue
         //copy it to the server array
         serving[i] = customers.front();
         serverBusy[i] = true;
         customers.pop();
         //set the copied customer's service time to the current clock time
         serving[i].serviceT = time;
         //use random number generation to determing the service time interval for the customer
         int serveTime = minService + rand() % (maxService - minService + 1);
         //create a new service event for the server, for the current clock time PLUS the service time interval
         serviceEvent a = {i, time + serveTime};
         //add the service event to the event priority queue 
         beingServed.push(a);
      }
    }

    // output the summary
    //output the current time
    cout << "Time: " << time << endl;
    //output a heading for the visual prepresentation of the servers and the wait queue
    cout << "---------------------------\n";
    cout << "line now serving wait queue\n";
    cout << "---- ----------- ";
    for(int i = 0; i < 2 + maxQue; i++)
      cout << "-";
    cout << endl;
    //for each server
    for(int i = 0; i < servers; i++)
    {
      //output the server's index number (zero-based)      
      //show the ID of the customer being served by that server (blank if idle) 
      //for server 0 only, show the IDs of customers in the wait queue
      if(i == 0)
      {
        cout << "  " << i << "       ";
        if(serverBusy[i]) cout << serving[i].ID; 
        cout << "       ";
        queue<customer> x = customers;
        for(; !x.empty(); x.pop())
          cout << x.front().ID;
        cout << endl;
      }
      else
      {
        cout << "  " << i << "       ";
        if(serverBusy[i]) cout << serving[i].ID;
        cout << endl;
      }
    }
    cout << "---------------------------\n";
    
    // summarize performance
    //if time is greater than zero
    if(time)
    {
      //iterate over the served customers queue to get the average time between arrival and service end
      float total = 0;
      float avg;      
      typename list<customer>::iterator it;
      for(it = custServed.begin(); it != custServed.end(); it++)
      {         
        total += it->serviceTEnd - it->serviceT;
      }
      avg =  total / custServed.size();
        //and if any, output the average of their "service end time" minus their "arrival time"
      if(!custServed.empty())
      {
        cout.setf(ios::fixed);
        cout << "Avg time: " << setprecision(3) << avg << ". ";
        cout.unsetf(ios::fixed);
      }
      //output the rate of customers turned away as total turned away divided by the current time
      cout.setf(ios::fixed);
      cout << setprecision(3) << "Turned away per minute: " << (1.0 * nonCustomers) / time << endl;
      cout.unsetf(ios::fixed);
      cout << setprecision(6);
    }
    
    // if the user wants to quit, break out of this loop
    cout << "Press ENTER to continue, X-ENTER to exit...\n";
    cin.get(buf, 1000);
    cin.ignore();
    if(buf[0] == 'x' || buf[0] == 'X') break;
  }
}