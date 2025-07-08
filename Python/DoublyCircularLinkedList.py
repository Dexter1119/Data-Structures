########################################################################
#
# File Name   : DoublyCircularLinkedList.py
# Description : Menu-driven program for Doubly Circular Linked List
# Author      : Pradhumnya Changdev Kalsait
# Date        : 08/07/25
#
########################################################################

class node:
    ####################################################################
    #
    # Function Name : __init__
    # Description   : Constructor to initialize a node
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

class DoublyCLL:
    ####################################################################
    #
    # Function Name : __init__
    # Description   : Initializes empty doubly circular linked list
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def __init__(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    ####################################################################
    #
    # Function Name : InsertFirst
    # Description   : Inserts node at the beginning
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def InsertFirst(self,no)
    # Input Output  : (1 input, 0 output)
    #
    ####################################################################
    def InsertFirst(self,no):
        
        newn = node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

            self.first.prev = self.last
            self.last.next = self.first

        else:
            newn.next = self.first
            self.first = newn

            self.first.prev = self.last
            self.last.next = self.first

        self.iCount += 1

    ####################################################################
    #
    # Function Name : InsertLast
    # Description   : Inserts node at the end
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def InsertLast(self,no)
    # Input Output  : (1 input, 0 output)
    #
    ####################################################################
    def InsertLast(self,no):

        newn = node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

            self.first.prev = self.last
            self.last.next = self.first

        else:
            newn.prev = self.last
            self.last.next = newn

            self.last = newn

            self.first.prev = self.last
            self.last.next = self.first

        self.iCount += 1
    
    ####################################################################
    #
    # Function Name : DeleteFirst
    # Description   : Deletes first node
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def DeleteFirst(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def DeleteFirst(self):

        if(self.first == None and self.last == None):
            return
        
        elif(self.first == self.last):
            self.first = None
            self.last = None

        else:
            self.first = self.first.next
            self.first.prev = self.last
            self.last.next = self.first

        self.iCount -= 1

    ####################################################################
    #
    # Function Name : DeleteLast
    # Description   : Deletes last node
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def DeleteLast(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def DeleteLast(self):

        if(self.first == None and self.last == None):
            return
        
        elif(self.first == self.last):
            self.first = None
            self.last = None

        else:
            self.last = self.last.prev
            self.first.prev = self.last
            self.last.next = self.first

        self.iCount -= 1

    ####################################################################
    #
    # Function Name : Display
    # Description   : Displays the contents of the list
    # Author        : Pradhumnya Changdev Kalsait
    # Date          : 08/07/25
    # Prototype     : def Display(self)
    # Input Output  : (0 input, 0 output)
    #
    ####################################################################
    def Display(self):
        temp = self.first

        if(temp == None):
            print("linked List is Empty")

        while 1:
            print(f"|{temp.data}|<=>", end="")
            temp = temp.next
            if (temp == self.first):
                break
            else:
                continue

        print("first")
    
    ####################################################################
    #
    # Function Name : Count
    # Description   : Returns number of nodes
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
    # Description   : Inserts node at a given position
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
    # Description   : Deletes node at a given position
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
            temp.next.prev = temp

            self.iCount -= 1
########################################################################

########################################################################
#
# Function Name : main
# Description   : Main function with menu to demonstrate Doubly CLL
# Author        : Pradhumnya Changdev Kalsait
# Date          : 08/07/25
# Prototype     : def main()
# Input Output  : (0 input, 0 output)
#
########################################################################

def main():
   dobj = DoublyCLL()
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

if(__name__ == "__main__"):
    main()
