#include <iostream>
#include <cstdlib>

using namespace std;


int n = 6; //PLEASE KEEP BELOW 10
int solutions = 0;

int move(int a[], int current);
bool valid(int a[], int current, int n);
void print(int a[], int n);
void printboard(int a[], int n);

int main()
{

    char ans;
    do {
    solutions=0;
    system("CLS");
    cout << "Please choose a number of queens for the N Queens problem: ";
    cin >> n;
    cout << "You have chosen " << n << " Queens." << endl << endl;
    system("PAUSE");
    system("CLS");
    int current=0;
    int a[n];
    for(int i=0; i<n; i++)//set all elements to -1 (off board)
    {
        a[i]=(-1);
    }


    int i=1;

    while (a[0]<n) //while queen 0 is on the board
    {

        //cout << "Current = " << current << "     ";
        current=move(a,current);
        //cout << "while loop has run " << i << " times." << endl;
        i++;

        //print(a,n); cout << "valid test = ";
        //cout << valid(a, current, n);
        //cout << endl;


    }

    /*cout << "Program terminated while array = ";
    print(a,n);*/

    cout << endl << "There are " << solutions << " solutions to the " << n << " Queens problem." << endl;
    cout << endl << "Would you like to repeat this program? y/n: ";
    cin >> ans;
    } while (ans=='y');
    return 0;
}

int move(int a[], int current)
{
   a[current]++; //begin by incrementing current queen

   if (current==0)//if current queen is on first column
   {
        current++;//don't bother checking with previous queens
        //shift focus to next queen and exit back to main()
   }
   else
   {
       /*keep incrementing current queen until valid test passes
       and square is safe, OR current queen is no longer on the board*/
       while ((!(valid(a, current, n)))&&(a[current]<n))
       {
          a[current]++;
       }

       if ((a[current]<n)&&(current<(n-1)))//if current queen is on board and not the last queen
       {
           current++;//shift focus to the next queen
           return (current);//exit function and return to main()
       }
       else if (!(a[current]<n))//if current queen is NOT on the board
       {
           a[current]=(-1);//take current queen OFF the board and put it at -1 (one increment away from 0)
           current--;//backtrack to previous queen
           return(current);//exit function and return to main()
       }
       else if ((a[current]<n)&&(current==(n-1)))//if current queen is on board but in the last column
       {
           //print(a, n);

           cout << endl;
           solutions++;
           cout << "Solution " << solutions << ":" << endl;
           printboard(a, n);
           cout << endl << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;


           return(current); //keep current queen as it is and just continue trying new solutions
       }



   }
   return (current);

}

void print(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    return;
}

bool valid(int a[], int current, int n)
{
    for (int i=0; i<n; i++)
    {

        if (i==current)
            continue;
        if (current==0)
            return 1;
        /*if distance between columns of current queen and queen i is the same
        as the distance between the rows of current queen and queen i, then the
        diagonal from current queen to queen i makes a 45 degree angle, thus the
        queens share a diagonal. remember that the row of a queen i is the element
        stored in a[i] and the row of the current queen is the elemnt stored in
        a[current]. for example, if a[3] = 4, then queen 3 (which is in column 3)
        is in row 4.*/
        if(( abs(a[current]-a[i]) == abs(current-i) )&&(a[i]>(-1)))//if current qeen and queen i share diagonal
            return 0; //valid test returns false
        else if(( a[current] == a[i] ) && (a[i]>(-1))) //if current queen and queen i are in the same row
            return 0; //valid test returns false
        else
            continue; //valid test passes, current queen is in a safe square, return true

    }
    return 1;
}

void printboard(int a[], int n)
{
    for(int row=(n-1); row>(-1); row--) {
        for(int col=0; col<n; col++)
        {
            if(a[col]==row)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}




