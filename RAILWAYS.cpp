#include <iostream>
#include "RAILWAYS.h"
using namespace std;

// function implementation of classes

// line class
void line::set_line_id(string id)
{   
    line_id = id;

    
}

string line::get_line_id()
{   
    
    return line_id;
}

// platform class

void platform::set_pt_id(string id)
{
    pt_id = id;
}

string platform::get_pt_id()
{
    return pt_id;
}

void platform::print_pt_lines()
{
        cout <<  pt_lines.get_line_id() << endl;
}
line platform::get_pt_lines()
{
    return pt_lines;
}
void platform::set_pt_lines(string id)
{
    
    pt_lines.set_line_id(id);
}

map<int, pair<bool, string>> &platform::get_schedule()
{
    return schedule;
}

