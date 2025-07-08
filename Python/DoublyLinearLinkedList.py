########################################################################
#
# File Name   : DoublyLinearLinkedList.py
# Description : Doubly Linear Linked List Implementation
# Author      : Pradhumnya Changdev Kalsait
# Date        : 08/07/25
#
########################################################################

class node :
    ####################################################################
    #
    # Function Name : __init__
    # Description   : Constructor to initialize node
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def __init__(self,no)
    # Input Output  : (1 input, 0 output)
    #
    ####################################################################
    def __init__(self,no):
        self.data = no
        self.next = None
        self.prev = None

class DoublyLLL:
    ####################################################################
    #
    # Function Name : __init__
    # Description   : Initializes empty doubly linear linked list
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def __init__(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def __init__(self):
        self.first = None
        self.iCount = 0

    ####################################################################
    #
    # Function Name : InsertFirst
    # Description   : Inserts node at beginning of DLLL
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def InsertFirst(self,no)
    # Input Output  : (1 input, 0 output)
    #
    ####################################################################
    def InsertFirst(self,no):
        
        newn = node(no)

        if( (self.first == None) ):
            self.first = newn
            
        
        else:
            newn.next = self.first
            self.first = newn

        self.iCount += 1

    ####################################################################
    #
    # Function Name : InsertLast
    # Description   : Inserts node at end of DLLL
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def InsertLast(self,no)
    # Input Output  : (1 input, 0 output)
    #
    ####################################################################
    def InsertLast(self,no):
        newn = node(no)
        temp = None

        if( (self.first == None) ):

            self.first = newn
             
        else:
            temp = self.first
            while(temp.next != None):
                temp = temp.next

            temp.next = newn
            newn.prev = temp

        self.iCount += 1

    ####################################################################
    #
    # Function Name : DeleteFirst
    # Description   : Deletes the first node
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def DeleteFirst(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def DeleteFirst(self):

        if((self.first == None) ):
            return
        
        elif(self.first.next == None):
            self.first = None
            self.iCount -= 1

        else:
            self.first = self.first.next
            self.first.prev = None
            self.iCount -= 1

    ####################################################################
    #
    # Function Name : DeleteLast
    # Description   : Deletes the last node
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def DeleteLast(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def DeleteLast(self):

        temp = None

        if((self.first == None) ):
            return
        
        elif(self.first.next ==None):
            self.first = None
            self.iCount -= 1

        else:
            temp = self.first
            while(temp.next.next != None):
                temp = temp.next

            temp.next = None
            self.iCount -= 1

    ####################################################################
    #
    # Function Name : Display
    # Description   : Displays all elements in the list
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def Display(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def Display(self):
        temp = self.first
        if(temp == None):
            print("Linked List is Empty")

        while(temp != None):
            print(f"|{temp.data}|<=>",end ="" )
            temp = temp.next

        print("None")

    ####################################################################
    #
    # Function Name : Count
    # Description   : Returns the number of elements in DLLL
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def Count(self)
    # Input Output  : (0 input, 1 output)
    #
    ####################################################################
    def Count(self):
        return self.iCount

    ####################################################################
    #
    # Function Name : InsertAtPos
    # Description   : Inserts node at specified position
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def InsertAtPos(self,no,pos)
    # Input Output  : (2 input, 0 output)
    #
    ####################################################################
    def InsertAtPos(self,no,pos):
        temp = None
        newn = None
        iCnt = 0

        if(pos < 1 or pos > self.iCount+1):
            print("invalid Position")
            return
        
        if(pos == 1):
            self.InsertFirst(no)

        elif(pos == self.iCount+1):
            self.InsertLast(no)

        else:
            newn = node(no)

            temp = self.first
            for iCnt in range(1,pos-1):
                temp = temp.next

            newn.next = temp.next
            temp.next.prev = newn

            newn.prev = temp
            temp.next = newn

            self.iCount += 1
 

    ####################################################################
    #
    # Function Name : DeleteAtPos
    # Description   : Deletes node at specified position
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def DeleteAtPos(self,pos)
    # Input Output  : (1 input, 0 output)
    #
    ####################################################################
    def DeleteAtPos(self,pos):
        temp = None
        
        if(pos < 1 or pos > self.iCount):
            print("invalid Position")
            return
        
        if(pos == 1):
            self.DeleteFirst()

        elif(pos == self.iCount):
            self.DeleteLast()

        else:
            temp = self.first
            for iCnt in range(1,pos-1):
                temp = temp.next

            temp.next = temp.next.next
            temp.next.prev = None

            self.iCount -= 1

########################################################################

########################################################################
# Function Name : main
# Description   : Menu-driven main function
# Author        : Pradhumnya Changdev Kalsait
# Date          : 08/07/25
# Prototype     : def main()
# Input Output  : (0 input, 0 output)
########################################################################

def main():
    dobj = DoublyLLL()
    while True:
        print("\n----------------------------")
        print(" Doubly Linear Linked List")
        print("----------------------------")
        print("1. Insert First")
        print("2. Insert Last")
        print("3. Insert at Position")
        print("4. Delete First")
        print("5. Delete Last")
        print("6. Delete at Position")
        print("7. Display")
        print("8. Count")
        print("9. Exit")
        print("----------------------------")

        print("Enter your choice: ")
        choice = int(input())

        match choice:
            case 1:
                print("Enter number to insert at beginning: ")
                no = int(input())
                dobj.InsertFirst(no)
            case 2:
                print("Enter number to insert at end: ")
                no = int(input())
                dobj.InsertLast(no)
            case 3:
                print("Enter number to insert: ")
                no = int(input())
                print("Enter position: ")
                pos = int(input())
                dobj.InsertAtPos(no, pos)
            case 4:
                dobj.DeleteFirst()
            case 5:
                dobj.DeleteLast()
            case 6:
                print("Enter position to delete: ")
                pos = int(input())
                dobj.DeleteAtPos(pos)
            case 7:
                dobj.Display()
            case 8:
                iRet = dobj.Count()
                print("Total number of nodes:", iRet)
            case 9:
                print("Exiting program.")
                break
            case _:
                print("Invalid choice. Try again.")

########################################################################

if __name__ == "__main__":
    main()
