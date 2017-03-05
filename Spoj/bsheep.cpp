#include<bits/stdc++.h>
#define PI 3.141592
const double eps=1e-9;
using namespace std;


struct point{
    int x,y,index;
    point(){
       
     }
    point(int _x, int _y){
        x=_x;
        y=_y;
    }
};

point start;

void set_p0_as_min_point(vector<point> &points){
    point min_point=points[0];
    int min_point_index=0;
    for(int i=1;i<points.size();i++){
        if((points[i].y<min_point.y) || ((points[i].y==min_point.y) && (points[i].x<min_point.x))){
            min_point=points[i];
            min_point_index=i;
        }
    }
    swap(points[0],points[min_point_index]);
    start=points[0];
    //cout<<"start:"<<start.x<<" "<<start.y<<endl;
}


float polar_angle(point p0, point p1){
    int y=p1.y-p0.y;
    int x=p1.x-p0.x;
    float ang=atan2(y,x)*180/PI;
    return ang;
}

int dist(point p1, point p2){
    int distt;
    distt=pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2);
    return distt;
}

bool compare(const point &point1, const point &point2){
    float angle1=polar_angle(start,point1);
    float angle2=polar_angle(start,point2);
    if(angle1<angle2)
       return true;
    else if(angle1==angle2){
        if(dist(start,point1)<dist(start,point2))
            return true;
        else if((dist(start,point1)==dist(start,point2)) && point1.index>point2.index)
            return true;
        else
            return false;
    }
    else
       return false;
}

point next_to_top(stack<point> &mystack){
    point point_top=mystack.top();
    mystack.pop();
    point next_top=mystack.top();
    mystack.push(point_top);
    return next_top;
}


int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2; 
}

void print(vector<point> points){
    for(int i=0;i<points.size();i++){
        cout<<points[i].x<<","<<points[i].y<<" "<<points[i].index<<endl;
    }
}

stack<point> convex_hull(vector<point> &points){
    set_p0_as_min_point(points);
    sort(points.begin()+1,points.end(),compare);
    //print(points);
    stack<point> mystack;
    int m = 1;
    for (int i=1; i<points.size(); i++)
    {
        while (i < points.size()-1 && orientation(start, points[i], points[i+1]) == 0){
            //cout<<"inside for i:"<<i<<" and i+1"<<i+1<<"Are coincident"<<endl;
            i++;
        }
        //cout<<"m:"<<m<<"<----"<<points[i].x<<","<<points[i].y<<" is inserted"<<endl;
        points[m] = points[i];
        m++;
    }   
    points.resize(m);
    if(m<=3){
        for(int i=0;i<m;i++)
            mystack.push(points[i]);
        return mystack;
    }
    mystack.push(points[0]);
    mystack.push(points[1]);
    mystack.push(points[2]);
    for(int i=3;i<points.size();i++){
        while(orientation(next_to_top(mystack), mystack.top(), points[i]) != 2){
            mystack.pop();
        }
        mystack.push(points[i]);
    }
    return mystack;
}

double signed_area(const vector<point> &poly){
    int n=poly.size();
    int S=0;
    
    for(int i=1;i<n;i++) S+=poly[i].x*(poly[i+1<n? i+1:i+1-n].y-poly[i-1].y);
    S+=poly[0].x*(poly[1].y-poly[n-1].y);
    
    return S/2.0;
}

double area_for_three(vector<point> &points){
    int n=points.size();
    if(n==3)
        return signed_area(points);
    else if(n==2)
        return (dist(points[0],points[1]))*2.0;
    else
        return 0.0;
}

double perim(vector<point> &points){
    double area=0.0;
    for(int i=0;i<points.size();i++){
        int j=(i+1)%points.size();
        area+=sqrt(dist(points[i],points[j]));
    }
    return area;
}

int main() {
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        //cout<<"Case #"<<i<<endl;
        double area;
        vector<point> hulls;
        int n;
        cin>>n;
        vector<point> points(n);
        for(int k=0;k<n;k++){
            int x,y;
            cin>>x>>y;
            points[k].x=x;
            points[k].y=y; 
            points[k].index=k+1;
        }
        stack<point> S=convex_hull(points);
        //cout<<"Points in Convex hull:"<<endl;
        while(!S.empty())
        {
            point p=S.top();
            S.pop();
            hulls.push_back(p);
            //cout<<p.x<<" "<<p.y<<endl<<" "<<p.index<<endl;
        }
        area=perim(hulls);  
        cout << fixed;
        cout << setprecision(2);
        cout<<area<<endl;
        for(int k=hulls.size()-1;k>=0;k--){
            printf("%d ",hulls[k].index);
        }
        printf("\n\n");
        
    }   
    return 0;
}
