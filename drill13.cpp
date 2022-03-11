#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 

using namespace Graph_lib;

struct occupied
{
    int ex;
    int ey;
};
vector <occupied> Taken;
void fillTaken(int x,int y)
{
    Taken.push_back(occupied());
    int a = Taken.size();
    Taken[a].ex = x;
    Taken[a].ey = y;
}
void foursquare(int x, int y)
{
    Taken.push_back(occupied());
    int a = Taken.size();
    Taken[a].ex = x;
    Taken[a].ey = y;
     Taken.push_back(occupied());
    int a = Taken.size();
    Taken[a].ex = x;
    Taken[a].ey = y+1;
     Taken.push_back(occupied());
    int a = Taken.size();
    Taken[a].ex = x+1;
    Taken[a].ey = y;
     Taken.push_back(occupied());
    int a = Taken.size();
    Taken[a].ex = x+1;
    Taken[a].ey = y+1;
}
vector <occupied> beenThere;
void fillbeenThere(int x, int y)
{
    beenThere.push_back(occupied());
    int b = beenThere.size();
    beenThere[b].ex = x;
    beenThere[b].ey = y;
}

bool check(int x, int y)
{
    bool isfree;
    for (int i = 0; i < Taken.size(), i++)
        if (x != Taken[i].ex || y != Taken[i].ey)
        isfree = true;
        else isfree = false;
    bool isfree2;
    for (int i = 0; i < beenThere.size(), i++)
        if (x != beenThere[i].ex || y != beenThere[i].ey)
        isfree2 = true;
        else isfree2 = false;
    if (isfree = true & isfree2 = true) return true;
        else return false;
}

void pic(int x, int y,string pict)
{
Image im {Point{x*100,y*100},pict};
im.set_mask(Point{x*100,y*100},200,200);
win.attach(im);
}

void moving(int x, int y,string pict)
{
Image moving {Point{x*100,y*100},pict};
moving.set_mask(Point{x*100,y*100},100,100);
win.attach(moving);
}

int main()
{           
    try {
        
        Point t1{300,50};
        Simple_window win (t1,1000,800, "My window");
        win.wait_for_button();

        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for (int i = 100; i <= x_size; i+=100)
            {
                grid.add(Point(i, 0), Point(i, y_size));
                grid.add(Point(0, i), Point(x_size, i));
            }
            win.attach;
            win.wait_for_button();
            
        vector_ref<Rectangle> vr;
        for (int i = 0 ; i < 8; i++)
                {
            vr.push_back(new Rectangle{Point{i*100,j*100},101,101});
                vr[vr.size()-1].set_fill_color(Color{Color::blue});
                win.attach(vr[vr.size()-1]);
                fillTaken(i,j);
                }

pict(3,0,"smile.jpg");
foursquare(3,0);
pict(0,6,"smile.jpg");
foursquare(0,6);
pict(6,0,"smile.jpg");
foursquare(6,0);

int i = 0;
while (i < 30)
    {
        int x = rand() % 8;
        int y = rand() % 8;
        if (check(x,y) = true)
            {
            moving(x,y,"eye.jpg");
            fillbeenThere(x,y);
            win.wait_for_button();
            i += 1;
            }
            else i = i;
    }
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
    }
catch (...) {
	cerr << "exception\n";
	return 2;
    }
}