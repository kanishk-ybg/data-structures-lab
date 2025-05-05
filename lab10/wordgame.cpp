
//Program to implement codeforces word game

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve()
{
    int n;
    cout<<"Enter number of words per player:    ";
    cin >>n;
    vector<string> p1(n);
    vector<string> p2(n);
    vector<string> p3(n);
    unordered_map<string , int> wordfreq;


    //initializing the player arrays
    cout<<"Enter Player 1's words:  ";
    for (int i=0 ; i<n ; i++)
    {
        cin>> p1[i];
        wordfreq[p1[i]]++;

    }

    cout<<"Enter Player 2's words:  ";
    for (int i=0 ; i<n ; i++)
    {
        cin>> p2[i];
        wordfreq[p2[i]]++;

    }
    cout<<"Enter Player 3's words:  ";

    for (int i=0 ; i<n ; i++)
    {
        cin>> p3[i];
        wordfreq[p3[i]]++;

    }

    int score1,score2,score3;
    score1=0;
    score2=0;
    score3=0;

    for (int i=0 ; i<n ; i++)
    {
        //Checking for unique words
        if( wordfreq[p1[i]]==1 )
        {
            score1+=3;
        }
        if( wordfreq[p2[i]]==1 )
        {
            score2+=3;
        }

        if( wordfreq[p3[i]]==1 )
        {
            score3+=3;
        }




        //Checking for words that have been repeated once
        if( wordfreq[p1[i]]==2 )
        {
            score1+=1;
        }
        if( wordfreq[p2[i]]==2 )
        {
            score2+=1;
        }

        if( wordfreq[p3[i]]==2 )
        {
            score3+=1;
        }


    }



    cout<<score1 <<" " << score2 <<" " << score3 <<endl <<endl;
    return 0;



}

int main()
{
    int tc;
    cout<<"Enter Number of Testcases:   ";
    cin >>tc;

    for (int i=0; i<tc ; i++)
    {
        cout<<"******* Test Case " << i+1 << " *******"<<endl<<endl ;
        solve();
    }

}