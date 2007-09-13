/*
  libpuMet - Meteorological algorithms (Weather symbol generator etc.)
  
  $Id$

  Copyright (C) 2006 met.no

  Contact information:
  Norwegian Meteorological Institute
  Box 43 Blindern
  0313 OSLO
  NORWAY
  email: diana@met.no
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef _miSymbol_h
#define _miSymbol_h


#include <puTools/miString.h>
#include <puTools/miTime.h>

#include <vector>
#include <iostream>
#include <algorithm>

#include <stdio.h>
#include <math.h>



using namespace std;

// class to hold a numeric weather identifier, and a string
// with the description of the weather. This part of the symbol
// is customer specific and should be read in  from file
// PU-JS 6/98
// last update 9/98

class code {
  friend class miSymbol;
private:
  int extNum;          // the customers identification Number
  miString name;       // the name 1of the weather situation
  int vision;          // an identidier for the visibillity in km 
  miString pic;        // an identifier for a picture (file Name or something )
public:
  code(){}
  void AddValues(int ex, miString nam, int vis, miString p){
    extNum =ex;
    name = nam;
    vision = vis;     // here is one of these famous vis addings
    pic = p;
  }
  void AddValues(int ex, miString nam, int vis){
    extNum =ex;
    name = nam;
    vision = vis;     // here is one of these famous vis addings
  }




};

// class to hold a symbol
// which uses  a code for normal daytime and one for darktime
// additional an internal index and the wmo number for verification


class miSymbol {
private:
  int intNum;                 // Internal Number
  bool changeSig;             // Significance check by changing from one sit. to another
  code light;                 // code for normal time
  code dark;                  // code for  darkness
  miTime tim;                 // time where the symbol is valid
  bool lightstat;             // switch from light to dark
public:
  miSymbol(){}
  miSymbol(const int i , const bool ch)
    : intNum(i),
      changeSig(ch) {}
  void AddCodes(code l, code d){
    light = l;
    dark = d;
  }
  void AddErr(miString errMessage );
  void setLightStat(miTime,float);
  void setLightStat(bool);
  void setTime(miTime t){tim = t;};
  
  int vis();
  int index(){return intNum;}
  

  int customNumber();
  int customNumber(bool);
  bool change() const {return changeSig;};
  miString customName();
  miTime getTime() const {return tim;};
  miString picture();
  miString picture(bool);
  friend bool operator==( const miSymbol& lhs, const miSymbol& rhs){
    return(lhs.intNum == rhs.intNum);}

  friend bool operator!=( const miSymbol& lhs, const miSymbol& rhs){
    return(lhs.intNum != rhs.intNum);}

};


#endif









