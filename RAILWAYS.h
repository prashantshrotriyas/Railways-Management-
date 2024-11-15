#ifndef RAILWAYS_H
#define RAILWAYS_H
#include <string>
#include <vector>
#include <map>
using namespace std;

class line
{  
    private:
    string line_id;
    public:
    string get_line_id();
    void set_line_id(string id);
};

class platform
{
    private:
    string pt_id;
    line pt_lines;
    map<int ,pair<bool,string>> schedule;
    public:

    string get_pt_id();
    void set_pt_id(string id);
    void print_pt_lines();
    line get_pt_lines();
    void set_pt_lines(string id);
    map<int ,pair<bool,string>>& get_schedule();
   
};

template <class T>
class station
{
  private:
  T st_id;
  string st_name;
  vector<platform> pltfrm;
  vector<line> st_lines;
  public:

  T get_st_id();
  void set_st_id(T id);
  string get_st_name();
  void set_st_name(string name);
  
  void setpltfrm(string id);
  void printpltfrm();
  

  void setlines(string id);
  void printlines();
  

  void alloc_ln_Plt(string ln_id,string pt_id);
  void print_line_plt();

  void  schedule_train(string pt_id,string time,string tname,int stoppage);
   
  void show_station();

};

#endif
