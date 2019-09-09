/*
 * Adam Zidek
 * CSCI385
 * Homework #1
 * "Multithreaded Linked List"
 * This is the header file for the "multithreaded" Linked List
 */

 #include <string>
 #include <iostream>
 
 #ifndef CITY_CLASS_
 #define CITY_CLASS_

 //Struct to store city data
 struct CityData
 {
	 int zipCode;
	 long population;
	 std::string name;
 };
 
 //Structure that will hold the city data and pointers to nodes
 struct NodeType
 {
	 CityData cityRecord;
	 NodeType * nextName;
	 NodeType * nextPop;
	 NodeType * nextZip;
	 NodeType * reverseName;
 };
 
 typedef NodeType * NodePtr;        //Typedef for NodeType Pointer
 
 class CityList
 {
	 public:
	 
		enum ListType {POPULATIONS, ZIP_CODES, NAMES};
         
        //Constructors
        
		CityList();
        //Creates in instance of CityList
        //Pre: None
        //Post: Intsance of CityList has been created and values have been initalized
        
		~CityList();
        //Destroyes and instance of CityList
        //Pre: Instance of CityList has been declared
        //Post: Instance of CityList has been destroyed, dynamic memory has been de-allocated
        
		CityList(const CityList & other);
        //Copies all members of CityClass responsibily, no mem leaks
        //Pre: None
        //Post: Instance of CityClass has been deep copied to another newly created CityClass
        
		CityList & operator = (const CityList & other);
        //Overloaded assignment operator for assigning one instance to another
        //Pre: Instance of CityClass has been created
        //Post: This instances values have been assigned to another through deep copy
        
		
		//Action Responsibilities
		
		bool AddCityToList(CityData city);
        //Takes a CityData struct and inserts it to the list
        //Pre: CityData has valid data
        //Post: City has been inserted to list, links and order have been maintained
		
		bool DeleteCityFromList(CityData city);
        //Deletes a CityData struct from the list
        //Pre: None
        //Post: City has been deleted from the list, links and order have been maintained
        
        void PrintListBy(int sortBy) const;
        //Takes an int and prints the list sorted by the parameter passed in
        //Pre: None
        //Post: List has been traversed and printed by specified order
        
        void PrintReverseNames() const;
        //Traverses the list by reverse name links and prints list
        //Pre: None
        //Post: List has been printed out in reverse order
        
		
		//Knowledge responsibilities
        
		int GetLength() const;
        //Returns the length of list
        //Pre: None
        //Post: Length of list has been returned
		
		bool IsEmpty() const;
        //Returns true if list is empty, false otherwise
        //Pre: None
        //Post: True returned if list is empty, false otherwise
		
		bool IsFull() const;
        //Returns true if list is full, false otherwise
        //Pre: None
        //Post: True returned if list is full, false otherwise
		
		bool IsPresent(CityData city) const;
		//Returns true if item is in the list, false otherwise
        //Pre: None
        //Post: True returned if item was in the list, false otherwise
		
		bool HasNext(int listType) const;
		//Takes an int(enum) to check if there is another node in the list
        //Pre: None
        //Post: True returned if list has next element specifed by parameter
       
	private:
		
		int length;		         //Maintains the number of elements in the list
		NodePtr nameHeadPtr;	 //Pointer to first node in list sorted by name
        NodePtr popHeadPtr;		 //Pointer to first node in list sorted by population
        NodePtr zipHeadPtr;		 //Pointer to first node in list sorted by zip code
		NodePtr nameTailPtr;	 //Pointer to last node in list sorted by name
        NodePtr popTailPtr;		 //Pointer to the last node in list sorted by population
        NodePtr zipTailPtr;		//Pointer to the last node in list sorted by zip code
        
        void NameDelete(CityData city, NodePtr prevPtr, NodePtr currPtr);
        //Handles the re connection of name links after a delete
        //Pre: Item to be deleted has been found
        //Post: Name links have been reconnected, currPtr still points at node to delete
        
        void ZipDelete(CityData city, NodePtr prevPtr, NodePtr currPtr);
        //Handles the re connecton of zip links after a delete
        //Pre: Item to be deleted has been found
        //Post: Zip links have been reconnected, currPtr still points at node to delete
        
        void PopDelete(CityData city, NodePtr prevPtr, NodePtr currPtr);
        //Handles the re connection of pop links after a delete
        //Pre: Item to be deleted has been found
        //Post: Pop links have been reconnected, currPtr still points at node to delete 
        
         void NameInsert(NodePtr currentPtr, NodePtr prevPtr, NodePtr newNodePtr, CityData city);
        //Handles the re connection of name links after a insert
        //Pre: Item to be inserted is valid data
        //Post: Name links have been connected after insert
        
        void PopInsert(NodePtr currentPtr, NodePtr prevPtr, NodePtr newNodePtr, CityData city);
        //Handles the re connection of pop links after a insert
        //Pre: Item to be inserted is valid data
        //Post: Pop links have been connected after insert
        
        void ZipInsert(NodePtr currentPtr, NodePtr prevPtr, NodePtr newNodePtr, CityData city);
        //Handles the re connection of zip links after a insert
        //Pre: Item to be inserted is valid data
        //Post: Zip links have been connected after insert
        
         void HelperCopy(const CityList & other);
         //Copies all members of CityClass responsibily, no mem leaks
         //Pre: None
         //Post: Instance of CityClass has been deep copied to another newly created CityClass
        
         void HelperDelete();
         //Destroyes and instance of CityList
         //Pre: Instance of CityList has been declared
         //Post: Instance of CityList has been destroyed, dynamic memory has been de-allocated
 };
 
 #endif
