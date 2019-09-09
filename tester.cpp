#include <iostream>
#include <string>
#include "cityClass.h"

using namespace std;

int main()
{
    //NOTE THIS IS THE TEST DRIVER FOR "Multithreaded" Linked List
    
	CityList list1;            //Declare the list object
    
    
    /*************CITY ONE**********************/
	CityData city1;        
	
	city1.name = "Erie";
	city1.population = 101786;
	city1.zipCode = 16512;
    
    
    /*************CITY TWO**********************/
    CityData city2;
    
    city2.name = "Altoona";
    city2.population = 46320;
    city2.zipCode = 16602;
    
    
    /*************CITY THREE**********************/
    CityData city3;
    
    city3.name = "Philadelphia";
    city3.population = 156006;
    city3.zipCode = 19106;
    
    
    /*************CITY FOUR**********************/
    CityData city4;
    
    city4.name = "Wilkes-Barre";
    city4.population = 41498;
    city4.zipCode = 18702;
    
    
    /*************CITY FIVE**********************/
    CityData city5;
    
    city5.name = "Harrisburgh";
    city5.population = 49528;
    city5.zipCode = 17120;
    
    
    /*************CITY SIX**********************/
    CityData city6;
    
    city6.name = "Aliquippa";
    city6.population = 9436;
    city6.zipCode = 15001;
    
    
    /*************CITY SEVEN**********************/
    CityData city7;
    
    city7.name = "Latrobe";
    city7.population = 8944;
    city7.zipCode = 15650;
    
    
    /*************CITY EIGHT**********************/
    CityData city8;
    
    city8.name = "Pittsburgh";
    city8.population = 305704;
    city8.zipCode = 15212;
    
    
    /*************CITY NINE**********************/
    CityData city9;
    
    city9.name = "Meadville";
    city9.population = 13388;
    city9.zipCode = 16335;
    
    
    /*************CITY TEN(NOT INSERTING)**********/
    CityData city10;
    
    city10.name = "Fake";
    city10.population = 14567;
    city10.zipCode = 12;
    
    
    /****************INSERTING CITIES TO LIST**********/
    cout<<"INSERTING 9 CITIES TO LIST"<<endl;
    
    list1.AddCityToList(city1);
    list1.AddCityToList(city2);
    
    list1.AddCityToList(city3);
    list1.AddCityToList(city4);
    
    list1.AddCityToList(city5);
    list1.AddCityToList(city6);
    list1.AddCityToList(city7);
    list1.AddCityToList(city8);
    list1.AddCityToList(city9);
    
    
    /**************TEST CONTRUCTOR***********/
    cout<<"****TESTING CONTRUCTOR****"<<endl;
    
    CityList list2;
    
    //LIST SHOULD BE EMPTY, length should be zero
    
    cout<<"LENGTH OF NEW LIST IS "<<list2.GetLength()<<endl<<endl;
    
    bool emptE = list2.IsEmpty();
    
    if(emptE)
        cout<<"NEW LIST IS EMPTY!"<<endl;
    else if(!emptE)
        cout<<"NEW LIST IS NOT EMPTY!"<<endl;
    cout<<endl;
    
    
    /*************TEST COPY CONTRUCTOR***********/
    cout<<"****TESTING COPY CONSTRUCTOR****"<<endl;
    
    CityList list3 = list1;
    
    cout<<"****CityList list3 = list1****"<<endl<<endl;
    
    cout<<"****PRINTING LIST 1 BY NAME****"<<endl;
    list1.PrintListBy(CityList::NAMES);
    
    cout<<endl<<endl;
    
    cout<<"PRINTING LIST 3 BY NAME****"<<endl;  //(ACTUALLY LIST 3)
    list3.PrintListBy(CityList::NAMES);
    
    cout<<endl<<endl;
    
    
    /**************TEST ASSIGNMENT OPERATOR********/
    cout<<"****TESING ASSIGNMENT OPERATOR****"<<endl<<endl;
    
    cout<<"****PRINTING LIST 1 BY NAME****"<<endl;
    list1.PrintListBy(CityList::NAMES);
    
    cout<<endl<<endl;
    
    cout<<"****Assigned list 2 = list 1****"<<endl;
    list2 = list1;
    
    cout<<"***PRINTING LIST 2 BY NAME****"<<endl;
    list2.PrintListBy(CityList::NAMES);
    
    
    //*************TEST PRINT**********************/
    cout<<"****TESTING PRINT****"<<endl;
    
    cout<<"****PRINTING BY NAME****"<<endl;
    list1.PrintListBy(CityList::NAMES);
    
    cout<<endl<<endl;
    
    cout<<"****PRINTING BY POP****"<<endl;
    list1.PrintListBy(CityList::POPULATIONS);
    
    cout<<endl<<endl;
    
    cout<<"****PRINTING BY ZIP****"<<endl;
    list1.PrintListBy(CityList::ZIP_CODES);
    
    cout<<endl<<endl;
    
    //**************TEST ISPRESENT**************//
    cout<<"****TESTING ISPRESENT****"<<endl<<endl;
    bool isPresent = false;
    isPresent = list1.IsPresent(city1);
    
    if(isPresent)
        cout<<city1.name<<" was found in the list "<<endl;
    else if(!isPresent)
        cout<<city1.name<<" was not found in the list"<<endl;
    
    cout<<endl;
    
    isPresent = list1.IsPresent(city10);
    
    if(isPresent)
        cout<<city10.name<<" was found in the list "<<endl;
    else if(!isPresent)
        cout<<city10.name<<" was not found in the list "<<endl;
    
    cout<<endl;
    
    //**************TEST LENGTH***********************/
    cout<<"****TESTING LENGTH****"<<endl;
    cout<<endl<<"List Length = "<<list1.GetLength()<<endl<<endl;
    
    
    //*************TEST ISEMPTY*********************/
    cout<<"****TESTING EMPTY****"<<endl<<endl;
    
    bool empty = false;

    empty = list1.IsEmpty();
    
    if(empty)
        cout<<"List is empty!"<<endl;
    
    else if(!empty)
        cout<<"List is not empty!"<<endl;
    
    cout<<endl;
    
    
    
    //*************TEST DELETE******************/
    cout<<"****TESTING DELETE****"<<endl<<endl;
    bool wasDeleted = false;
    
    //Delete from Middle
    wasDeleted = list1.DeleteCityFromList(city1);
    
    if(wasDeleted)
        cout<<city1.name<<" was deleted from the list"<<endl;
    else
        cout<<city1.name<<" was not deleted from the list"<<endl<<endl;
    
    //Delete from Front
    wasDeleted = list1.DeleteCityFromList(city6);
    
    if(wasDeleted)
        cout<<city6.name<<" was deleted from the list"<<endl;
    else
        cout<<city6.name<<" was not deleted from the list"<<endl<<endl;
    
    
    //Delete from back
    wasDeleted = list1.DeleteCityFromList(city4);
    
    if(wasDeleted)
        cout<<city4.name<<" was deleted from the list"<<endl;
    else
        cout<<city4.name<<" was not deleted from the list"<<endl<<endl;
    
    
    cout<<endl<<"List Length = "<<list1.GetLength()<<endl<<endl;
    
    
    //RE PRINTING AFTER DELETE
    
    cout<<"****PRINTING BY NAME****"<<endl;
    list1.PrintListBy(CityList::NAMES);
    
    cout<<endl<<endl;
    
    cout<<"****PRINTING BY POP****"<<endl;
    list1.PrintListBy(CityList::POPULATIONS);
    
    cout<<endl<<endl;
    
    cout<<"****PRINTING BY ZIP****"<<endl;
    list1.PrintListBy(CityList::ZIP_CODES);
    
    
    //***********TEST ADDING DUPLICATE***********/
    cout<<"****TESTING FOR ADDITION OF DUPLICATE CITY****"<<endl;
    
    bool putIn = list1.AddCityToList(city2);
    
    if(!putIn)
        cout<<city2.name<<" was not added to list(already exists)"<<endl;
    else if(putIn)
        cout<<city2.name<<" was not added to the list!"<<endl<<endl;
    
    CityData city11;
    
    city11.name = "DuBois";
    city11.population = 2345;
    city11.zipCode = 16555;
    
    putIn = list1.AddCityToList(city11);
    
    if(!putIn)
        cout<<city11.name<<" was not added to list(already exists)"<<endl;
    else if(putIn)
        cout<<city11.name<<" was added to the list!"<<endl;
    
    cout<<endl;
    
    
    //*************TEST REVERSE NAME LINK***********/
    cout<<"****TESING REVERSE NAME LINK****"<<endl;
    
    list1.PrintReverseNames();
    
    cout<<endl<<endl;
    
    //************TEST HAS NEXT************//
    cout<<"****TESTING HAS NEXT****"<<endl;
    
    bool hasNext = list1.HasNext(CityList::NAMES);
    
    if(hasNext)
        cout<<"List 1 has next!"<<endl<<endl;
    
    else if(!hasNext)
        cout<<"List 1 does not have next!"<<endl<<endl;
    
    
    //*********TEST DELETE ALL NODES********//
    cout<<"****TESTING DELETING ALL NODES FROM LIST4****"<<endl;
    
    CityList list4;
    
    list4.AddCityToList(city1);
    list4.AddCityToList(city2);
    list4.AddCityToList(city3);
    
    cout<<endl<<"****PRINTING LIST 4****"<<endl;
    cout<<"List 4 has length of "<<list4.GetLength()<<endl<<endl;
    
    list4.PrintListBy(CityList::NAMES);
    
    cout<<"REMOVING ALL 3 CITIES FROM LIST 4"<<endl;
    list4.DeleteCityFromList(city1);
    list4.DeleteCityFromList(city2);
    list4.DeleteCityFromList(city3);
    
    cout<<endl<<"List 4 has length of "<<list4.GetLength()<<endl<<endl;
}
