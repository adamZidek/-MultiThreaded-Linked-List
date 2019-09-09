/*
 * Adam Zidek
 * CSCI 385
 * "Multithreaded Linked List"
 * This is the implementation file for the "multithreaded" Linked List
 */
 #include "cityClass.h"
 
 using namespace std;
 
 CityList::CityList()
 {
	 length = 0;
	 nameHeadPtr = NULL;
     popHeadPtr = NULL;
     zipHeadPtr = NULL;
     nameTailPtr = NULL;
     popTailPtr = NULL;
     zipTailPtr = NULL;
 }
 
 CityList::~CityList()
 {
	 HelperDelete();
 }
 
 CityList::CityList(const CityList & other): nameHeadPtr(NULL), zipHeadPtr(NULL), popHeadPtr(NULL),
                                                nameTailPtr(NULL), zipTailPtr(NULL), popTailPtr(NULL)
 {
     HelperCopy(other);
 }
 
 void CityList::HelperDelete()
 {
     //Follow name head pointer and delete all pointers
     NodePtr tempCurrent = NULL;
     NodePtr current = nameHeadPtr;
     
     //Loop through and delete all nodes
     //We only have to do this for one head since nodes are same
     while(current != NULL)
     {
         tempCurrent = current;
         current = current -> nextName;
         delete tempCurrent;
         tempCurrent = NULL;
     }
     popHeadPtr = NULL;
     zipHeadPtr = NULL;
     nameTailPtr = NULL;
     popTailPtr = NULL;
     zipTailPtr = NULL;
     
     return;
 }
 
 void CityList::HelperCopy(const CityList & other)
 {     
    NodePtr newListPtr = other.nameHeadPtr;
    length = other.length;
    
    while(newListPtr != NULL)
    {
        AddCityToList(newListPtr -> cityRecord);
        newListPtr = newListPtr -> nextName;
    }
    return;
 }
 
 CityList & CityList::operator = (const CityList & other)
 {
     if(this != &other)
     {
         HelperDelete();
         HelperCopy(other);
     }
     return *this;
 }
 
 void CityList::NameInsert(NodePtr currentPtr, NodePtr prevPtr, NodePtr newNodePtr, CityData city)
 {
     //If there is already a node in the list, we need to sort and properly place it.
     //This will be done for each data field for a city
     currentPtr = nameHeadPtr;
     prevPtr = NULL;
         
     while(currentPtr != NULL && currentPtr -> cityRecord.name < city.name)
     {
         prevPtr = currentPtr;
         currentPtr = currentPtr -> nextName;
     }
     
     //Inserting node and connecting name pointers
     newNodePtr -> nextName = currentPtr;
         
     if(prevPtr == NULL)
     {
        //Insert to front of list
        nameHeadPtr -> reverseName = newNodePtr;
        nameHeadPtr = newNodePtr;
        newNodePtr -> reverseName = NULL;
     }
     else
     {
        prevPtr -> nextName = newNodePtr;
        
        if(currentPtr != NULL)
            currentPtr -> reverseName = newNodePtr;
        
        newNodePtr -> reverseName = prevPtr;
     }
        
     if(currentPtr == NULL)
     {
         //If we reached end of list, put it on the end
        newNodePtr -> reverseName = nameTailPtr;
        nameTailPtr = newNodePtr;
     }
     return;
 }
 
 void CityList::PopInsert(NodePtr currentPtr, NodePtr prevPtr, NodePtr newNodePtr, CityData city)
 {
     //If there is already a node in the list, we need to sort and properly place it.
     //This will be done for each data field for a city
     currentPtr = popHeadPtr;
     prevPtr = NULL;
     
     while(currentPtr != NULL && currentPtr -> cityRecord.population <= city.population)
     {
         prevPtr = currentPtr;
         currentPtr = currentPtr -> nextPop;
     }
    
     //Inserting node and connecting population pointers
     newNodePtr -> nextPop = currentPtr;
     
     if(prevPtr == NULL)
     {
         //Insert to the front of the list
         popHeadPtr = newNodePtr;
     }
         
     else
         prevPtr -> nextPop = newNodePtr;
     
     if(currentPtr == NULL)
         popTailPtr = newNodePtr;
     
     return;
 }
 
 void CityList::ZipInsert(NodePtr currentPtr, NodePtr prevPtr, NodePtr newNodePtr, CityData city)
 {
     //If there is already a node in the list, we need to sort and properly place it.
     //This will be done for each data field for a city
     currentPtr = zipHeadPtr;
     prevPtr = NULL;
     
     while(currentPtr != NULL && currentPtr -> cityRecord.zipCode <= city.zipCode)
     {
         prevPtr = currentPtr;
         currentPtr = currentPtr -> nextZip;
     }
         
     //Inserting node and connecting population pointers
     newNodePtr -> nextZip = currentPtr;
     
     if(prevPtr == NULL)
         //Insert to the front of the list
         zipHeadPtr = newNodePtr;
     else
         prevPtr -> nextZip = newNodePtr;
     
     if(currentPtr == NULL)
         zipTailPtr = newNodePtr;
     
     return;
 }
 
 bool CityList::AddCityToList(CityData city)
 {
	 //Variable Declaration
	 NodePtr newNodePtr;		//Points to the new Node
	 NodePtr currentPtr;		//Keeps track of where we are in list
	 NodePtr prevPtr;			//Keeps track of where we were in list
	 bool inserted = false;     //Set to True if item was added(Not Duplicate)
	 int found = false;         //If item is in list, dont add it or Allocate memory
	 
     if(!IsPresent(city))
     {
         //Allocate memory for new item
         newNodePtr = new NodeType;
	 
        //Point our new pointer at new item and set pointer fields to null
        newNodePtr -> cityRecord = city;
        newNodePtr -> nextName = NULL;
        newNodePtr -> nextPop = NULL;
        newNodePtr -> nextZip = NULL;
        newNodePtr -> reverseName = NULL;
        
        //If the list is empty, add it to the front
        if(nameHeadPtr == NULL || popHeadPtr == NULL || zipHeadPtr == NULL)
        {
            //Since its the first item, all head/tail pointers will point to first node(No order yet)
            nameHeadPtr = newNodePtr;
            popHeadPtr = newNodePtr;
            zipHeadPtr = newNodePtr;
            nameTailPtr = newNodePtr;
            popTailPtr = newNodePtr;
            zipTailPtr = newNodePtr;
        }
        else
        {
            //Calling each function to 
            NameInsert(currentPtr, prevPtr, newNodePtr, city);
            PopInsert(currentPtr, prevPtr, newNodePtr, city);
            ZipInsert(currentPtr, prevPtr, newNodePtr, city);
        }
        inserted = true;
        length++;
     }
     return inserted;
 }
 
 
 void CityList::NameDelete(CityData city, NodePtr prevPtr, NodePtr currPtr)
 {
     if(length == 1)
     {
         currPtr = nameHeadPtr;
         nameHeadPtr = NULL;
         nameTailPtr = NULL;
     }
     else
     {
         //We have found the item
        if(currPtr == nameHeadPtr)
        {
            nameHeadPtr = currPtr -> nextName;      //Goes to front of list
            nameHeadPtr -> reverseName = NULL;
        }
        else
        {
            //Middle of List
            NodePtr afterCurrent = currPtr -> nextName;
            prevPtr -> nextName = currPtr -> nextName;
         
            if(afterCurrent != NULL)
                afterCurrent -> reverseName = prevPtr;
        }
        if(currPtr == nameTailPtr)
        {
            //Goes to end of list
            nameTailPtr = prevPtr;
        }
     }
     return;
 }
 
 void CityList::ZipDelete(CityData city, NodePtr prevPtr, NodePtr currPtr)
 {
     prevPtr = NULL;
     currPtr = zipHeadPtr;
     
     if(length == 1)
     {
         currPtr = zipHeadPtr;
         zipHeadPtr = NULL;
         zipTailPtr = NULL;
     }
     else
     {
         while(currPtr != NULL && currPtr -> cityRecord.name != city.name)
        {
            //Iterate through name list
            prevPtr = currPtr;
            currPtr = currPtr -> nextZip;
        }
        if(currPtr == zipHeadPtr)
        {
            zipHeadPtr = currPtr -> nextZip;
        }
        else
        {
            prevPtr -> nextZip = currPtr -> nextZip;
        }
        if(currPtr == zipTailPtr)
        {
            //Goes to end of the list
            zipTailPtr = prevPtr;
        }
     }
     return;
 }
 
 void CityList::PopDelete(CityData city, NodePtr prevPtr, NodePtr currPtr)
 {
     prevPtr = NULL;
     currPtr = popHeadPtr;
     
     if(length == 1)
     {
         currPtr = popHeadPtr;
         popHeadPtr = NULL;
         popTailPtr = NULL;
     }
     else
     {
         while(currPtr != NULL && currPtr -> cityRecord.name != city.name)
        {
            //Iterate through name list
            prevPtr = currPtr;
            currPtr = currPtr -> nextPop;
        }
        if(currPtr == popHeadPtr)
        {
            popHeadPtr = currPtr -> nextPop;
        }
        else
        {
            prevPtr -> nextPop = currPtr -> nextPop;
        }
        if(currPtr == popTailPtr)
        {
            //Goes to end of the list
            popTailPtr = prevPtr;
        }
     }
     return;
 }
 
 bool CityList::DeleteCityFromList(CityData city)
 {
     bool wasDeleted = false;
     NodePtr prevPtr = NULL;
     NodePtr currPtr = nameHeadPtr;
     
     while(currPtr != NULL && currPtr -> cityRecord.name != city.name)
     {
         //Iterate through name list
         prevPtr = currPtr;
         currPtr = currPtr -> nextName;
     }
     
     if(currPtr != NULL)
     {
         NameDelete(city, prevPtr, currPtr);
         ZipDelete(city, prevPtr, currPtr);
         PopDelete(city, prevPtr, currPtr);
         
         //Delete Node and subtract from length
         wasDeleted = true;
         delete currPtr;
         length--;
     }
     return wasDeleted;
 }
 
 bool CityList::IsPresent(CityData city) const
 {
     bool found = false;
     NodePtr iterator = nameHeadPtr;
     
     //Using name head to iterate through
     while(iterator != NULL && found == false)
     {
         if(iterator -> cityRecord.name == city.name)
             found = true;
         
         else
             iterator = iterator -> nextName;
     }
     return found;
 }
 
 int CityList::GetLength() const
 {
	 return length;
 }
 
 bool CityList::IsEmpty() const
 {
	 return(length == 0);
 }
 
 bool CityList::IsFull() const
 {
	 //No restriction on size besides memory filling up
	 return false;
 }
 
 bool CityList::HasNext(int listType) const
 {
     NodePtr iterator = NULL;
     
     bool hasNext = false;
     
     switch(listType)
     {
         case NAMES:
             iterator = nameHeadPtr;
             break;
         
         case POPULATIONS:
             iterator = popHeadPtr;
             break;
             
         case ZIP_CODES:
             iterator = zipHeadPtr;
             break;
     }
     
     if(iterator -> nextName != NULL)
     {
         hasNext = true;
         iterator = iterator -> nextName;
     }
     
     return hasNext;
 }
 
 void CityList::PrintListBy(int sortBy) const
 {
     NodePtr iterator = NULL;
     
     switch(sortBy)
     {
         case NAMES:
             iterator = nameHeadPtr;
             break;
            
         case POPULATIONS:
             iterator = popHeadPtr;
             break;
             
         case ZIP_CODES:
             iterator = zipHeadPtr;
             break;
             
         default:
             cout<<"UNKOWN COMMAND"<<endl;
             break;
     }
     
     //iterate through and print
      while(iterator != NULL)
      {
         cout<<"Name is "<<iterator -> cityRecord.name<<endl;
         cout<<"Population is "<<iterator -> cityRecord.population<<endl;
         cout<<"Zip Code is "<<iterator -> cityRecord.zipCode<<endl;
         cout<<endl<<endl;
         
         //Set to next node depending on sort type
         if(sortBy == NAMES)
             iterator = iterator -> nextName;
         
         else if(sortBy == POPULATIONS)
             iterator = iterator -> nextPop;
         
         else if(sortBy == ZIP_CODES)
             iterator = iterator -> nextZip;
      }
      return;
 }
 
 void CityList::PrintReverseNames() const
 {
     NodePtr curr = nameTailPtr;
     
     while(curr != NULL)
     {
         cout<<"Name is "<<curr -> cityRecord.name<<endl;
         cout<<"Population is "<<curr -> cityRecord.population<<endl;
         cout<<"Zip Code is "<<curr -> cityRecord.zipCode<<endl;
         cout<<endl<<endl;
         
         //Iterate
         curr = curr -> reverseName;
     }
     return;
 }
