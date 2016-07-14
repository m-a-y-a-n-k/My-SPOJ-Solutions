#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++)
	 cin>>list[i];
    int num;
    int min = 1;
    int max = n;
    int middle1 = (2*min+max)/3; 
    int middle2 = (min+2*max)/3;

    cin >> num;    //num is the number that is wanted to be found

    while (middle1 != middle2)
    {
        middle1 = (2*min+max)/3;
        middle2 = (min+2*max)/3;

        if(num <= list[middle1])
            max = middle1;
        else if(num >list[middle1] && num <= list[middle2])
            {
                    min= middle1; 
                    max = middle2;
            }
        else
            min = middle2;
    }
    if(num == list[max])
        cout << "your number is found in the "<< max <<"th location\n";
    else
        cout << "number cannot be found";
    
	return 0;
}
