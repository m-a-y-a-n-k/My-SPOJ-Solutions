#include <bits/stdc++.h>

using namespace std;

struct Points{
    int x,y;
};

Points *p0;

void swap(Points *P, int a, int b) {
    Points temp = P[a];
    P[a] = P[b];
    P[b] = temp;
}

Points nextToTop(stack<Points> s) {
    Points p = s.top();
    s.pop();
    Points n = s.top();
    s.push(p);
    return n;
}

int orientation(Points p, Points q, Points r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

int DistSq( Points *a, Points* b) {
        return ( a -> x - b -> x) * ( a -> x - b -> x ) + ( a -> y - b -> y ) * (a -> y - b -> y );
}

bool compare(Points *a,Points *b){

    if( (a->y - p0->y)/(a->x - p0->x) == (b->y - p0->y)/(b->x - p0->x) ) {

        return ( DistSq(a,p0) > DistSq(b,p0) );
    }
    return ( (a->y - p0->y)/(a->x - p0->x) < (b->y - p0->y)/(b->x - p0->x) );
}

void convexHull(Points *P,int n) {

    int m = 1;              // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(P[0], P[i],P[i+1]) == 0)
          i++;

       P[m] = P[i];
       m++;  // Update size of modified array
   }

   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;

   // Create an empty stack and push first three points
   // to it.
   stack<Points> S;
   S.push(P[0]);
   S.push(P[1]);
   S.push(P[2]);

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), P[i]) != 2)
         S.pop();
      S.push(P[i]);
   }

   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Points p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }

}

int main() {

    int n,i,minid=0,miny=999999999;
    cout << "Enter number of points" << endl;
    cin >> n;
    Points P[n+1];
    cout << "Enter points " << endl;
    for( i = 0; i < n; i++) {

        cin >> P[i].x >> P[i].y;
        if( ( P[i].y < miny ) || (P[i].y == miny && P[i].x < P[minid].x) ) {
            miny = P[i].y;
            minid = i;
        }
    }

    swap(P,0,minid);
    p0 = &P[0];
    sort(P+1,P+n,compare);

    convexHull(P,n);
    return 0;
}
