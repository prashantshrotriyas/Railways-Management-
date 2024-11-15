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

// station class

// Applying template for station class functions

template <class T>
T station<T>::get_st_id()
{
    return st_id;
}

template <class T>
void station<T>::set_st_id(T id)
{
    st_id = id;
}

template <class T>
string station<T>::get_st_name()
{
    return st_name;
}

template <class T>
void station<T>::set_st_name(string name)
{
    st_name = name;
}

template <class T>
void station<T>::printpltfrm()
{
    for (auto pt : pltfrm)
        cout << pt.get_pt_id() << endl;
}


template <class T>
void station<T>::setpltfrm(string id)
{
    platform temp;
    temp.set_pt_id(id);
    pltfrm.push_back(temp);
}

template <class T>
void station<T>::printlines()
{
    for (auto ln : st_lines)
        cout << ln.get_line_id() << endl;
}

template <class T>
void station<T>::setlines(string id)
{
    line temp;
    temp.set_line_id(id);
    st_lines.push_back(temp);
}


template <class T>
void station<T>::alloc_ln_Plt(string ln_id, string pt_id)
{
    // Check if this line and platform exist in this station

    int plt_flag = 0;
    int ln_flag = 0;

    for (auto pt : pltfrm)
        if (pt.get_pt_id() == pt_id)
        {
            plt_flag = 1;
            break;
        }

    for (auto ln : st_lines)
        if (ln.get_line_id() == ln_id)
        {
            ln_flag = 1;
            break;
        }

    if (plt_flag == 0)
    {
        cout << "This platform does not exist in this station" << endl;
        return;
    }

    if (ln_flag == 0)
    {
        cout << "This line does not exist in this station" << endl;
        return;
    }

    for (auto pt : pltfrm)
    {
       
            if (pt.get_pt_lines().get_line_id() == ln_id)
            {
                cout << "Single line can not belong to multiple platforms " << endl;
                cout << "line " << ln_id << " belongs to platform " << pt.get_pt_id() << endl;
                return;
            }
    }

    for (auto &pt : pltfrm)
        if (pt.get_pt_id() == pt_id)
        {   
            if(pt.get_pt_lines().get_line_id()=="")
            pt.set_pt_lines(ln_id);
            else
            cout<<"A platform has only single line !!";

        }
}

template <class T>
void station<T>::print_line_plt()
{
    for (auto pt : pltfrm)
    {
        cout << "Platform is: " << pt.get_pt_id();
        cout << " with line -> " << pt.get_pt_lines().get_line_id() <<endl;
       
    }
}

template <class T>
void station<T>::show_station()
{
      cout<<"The details of Station "<<st_name<<" is :"<<endl;
      cout<<"It has following lines :"<<endl;
      printlines();

      cout<<"It has following platforms :"<<endl;
      printpltfrm();

      print_line_plt();

}


template <class T>
void station<T>::schedule_train(string pt_id, string time, string tname, int stoppage)
{

    int i = 0;
    int minutes = 0;
    string hours;
    string minuts;

    while (time[i] != ':')
    {
        i++;
    }

    hours = time.substr(0, i);
    minuts = time.substr(i + 1, -1);
    minutes = stoi(hours) * 60 + stoi(minuts);

    map<int, pair<bool, string>>::iterator it;
    for (auto &pt : pltfrm)
    {

        if (pt.get_pt_id() == pt_id)
        {
            for (it = pt.get_schedule().begin(); it != pt.get_schedule().end(); ++it)
            {
                if (it->first > minutes)
                {
                    break;
                }
            }

            if ((pt.get_schedule().begin() != pt.get_schedule().end())&&(it != pt.get_schedule().begin()))
            {

                auto prev_it = std::prev(it);

                if (prev_it->second.first == 1)
                {
                    try
                    {
                        if ((minutes < prev_it->first + 30) ||
                            ((it != pt.get_schedule().end()) && stoppage && (minutes + 30) > it->first) ||
                            ((it != pt.get_schedule().end()) && !stoppage && (minutes + 10) > it->first))
                        {
                            throw runtime_error("Train cannot be scheduled due to timing conflicts.");
                        }
                    }
                    catch (runtime_error &e)
                    {
                        cout << "Error: " << e.what() << endl;
                        return;
                    }
                }
                else
                {
                    try
                    {
                        if ((minutes < prev_it->first + 10) ||
                            ((it != pt.get_schedule().end()) && stoppage && (minutes + 30) > it->first) ||
                            ((it != pt.get_schedule().end()) && !stoppage && (minutes + 10) > it->first))
                        {
                            throw runtime_error("Train cannot be scheduled due to timing conflicts.");
                        }
                    }
                    catch (const runtime_error &e)
                    {
                        cout << "Error: " << e.what() << endl;
                        return;
                    }
                }
            }

            cout << "Train scheduled successfully!" << endl;
            pt.get_schedule()[minutes] = {stoppage, tname};
            return;
        }
    }
}

template class station<int>;
template class station<string>;